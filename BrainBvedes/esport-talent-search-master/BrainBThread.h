#ifndef BrainBThread_H
#define BrainBThread_H

#include <QThread>
#include <QSize>
#include <QImage>
#include <QDebug>
#include <sstream>
#include <QPainter>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <functional>
#include <numeric>
#include <QDesktopWidget>
#include <QTimer>
class Hero;
typedef std::vector<Hero> Heroes;

class Hero
{

public:
    int x;
    int y;
    int color;
    int agility;
    int conds {0};
    double r = std::rand()%255;
    double g = std::rand()%255;
    double b = std::rand()%255;
    cv::Scalar cCenter { r, g, b };
    
    std::string name;

    Hero ( int x=0, int  y=0, int color=0, int agility=1,  std::string name ="Ifrit Entropy" ) :
        x ( x ), y ( y ), color ( color ), agility ( agility ), name ( name )
    {
    }
    ~Hero() {}

    void move ( int maxx, int maxy, int env ) {

        int newx = x+ ( ( ( double ) agility*1.0 ) * ( double ) ( std::rand() / ( RAND_MAX+1.0 ) )-agility/2 ) ;
        if ( newx-env > 0 && newx+env < maxx ) {
            x = newx;
        }
        int newy = y+ ( ( ( double ) agility*1.0 ) * ( double ) ( std::rand() / ( RAND_MAX+1.0 ) )-agility/2 );
        if ( newy-env > 0 && newy+env < maxy ) {
            y = newy;
        }

    }

    void randxy(int maxx, int maxy, int env)
    {
        QDesktopWidget dw;
        int newx = std::rand()%maxx;
        if ( newx-env > 0 && newx+env < maxx ) {
            x = newx;
        }
        int newy = std::rand()%maxy;
        if ( newy-env > 0 && newy+env < maxy ) {
            y = newy;
        }
    }

    void set_coord(int maxx,int maxy)
    {
        x=maxx;
        y=maxy;
    }


};

class BrainBThread : public QThread
{
    Q_OBJECT

    
    
    cv::Scalar cBg { 247, 223, 208 };
    cv::Scalar cBorderAndText { 47, 8, 4 };
    cv::Scalar cBoxes { 10, 235, 252 };
    
    Heroes heroes;
    int heroRectSize {40};

    cv::Mat prev {3*heroRectSize, 3*heroRectSize, CV_8UC3, cBg };
    int bps;
    long time {0};
    long endTime {10*60*10};
    int delay {100};

    bool paused {true};
    int nofPaused {0};

    std::vector<int> lostBPS;
    std::vector<int> foundBPS;

    int w;
    int h;
    int dispShift {40};
    

public:
    BrainBThread ( int w = 256, int h = 256 );
    ~BrainBThread();

    void run();
    void pause();
    void set_color();
    void set_color1();
    void set_paused ( bool p );
    
    int getDelay() const {

        return delay;

    }
    void setDelay ( int delay ) {

        if ( delay > 0 ) {
            delay = delay;
        }

    }

    void devel() {

        for ( Hero & hero : heroes ) {

            hero.move ( w, h, ( h<w ) ?h/10:w/10 );

        }

    }
    
    int nofHeroes () {

        return  heroes.size();

    }

    std::vector<int> &lostV () {

        return  lostBPS;

    }

    std::vector<int> &foundV () {

        return  foundBPS;

    }

    double meanLost () {

        return  mean ( lostBPS );

    }

    double varLost ( double mean ) {

        return  var ( lostBPS, mean );

    }

    double meanFound () {

        return  mean ( foundBPS );

    }

    double varFound ( double mean ) {

        return  var ( foundBPS, mean );

    }

    double mean ( std::vector<int> vect ) {

        double sum = std::accumulate ( vect.begin (), vect.end (), 0.0 );
        return  sum / vect.size();

    }

    double var ( std::vector<int> vect, double mean ) {

        double accum = 0.0;
        std::for_each ( vect.begin (), vect.end (), [&] ( const double d ) {
            accum += ( d - mean ) * ( d - mean );
        } );

        return sqrt ( accum / ( vect.size()-1 ) );
    }

    int get_bps() const {

        return bps;

    }

    int get_w() const {

        return w;

    }


