//
// Created by 1 on 01.06.2023.
//

#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QEvent>

#include <vector>
#include <algorithm>

struct Node {
    std::vector<Node> children;
    char state[3][3];

    Node() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                state[i][j] = ' ';
            }
        }
    }
};

QT_BEGIN_NAMESPACE
namespace Ui
{
class Game;
}
QT_END_NAMESPACE

class Game: public QWidget
{
Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game() override;

    bool eventFilter(QObject *object, QEvent *event) override ;
    void setCircle(int raw, int col);
    void setSignal(int raw, int col);
    void setDefault();

    bool isGameOver(const char state[3][3]);
    void buildTree(Node& node, char currentPlayer);
    void printBoard(const char board[3][3]);
    void makeMove(char board[3][3], char player);
    int evaluate(const char board[3][3]);
    int minimax(Node& node, bool isMaximizer);
    void makeBotMove(char board[3][3]);

    void next();



private:
    Ui::Game *ui;
    char board[3][3];
    bool moveDone = false;
    int move_raw, move_col;
    bool first_call = true;

};


#endif //GAME_H
