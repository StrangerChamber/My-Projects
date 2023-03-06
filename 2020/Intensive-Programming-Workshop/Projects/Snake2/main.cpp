#include <QApplication>
#include "Gameview.h"

/*
Jack Blackburn
CSCI 3010

This is my version of Snake, the classic game from a few decades ago. It follows the same basic rules as the original
except that food appears and a set interval instead of each time the one on the board is eaten. My version also includes
enemies that when hit cause your snake to lose a link. If you lose all your links except for the head you lose and to win
you need to accumulate 25 links. In my version you can hit the walls and not lose because of how fast the snake moves.

I wasn't able to get as much done as I wanted to from this game. I wanted to implement special powerups that either speed
up the snake or slow it down based on whatever collision occurs. I also struggled getting the borders of the board to work
correctly (two sides act like walls and the other two send you through to the opposite side). The game isn't multiplayer nor
does it meet all of the technical requirements but the game is functional and I definetely learned a lot more about QT through
the building process.

Overall, I built a game and am proud of what I was able to get done even though it didn't satisfy all the given requirements

*/

GameView* game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new GameView();
    game->show();
    return app.exec();
}