    bool get_paused() const {

        return paused;

    }

    int get_nofPaused() const {

        return nofPaused;

    }

    void decComp() {

        lostBPS.push_back ( bps );

        if ( heroes.size() > 1 ) {
            heroes.pop_back();
        }

        for ( Hero & hero : heroes ) {
            if ( hero.agility >= 5 ) {
                hero.agility -= 2;
            }

        }

    }

    void incComp() {

        foundBPS.push_back ( bps );

        if ( heroes.size() > 300 ) {

            return;

        }

        /*
        Hero other ( w/2 + 200.0*std::rand() / ( RAND_MAX+1.0 )-100,
                     h/2 + 200.0*std::rand() / ( RAND_MAX+1.0 )-100,
                     255.0*std::rand() / ( RAND_MAX+1.0 ), 11, "New Entropy" );
                     */

	double rx = 200.0;
	if(heroes[0].x - 200 < 0)
	  rx = heroes[0].x;
	else if(heroes[0].x + 200 > w)
	  rx = w - heroes[0].x;
	
	double ry = 200.0;
	if(heroes[0].y - 200 < 0)
	  ry = heroes[0].y;
	else if(heroes[0].y + 200 > h)
	  ry = h - heroes[0].y;
	
        Hero other ( heroes[0].x + rx*std::rand() / ( RAND_MAX+1.0 )-rx/2,
                     heroes[0].y + ry*std::rand() / ( RAND_MAX+1.0 )-ry/2,
                     255.0*std::rand() / ( RAND_MAX+1.0 ), 11, "Clone Entropy" );
		
        heroes.push_back ( other );

        for ( Hero & hero : heroes ) {

            ++hero.conds;
            if ( hero.conds == 3 ) {
                hero.conds = 0;
                hero.agility += 2;
            }

        }

    }

    void draw () {

        cv::Mat src ( h+3*heroRectSize, w+3*heroRectSize, CV_8UC3, cBg );

        for ( Hero & hero : heroes ) {

            cv::Point x ( hero.x-heroRectSize+dispShift, hero.y-heroRectSize+dispShift );
            cv::Point y ( hero.x+heroRectSize+dispShift, hero.y+heroRectSize+dispShift );

            cv::rectangle ( src, x, y, cBorderAndText );

            cv::putText ( src, hero.name, x, cv::FONT_HERSHEY_SIMPLEX, .35, cBorderAndText, 1 );

            cv::Point xc ( hero.x+dispShift , hero.y+dispShift );
            
            cv::circle ( src, xc, 11, hero.cCenter, CV_FILLED, 8, 0 );

            cv::Mat box = src ( cv::Rect ( x, y ) );

            cv::Mat cbox ( 2*heroRectSize, 2*heroRectSize, CV_8UC3, cBoxes );
            box = cbox*.3 + box*.7;

        }

        cv::Mat comp;

        cv::Point focusx ( heroes[0].x- ( 3*heroRectSize ) /2+dispShift, heroes[0].y- ( 3*heroRectSize ) /2+dispShift );
        cv::Point focusy ( heroes[0].x+ ( 3*heroRectSize ) /2+dispShift, heroes[0].y+ ( 3*heroRectSize ) /2+dispShift );
        cv::Mat focus = src ( cv::Rect ( focusx, focusy ) );

        cv::compare ( prev, focus, comp, cv::CMP_NE );

        cv::Mat aRgb;
        cv::extractChannel ( comp, aRgb, 0 );

        bps = cv::countNonZero ( aRgb ) * 10;

        //qDebug()  << bps << " bits/sec";

        prev = focus;

        QImage dest ( src.data, src.cols, src.rows, src.step, QImage::Format_RGB888 );
        dest=dest.rgbSwapped();
        dest.bits();

        emit heroesChanged ( dest, heroes[0].x, heroes[0].y );

    }

    long getT() const {

        return time;

    }

    void finish () {

        time = endTime;

    }

   

signals:
    
    void heroesChanged ( const QImage &image, const int &x, const int &y );
    void endAndStats ( const int &t );
    void doStuff();
    void doStuff2();
public slots:
void updateCaption();
void set_color2();
void setxy(int x,int y);

};

#endif // BrainBThread_H

