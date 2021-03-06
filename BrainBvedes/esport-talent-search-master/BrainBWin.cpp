

#include "BrainBWin.h"
#include <QMessageBox>
const QString BrainBWin::appName = "NEMESPOR BrainB Test";
const QString BrainBWin::appVersion = "6.0.3";

BrainBWin::BrainBWin ( int w, int h, QWidget *parent ) : QMainWindow ( parent )
{

        statDir = appName + " " + appVersion + " - " + QDate::currentDate().toString() + QString::number ( QDateTime::currentMSecsSinceEpoch() );

        brainBThread = new BrainBThread ( w, h - yshift );
        brainBThread->start();

        connect ( brainBThread, SIGNAL ( heroesChanged ( QImage, int, int ) ),
                  this, SLOT ( updateHeroes ( QImage, int, int ) ) );
        connect ( brainBThread, SIGNAL ( endAndStats ( int ) ),
                  this, SLOT ( endAndStats ( int ) ) );
        
        
        connect(timer, &QTimer::timeout,[=](  ) { brainBThread->doStuff2(); });
        connect(brainBThread,SIGNAL(doStuff2()),this, SLOT(ugrik()));
        
        

}

void BrainBWin::ugrik()
{
    brainBThread->updateCaption();
}

void BrainBWin::endAndStats ( const int &t )
{

        qDebug()  << "\n\n\n";
        qDebug()  << "Thank you for using " + appName;
        qDebug()  << "The result can be found in the directory " + statDir;
        qDebug()  << "\n\n\n";

        save ( t );
        close();
}
void BrainBWin::updateHeroes ( const QImage &image, const int &x, const int &y )
{

        if ( start && !brainBThread->get_paused() ) {

                int dist = ( this->mouse_x - x ) * ( this->mouse_x - x ) + ( this->mouse_y - y ) * ( this->mouse_y - y );

                if ( dist > 121 ) {
                        
                        ++nofLost;
                        nofFound = 0;
                        if ( nofLost > 12 ) {

                                if ( state == found && firstLost ) {
                                        found2lost.push_back ( brainBThread->get_bps() );
                                }

                                firstLost = true;

                                state = lost;
                                nofLost = 0;
                                //qDebug() << "LOST";
                                //double mean = brainBThread->meanLost();
                                //qDebug() << mean;

                                brainBThread->decComp();
                        }
                } else {
                        if(kapcsolo==false){
                        timer->setInterval(500);
                        timer->start();
                        }
                        ++nofFound;
                        nofLost = 0;
                        if ( nofFound > 12 ) {

                                if ( state == lost && firstLost ) {
                                        lost2found.push_back ( brainBThread->get_bps() );
                                }

                                state = found;
                                nofFound = 0;
                                //qDebug() << "FOUND";
                                //double mean = brainBThread->meanFound();
                                //qDebug() << mean;

                                brainBThread->incComp();
                        }

                }

        }
        pixmap = QPixmap::fromImage ( image );
        update();
}

void BrainBWin::paintEvent ( QPaintEvent * )
{
        if ( pixmap.isNull() ) {
                return;
        }

        QPainter qpainter ( this );

        xs = ( qpainter.device()->width() - pixmap.width() ) /2;
        ys = ( qpainter.device()->height() - pixmap.height() +yshift ) /2;

        qpainter.drawPixmap ( xs, ys, pixmap );

        qpainter.drawText ( 10, 20, "Press and hold the mouse button on the center of Samu Entropy" );

        int time = brainBThread->getT();
        int min, sec;
        millis2minsec ( time, min, sec );
        QString timestr = QString::number ( min ) + ":" + QString::number ( sec ) + "/10:0";
        qpainter.drawText ( 10, 40, timestr );

        int bps = brainBThread->get_bps();
        QString bpsstr = QString::number ( bps ) + " bps";
        qpainter.drawText ( 110, 40, bpsstr );
        if ( brainBThread->get_paused() ) {
                QString pausedstr = "PAUSED (" + QString::number ( brainBThread->get_nofPaused() ) + ")";

                qpainter.drawText ( 210, 40, pausedstr );
        }
        QString help="Segítségek száma:"+QString::number(counter);
        qpainter.drawText(400,40,help);

        qpainter.end();
}

void BrainBWin::mousePressEvent ( QMouseEvent *event )
{

        brainBThread->set_paused ( false );
        if(event->button() == Qt::RightButton)
        {
            if (kapcsolo==true)
            {
                counter++;
                timer->stop();
                timer->setInterval(1000);
                timer->start();
                brainBThread->setxy(mouse_x,mouse_y);
            }
        }

}

void BrainBWin::mouseReleaseEvent ( QMouseEvent *event )
{

        //brainBThread->set_paused(true);

}

void BrainBWin::mouseMoveEvent ( QMouseEvent *event )
{

        start = true;

        mouse_x = event->pos().x() -xs - 60;
        //mouse_y = event->pos().y() - yshift - 60;
        mouse_y = event->pos().y() - ys - 60;
}

void BrainBWin::keyPressEvent ( QKeyEvent *event )
{

        if ( event->key() == Qt::Key_S ) {
                save ( brainBThread->getT() );
        } else if ( event->key() == Qt::Key_P ) {
                brainBThread->pause();
                takepicture(brainBThread->getT());
        } else if ( event->key() == Qt::Key_Q ||  event->key() == Qt::Key_Escape ) {
                
                QMessageBox msgBox;
                msgBox.setText("Kilépés");
                msgBox.setInformativeText("Biztosan kiakar lépni?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
                msgBox.setDefaultButton(QMessageBox::Yes);
                int ret = msgBox.exec();
                switch (ret) {
                case QMessageBox::Yes:
                close();
                break;
                case QMessageBox::Cancel:
                // Cancel was clicked
                break;
                default:
                // should never be reached
                break;
        }
        }
        else if(event->key() == Qt::Key_Space){
            brainBThread->set_color();
            brainBThread->doStuff();
        }
        else if (event->key() == Qt::Key_X)
        {
            if (kapcsolo!=true)
            {
                kapcsolo=true;
            }
            else
            {
                kapcsolo=false;
            }
            takepicture(brainBThread->getT());
        }


}

BrainBWin::~BrainBWin()
{

}
