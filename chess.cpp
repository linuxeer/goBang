#include <QtWidgets>
#include "chess.h"

Chess::Chess (int x_ , int y_ , QWidget * parent) : QPushButton(parent) {
        x = x_;
        y = y_;
}
void Chess::drawRed () {
        QIcon icon = QIcon("red.png");
        this->setIcon(icon);
}
void Chess::drawBlack () {
        QIcon icon = QIcon("black.png");
        this->setIcon(icon);
}