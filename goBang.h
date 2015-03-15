#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QList>
#include <QGridLayout>
#include <QMessageBox>

class QAction;
class QMenu;
class Chess;
class goBang : public QWidget {
        Q_OBJECT
    public:
        goBang (QWidget * parent = 0);
        void think ();
        QList<int> get_list_left_right (int chess , int x , int y);
        QList<int> get_list_up_down (int chess , int x , int y);
        QList<int> get_list_down_ward (int chess , int x , int y);
        QList<int> get_list_up_ward(int chess,int x,int y);
        int get_total_score(int chess , QList<int> list);
        int count_score(int chess , QString list_str);
        void judge();
    public slots:
        void drapRedChess ();
        void drapBlackChess (int x , int y);
        void restart();
    private:
        Chess * chesses[20][20];
        QGridLayout * mainLayout;
        QMessageBox * victoryMessage;
        int values[20][20];
        int index;
};
#endif