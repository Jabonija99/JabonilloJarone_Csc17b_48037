/* Topics
 * #06
 * Parents
 * QGraphicsTextItem //Text on scene
 * **setPlainText()
 * **setFont()
 * **setDefaultTextColor()
 *
 * #07
 * Resourcefiles
 * QMediaPlayer
 * **setMedia()
 * QUrl
 * **play()
 * Including multimedia within .pro
 *
 * #08
 * Libraries for images:
 * QGraphicsPixmapItem
 * QPixmap
 * QImage
 * Edits all QGraphicsRectItems with pixmap
*/


#include <QApplication>
#include "game.h"

Game *GAME;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GAME = new Game();
    GAME->show();


    return a.exec();
}
