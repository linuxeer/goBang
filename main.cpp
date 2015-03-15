#include <QApplication>
#include "goBang.h"
#include "chess.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	goBang gobang;
	gobang.move(200,200);
	gobang.show();
	return app.exec();
}