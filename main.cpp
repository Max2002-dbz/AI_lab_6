#include <QApplication>
#include <QPushButton>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;
    game.show();

    return QApplication::exec();
}
