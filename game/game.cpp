#include "game.h"
#include "ui_Game.h"


Game::Game(QWidget *parent)
    :
    QWidget(parent), ui(new Ui::Game)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    connect(ui->pushButton_start, &QPushButton::clicked, this, [this]()
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        setDefault();
        ui->pushButton_start->setEnabled(false);
    });
}

Game::~Game()
{
    delete ui;
}

bool Game::eventFilter(QObject *object, QEvent *event)
{
    if (isGameOver(board)){
        ui->pushButton_start->setEnabled(true);
    }
    if (event->type() == QEvent::MouseButtonRelease) {
        if (object == ui->label_1_cell) {
            if (board[0][0] == ' ') {
                setSignal(0, 0);

                move_raw = 0;
                move_col = 0;

                next();
            }
        }
        else if (object == ui->label_2_cell) {
            if (board[0][1] == ' ') {
                setSignal(0, 1);

                move_raw = 0;
                move_col = 1;

                next();
            }
        }
        else if (object == ui->label_3_cell) {
            if (board[0][2] == ' ') {
                setSignal(0, 2);

                move_raw = 0;
                move_col = 2;

                next();
            }
        }
        else if (object == ui->label_4_cell) {
            if (board[1][0] == ' ') {
                setSignal(1, 0);

                move_raw = 1;
                move_col = 0;

                next();
            }
        }
        else if (object == ui->label_5_cell) {
            if (board[1][1] == ' ') {
                setSignal(1, 1);

                move_raw = 1;
                move_col = 1;

                next();
            }
        }
        else if (object == ui->label_6_cell) {
            if (board[1][2] == ' ') {
                setSignal(1, 2);

                move_raw = 1;
                move_col = 2;

                next();
            }
        }
        else if (object == ui->label_7_cell) {
            if (board[2][0] == ' ') {
                setSignal(2, 0);

                move_raw = 2;
                move_col = 0;

                next();
            }
        }
        else if (object == ui->label_8_cell) {
            if (board[2][1] == ' ') {
                setSignal(2, 1);

                move_raw = 2;
                move_col = 1;

                next();
            }
        }
        else if (object == ui->label_9_cell) {
            if (board[2][2] == ' ') {
                setSignal(2, 2);

                move_raw = 2;
                move_col = 2;

                next();
            }
        }
    }

    return QObject::eventFilter(object, event);
}

void Game::setCircle(int raw, int col)
{
    if (raw == 0) {
        if (col == 0) {
            ui->label_1_cell->setStyleSheet(
                "border-bottom: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 1) {
            ui->label_2_cell->setStyleSheet(
                "border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 2) {
            ui->label_3_cell->setStyleSheet(
                "border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
        }
    }
    else if (raw == 1) {
        if (col == 0) {
            ui->label_4_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 1) {
            ui->label_5_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 2) {
            ui->label_6_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
        }
    }
    else if (raw == 2) {
        if (col == 0) {
            ui->label_7_cell->setStyleSheet(
                "border-top: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 1) {
            ui->label_8_cell->setStyleSheet(
                "border-top: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
        }
        else if (col == 2) {
            ui->label_9_cell->setStyleSheet(
                "border-top: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
        }
    }
}

void Game::setSignal(int raw, int col)
{
    if (raw == 0) {
        if (col == 0) {
            ui->label_1_cell->setStyleSheet(
                "border-bottom: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 1) {
            ui->label_2_cell->setStyleSheet(
                "border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 2) {
            ui->label_3_cell->setStyleSheet(
                "border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
        }
    }
    else if (raw == 1) {
        if (col == 0) {
            ui->label_4_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 1) {
            ui->label_5_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 2) {
            ui->label_6_cell->setStyleSheet(
                "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
        }
    }
    else if (raw == 2) {
        if (col == 0) {
            ui->label_7_cell->setStyleSheet(
                "border-top: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 1) {
            ui->label_8_cell->setStyleSheet(
                "border-top: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
        }
        else if (col == 2) {
            ui->label_9_cell->setStyleSheet(
                "border-top: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
        }
    }
}

bool Game::isGameOver(const char state[3][3])
{
    // Перевіряємо всі можливі варіанти перемоги та нічиєї

    // Перевірка рядків
    for (int i = 0; i < 3; i++) {
        if (state[i][0] != ' ' && state[i][0] == state[i][1] && state[i][0] == state[i][2]) {
            return true;
        }
    }

    // Перевірка стовпців
    for (int j = 0; j < 3; j++) {
        if (state[0][j] != ' ' && state[0][j] == state[1][j] && state[0][j] == state[2][j]) {
            return true;
        }
    }

    // Перевірка діагоналей
    if (state[0][0] != ' ' && state[0][0] == state[1][1] && state[0][0] == state[2][2]) {
        return true;
    }

    if (state[2][0] != ' ' && state[2][0] == state[1][1] && state[2][0] == state[0][2]) {
        return true;
    }

    // Перевірка нічиєї
    bool isTie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] == ' ') {
                isTie = false;
                break;
            }
        }
        if (!isTie) {
            break;
        }
    }

    return isTie;
}

void Game::buildTree(Node &node, char currentPlayer)
{
    if (isGameOver(node.state)) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (node.state[i][j] == ' ') {
                Node child;
                std::copy(&node.state[0][0], &node.state[0][0] + 9, &child.state[0][0]);
                child.state[i][j] = currentPlayer;

                char nextPlayer = (currentPlayer == 'X') ? 'O' : 'X';

                buildTree(child, nextPlayer);

                node.children.push_back(child);
            }
        }
    }
}

//void Game::printBoard(const char board[3][3])
//{
//    std::cout << "-------------" << std::endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            std::cout << "| " << board[i][j] << " ";
//        }
//        std::cout << "|" << std::endl;
//        std::cout << "-------------" << std::endl;
//    }
//}

void Game::makeMove(char board[3][3], char player)
{
    int row = move_raw, col = move_col;

    board[row][col] = player;
}

int Game::evaluate(const char board[3][3])
{
    // Перевірка рядків
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return (board[i][0] == 'X') ? -1 : 1;
        }
    }

    // Перевірка стовпців
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return (board[0][j] == 'X') ? -1 : 1;
        }
    }

    // Перевірка діагоналей
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return (board[0][0] == 'X') ? -1 : 1;
    }

    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        return (board[2][0] == 'X') ? -1 : 1;
    }

    // Нічия
    bool isTie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                isTie = false;
                break;
            }
        }
        if (!isTie) {
            break;
        }
    }

    if (isTie) {
        return 0;
    }

    return 0;  // Повертаємо 0, якщо стан гри невизначений
}

