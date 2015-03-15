#ifndef CHESS_H
#define CHESS_H
#include <QPushButton>

class Chess : public QPushButton {
        Q_OBJECT
    public:
        Chess (int , int , QWidget *);
        void remove ();
        void drawRed ();
        void drawBlack ();
        int x;
        int y;
};
#endif