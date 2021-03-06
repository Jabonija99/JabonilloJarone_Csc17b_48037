#include "game.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game(QWidget *parent)
{
    //Create a scene
    scene = new QGraphicsScene();
    //Set scene size to (800, 600)
    scene->setSceneRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT);
    setBackgroundBrush(QBrush(QImage(":/images/dep/background.png")));


    setScene(scene);
    //Disable scrollbar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    //Create an item to put into the scene
    player = new Rect();
    //Set rectangle size (xpos, ypos, width, height)
    //player->setRect(0,0,100,100);
    //Set player coordinates(middle of the screen, bottom - player height)
    player->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - 100);
    //Enable item focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    //Sets item focus
    player->setFocus();
    //Set item on scene
    scene->addItem(player);

    //Create score
    score = new Score();
    scene->addItem(score);

    hp = new Health();
    hp->setPos(hp->x(), hp->y()+25);
    scene->addItem(hp);


    //Spawns enemies
    QTimer *timer = new QTimer();
    //Player object not preferred place to put it
    QObject::connect(timer,SIGNAL(timeout()),
                     player, SLOT(spawn()));
    timer->start(2000);

    //Play background music
    QMediaPlayer *music = new QMediaPlayer();
    //Set sound file
    //*Uses QUrl to access all files
    music->setMedia(QUrl("qrc:/sounds/dep/bgmusic.mp3"));
    //Play music
    music->play();

    show();
}