int Game::minimax(Node &node, bool isMaximizer)
{
    if (isGameOver(node.state)) {
        return evaluate(node.state);
    }

    if (isMaximizer) {
        int maxEval = std::numeric_limits<int>::min();
        for (Node &child: node.children) {
            int eval = minimax(child, false);
            maxEval = std::max(maxEval, eval);
        }
        return maxEval;
    }
    else {
        int minEval = std::numeric_limits<int>::max();
        for (Node &child: node.children) {
            int eval = minimax(child, true);
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
}

void Game::makeBotMove(char board[3][3])
{
    Node root;
    std::copy(&board[0][0], &board[0][0] + 9, &root.state[0][0]);
    buildTree(root, 'O');

    int maxEval = std::numeric_limits<int>::min();
    Node *bestMove = nullptr;

    for (Node &child: root.children) {
        int eval = minimax(child, false);
        if (eval > maxEval) {
            maxEval = eval;
            bestMove = &child;
        }
    }

    if (bestMove) {
        std::copy(&bestMove->state[0][0], &bestMove->state[0][0] + 9, &board[0][0]);
    }
}
void Game::next()
{
    if (!isGameOver(board)) {

        // Гравець робить хід
        makeMove(board, 'X');

        // Комп'ютер робить хід
        makeBotMove(board);
        printBoard(board);
    }
}

void Game::printBoard(const char (*board)[3])
{
    if (board[0][0] == 'O') {
        ui->label_1_cell->setStyleSheet(
            "border-bottom: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[0][1] == 'O') {
        ui->label_2_cell->setStyleSheet(
            "border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[0][2] == 'O') {
        ui->label_3_cell->setStyleSheet(
            "border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
    }
    if (board[1][0] == 'O') {
        ui->label_4_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[1][1] == 'O') {
        ui->label_5_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[1][2] == 'O') {
        ui->label_6_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
    }
    if (board[2][0] == 'O') {
        ui->label_7_cell->setStyleSheet(
            "border-top: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[2][1] == 'O') {
        ui->label_8_cell->setStyleSheet(
            "border-top: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/circle.png);");
    }
    if (board[2][2] == 'O') {
        ui->label_9_cell->setStyleSheet(
            "border-top: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/circle.png);");
    }


    // signals

    if (board[0][0] == 'X') {
        ui->label_1_cell->setStyleSheet(
            "border-bottom: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[0][1] == 'X') {
        ui->label_2_cell->setStyleSheet(
            "border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[0][2] == 'X') {
        ui->label_3_cell->setStyleSheet(
            "border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
    }
    if (board[1][0] == 'X') {
        ui->label_4_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[1][1] == 'X') {
        ui->label_5_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[1][2] == 'X') {
        ui->label_6_cell->setStyleSheet(
            "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
    }
    if (board[2][0] == 'X') {
        ui->label_7_cell->setStyleSheet(
            "border-top: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[2][1] == 'X') {
        ui->label_8_cell->setStyleSheet(
            "border-top: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black; image: url(:/images/signal.png);");
    }
    if (board[2][2] == 'X') {
        ui->label_9_cell->setStyleSheet(
            "border-top: 3px solid white;border-left: 3px solid white;background-color: black; image: url(:/images/signal.png);");
    }
}

void Game::setDefault()
{
    ui->label_1_cell->setStyleSheet(
        "border-bottom: 3px solid white; border-right: 3px solid white; background-color: black;");
    ui->label_2_cell->setStyleSheet(
        "border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black;");
    ui->label_3_cell->setStyleSheet(
        "border-bottom: 3px solid white;border-left: 3px solid white;background-color: black;");
    ui->label_4_cell->setStyleSheet(
        "border-top: 3px solid white; border-bottom: 3px solid white;border-right: 3px solid white; background-color: black;");
    ui->label_5_cell->setStyleSheet(
        "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black;");
    ui->label_6_cell->setStyleSheet(
        "border-top: 3px solid white; border-bottom: 3px solid white;border-left: 3px solid white;background-color: black;");
    ui->label_7_cell->setStyleSheet(
        "border-top: 3px solid white; border-right: 3px solid white; background-color: black;");
    ui->label_8_cell->setStyleSheet(
        "border-top: 3px solid white;border-left: 3px solid white; border-right: 3px solid white; background-color: black;");
    ui->label_9_cell->setStyleSheet(
        "border-top: 3px solid white;border-left: 3px solid white;background-color: black;");
}
