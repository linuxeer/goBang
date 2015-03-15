#include <QtWidgets>
#include <QDebug>
#include <QList>
#include <QPushButton>
#include <QMessageBox>
#include "goBang.h"
#include "chess.h"

goBang::goBang(QWidget * parent) : QWidget(parent) {
        mainLayout = new QGridLayout;
        for (int i = 0 ; i < 20 ; i++) {
                for (int j = 0 ; j < 20 ; j++) {
                        Chess * ch = new Chess(i , j , 0);
                        chesses[i][j] = ch;
                        values[i][j] = 0;
                        connect(ch , & QPushButton::clicked , this , & goBang::drapRedChess);
                        ch->setFixedSize(QSize(30 , 30));
                        mainLayout->addWidget(ch , i , j);
                }
        }
        QPushButton * restart = new QPushButton("restart");
        QObject::connect(restart , & QPushButton::clicked , this , & goBang::restart);
        mainLayout->addWidget(restart , 0 , 20);
        setLayout(mainLayout);
}
// 红方为人
void goBang::drapRedChess () {
        Chess * ch = qobject_cast<Chess *>(sender());
        int x = ch->x;
        int y = ch->y;
        if (values[x][y] != 0)
                return;
        ch->drawRed();
        values[x][y] = 1;
        think();
        judge();
}
// 黑方为计算机
void goBang::drapBlackChess (int x , int y) {
        Chess * ch = chesses[x][y];
        ch->drawBlack();
        values[x][y] = -1;
        judge();
}
void goBang::think () {
        int best_x = 0;
        int best_y = 0;
        int best_score = 0;
        //  遍历每一步棋
        for (int x = 0 ; x < 20 ; x++) {
                for (int y = 0 ; y < 20 ; y++) {
                        if (values[x][y] != 0)
                                continue;
                        QList<int> left_right_red = get_list_left_right(1 , x , y);
                        QList<int> left_right_black = get_list_left_right(-1 , x , y);
                        QList<int> up_down_red = get_list_up_down(1 , x , y);
                        QList<int> up_down_black = get_list_up_down(-1 , x , y);
                        QList<int> down_ward_red = get_list_down_ward(1 , x , y);
                        QList<int> down_ward_black = get_list_down_ward(-1 , x , y);
                        QList<int> up_ward_red = get_list_up_ward(1 , x , y);
                        QList<int> up_ward_black = get_list_up_ward(-1 , x , y);
                        // 计算两种棋的四条线的分数
                        int score_0 = get_total_score(1 , left_right_red);
                        int score_1 = get_total_score(-1 , left_right_black);
                        int score_2 = get_total_score(1 , up_down_red);
                        int score_3 = get_total_score(-1 , up_down_black);
                        int score_4 = get_total_score(1 , down_ward_red);
                        int score_5 = get_total_score(-1 , down_ward_black);
                        int score_6 = get_total_score(1 , up_ward_red);
                        int score_7 = get_total_score(-1 , up_ward_black);
                        QList<int> scores;
                        scores << score_0 << score_1 << score_2 << score_3 << score_4 << score_5 << score_6 << score_7;
                        QList<int>::iterator iter;
                        for (iter = scores.begin() ; iter != scores.end() ; ++iter) {
                                if (* iter > best_score) {
                                        best_score = * iter;
                                        best_x = x;
                                        best_y = y;
                                }
                        }
                }
        }
        drapBlackChess(best_x , best_y);
}
void goBang::judge () {
        QList<int> list0 = QList<int>() << 1 << 1 << 1 << 1 << 1;
        QList<int> list1 = QList<int>() << -1 << -1 << -1 << -1 << -1;
        for (int i = 0 ; i < 20 ; i++) {
                for (int j = 0 ; j < 20 ; j++) {
                        if (values[i][j] == 0)
                                continue;
                        QList<int> list;
                        // 横向检测是否有一方胜利
                        list << values[i][j];
                        if (j + 1 < 20 || j + 2 < 20 || j - 1 >= 0 || j - 2 >= 0) {
                                list.prepend(values[i][j - 1]);
                                list.prepend(values[i][j - 2]);
                                list.append(values[i][j + 1]);
                                list.append(values[i][j + 2]);
                                if (list == list0) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "红方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                } else if (list == list1) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "黑方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                }
                        }
                        list.clear();
                        // 纵向检测是否有一方胜利
                        list << values[i][j];
                        if (i - 2 >= 0 || i - 1 >= 0 || i + 1 < 20 || i + 2 < 20) {
                                list.prepend(values[i - 2][j]);
                                list.prepend(values[i - 1][j]);
                                list.append(values[i + 1][j]);
                                list.append(values[i + 2][j]);
                                if (list == list0) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "红方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                } else if (list == list1) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "黑方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                }
                        }
                        list.clear();
                        // 左上右下检测是否有一方胜利
                        list << values[i][j];
                        if (i - 2 >= 0 || i - 1 >= 0 || j - 2 >= 0 || j - 1 >= 0 || i + 1 < 20 || i + 2 < 20 || j + 1 < 20 || j + 2 < 20) {
                                list.prepend(values[i - 2][j - 2]);
                                list.prepend(values[i - 1][j - 1]);
                                list.append(values[i + 1][j + 1]);
                                list.append(values[i + 2][j + 2]);
                                if (list == list0) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "红方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                } else if (list == list1) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "黑方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                }
                        }
                        list.clear();
                        // 右上左下检测是否有一方胜利
                        list << values[i][j];
                        if (i - 2 >= 0 || i - 1 >= 0 || j + 2 < 20 || j + 1 < 20 || i + 1 < 20 || i + 2 < 20 || j - 1 >= 0 || j - 2 >= 0) {
                                list.prepend(values[i - 2][j + 2]);
                                list.prepend(values[i - 1][j + 1]);
                                list.append(values[i + 1][j - 1]);
                                list.append(values[i + 2][j - 2]);
                                if (list == list0) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "红方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                } else if (list == list1) {
                                        int ret = QMessageBox::question(this , "对弈结果" , "黑方胜利!想要再来一盘吗?" , QMessageBox::Yes , QMessageBox::No);
                                        if (ret == QMessageBox::Yes) {
                                                restart();
                                        }
                                }
                        }
                }
        }
}
QList<int> goBang::get_list_left_right (int chess , int x , int y) {
        QList<int> list;
        list << chess;
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x][y - step] == chess * -1 || y - step < 0) {
                        break;
                }
                list.prepend(values[x][y - step]);
        }
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x][y + step] == chess * -1 || y + step >= 20) {
                        break;
                }
                list.append(values[x][y + step]);
        }
        return list;
}
QList<int>  goBang::get_list_up_down (int chess , int x , int y) {
        QList<int> list;
        list << chess;
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x - step][y] == chess * -1 || x - step < 0) {
                        break;
                }
                list.prepend(values[x - step][y]);
        }
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x + step][y] == chess * -1 || x + step >= 20) {
                        break;
                }
                list.append(values[x + step][y]);
        }
        return list;
}
QList<int> goBang::get_list_down_ward (int chess , int x , int y) {
        QList<int> list;
        list << chess;
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x - step][y - step] == chess * -1 || x - step < 0 || y - step < 0) {
                        break;
                }
                list.prepend(values[x - step][y - step]);
        }
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x + step][y + step] == chess * -1 || x + step >= 20 || y + step > 20) {
                        break;
                }
                list.append(values[x + step][y + step]);
        }
        return list;
}
QList<int> goBang::get_list_up_ward (int chess , int x , int y) {
        QList<int> list;
        list << chess;
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x - step][y + step] == chess * -1 || x - step < 0 || y + step >= 20) {
                        break;
                }
                list.prepend(values[x - step][y + step]);
        }
        for (int step = 1 ; step < 5 ; step++) {
                if (values[x + step][y - step] == chess * -1 || x + step >= 20 || y - step < 0) {
                        break;
                }
                list.append(values[x + step][y - step]);
        }
        return list;
}
int goBang::get_total_score (int chess , QList<int> list) {
        int total_score = 0;
        static int turn = -1;
        turn++;
        if (list.size() < 5) {
                return 0;
        }
        for (int start = 0 ; start < list.size() - 4 ; start++) {
                QList<int> sub_list = list.mid(start , 5);
                QString sub_list_str = "";
                QList<int>::iterator iter;
                for (iter = sub_list.begin() ; iter != sub_list.end() ; ++iter) {
                        if (* iter == -1) {
                                * iter = 1;
                        }
                        sub_list_str += QString::number(* iter);
                }
                int score = count_score(chess , sub_list_str);
                total_score += score;
        }
        return total_score;
}
int goBang::count_score (int chess , QString list_str) {
        int score = 0;
        if (list_str == "10000" || list_str == "01000" || list_str == "00100" || list_str == "00010" || list_str == "00001") {
                score = 1;
        } else if (list_str == "11000") {
                score = 10;
        } else if (list_str == "10100") {
                score = 9;
        } else if (list_str == "10010") {
                score = 8;
        } else if (list_str == "10001") {
                score = 7;
        } else if (list_str == "01100") {
                score = 10;
        } else if (list_str == "01010") {
                score = 9;
        } else if (list_str == "01001") {
                score = 9;
        } else if (list_str == "00110") {
                score = 10;
        } else if (list_str == "00101") {
                score = 9;
        } else if (list_str == "00011") {
                score = 10;
        } else if (list_str == "11100") {
                score = 100;
        } else if (list_str == "11010") {
                score = 90;
        } else if (list_str == "11001") {
                score = 80;
        } else if (list_str == "10110") {
                score = 90;
        } else if (list_str == "10101") {
                score = 75;
        } else if (list_str == "10011") {
                score = 80;
        } else if (list_str == "01110") {
                score = 105;
        } else if (list_str == "01101") {
                score = 90;
        } else if (list_str == "01011") {
                score = 90;
        } else if (list_str == "11001") {
                score = 80;
        } else if (list_str == "11110") {
                score = 3000;
        } else if (list_str == "11101") {
                score = 2000;
        } else if (list_str == "11011") {
                score = 2000;
        } else if (list_str == "10111") {
                score = 2000;
        } else if (list_str == "01111") {
                score = 3000;
        } else if (list_str == "11111") {
                if (chess == 1) {
                        score = 100000;
                } else if (chess == -1) {
                        score = 50000;
                }
        }
        return score;
}
void goBang::restart () {
        for (int i = 0 ; i < 20 ; i++) {
                for (int j = 0 ; j < 20 ; j++) {
                        chesses[i][j]->hide();
                        Chess * ch = new Chess(i , j , 0);
                        chesses[i][j] = ch;
                        values[i][j] = 0;
                        connect(ch , & QPushButton::clicked , this , & goBang::drapRedChess);
                        ch->setFixedSize(QSize(30 , 30));
                        mainLayout->addWidget(ch , i , j);
                        ch->show();
                }
        }
}