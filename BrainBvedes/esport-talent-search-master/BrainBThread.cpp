
#include "BrainBThread.h"
#include <cstdlib>
#include <ctime>

BrainBThread::BrainBThread ( int w, int h )
{

        dispShift = heroRectSize+heroRectSize/2;

        this->w = w - 3 * heroRectSize;
        this->h = h - 3 * heroRectSize;

        std::srand ( std::time ( 0 ) );

        Hero me ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                  this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 9 );

        Hero other1 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 5, "NemesisR Entropy" );
        Hero other2 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 3, "Shuvian Entropy" );
        Hero other4 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 5, "RaptorX Entropy" );
        Hero other5 ( this->w / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100,
                      this->h / 2 + 200.0 * std::rand() / ( RAND_MAX + 1.0 ) - 100, 255.0 * std::rand() / ( RAND_MAX + 1.0 ), 7, "ZooM Entropy" );
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout,[=](  ) { this->doStuff(); });
        connect(this,SIGNAL(doStuff()),this, SLOT(set_color2()));
        timer->setInterval(500);
        timer->start();
        heroes.push_back ( me );
        heroes.push_back ( other1 );
        heroes.push_back ( other2 );
        heroes.push_back ( other4 );
        heroes.push_back ( other5 );

}

BrainBThread::~BrainBThread()
{

}

void BrainBThread::run()
{
        
        while ( time < endTime ) {

                QThread::msleep ( delay );
                
                if ( !paused ) {
                        ++time;
                        devel();

                }

                draw();

        }

        emit endAndStats ( endTime );

}

void BrainBThread::pause()
{

        paused = !paused;
        if ( paused ) {
                ++nofPaused;
        }

}
void BrainBThread::updateCaption(){
    for ( Hero & hero : heroes ){
        QDesktopWidget dw;
        if(hero.name=="Ifrit Entropy"){
            hero.randxy(dw.width(), dw.height(), ( h<w ) ?h/2:w/2);
        }
    }

}
void BrainBThread::setxy(int x,int y)
{
    for ( Hero & hero : heroes ){
        if(hero.name=="Ifrit Entropy"){
            hero.set_coord(x,y);
        }
    }
    
}
void BrainBThread::set_paused ( bool p )
{

        if ( !paused && p ) {
                ++nofPaused;
        }

        paused = p;

}

void BrainBThread::set_color()
{
	

        for ( Hero & hero : heroes ) {
            if(hero.name=="Ifrit Entropy"){
            double r=std::rand()%255;
		    double g=std::rand()%255;
		    double b=std::rand()%255;
		    cv::Scalar newCenter { r, g, b };
		    hero.cCenter=newCenter;
            }
        }
    
}
void BrainBThread::set_color2()
{
    

        for ( Hero & hero : heroes ) {
            if(hero.name=="Ifrit Entropy"){
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar newCenter { r, g, b };
            hero.cCenter=newCenter;
            }
        }
    
}

void BrainBThread::set_color1()
{
        for ( Hero & hero : heroes ) {
            double r=std::rand()%255;
            double g=std::rand()%255;
            double b=std::rand()%255;
            cv::Scalar newCenter { r, g, b };
            hero.cCenter=newCenter;
        }

}

