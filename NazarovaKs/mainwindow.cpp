#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include "field.h"
#include "check.h"
#include "row.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    firstClick = true;
    startX=startY=finishX=finishY=0;
    myVar=0;

}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    int x=30, y=45;
     for(int i=myVar; i<f.field.size(); i++){
        for(int j=0; j<maxColumns; j++){
            QRect sq(x, y, 30, 30);
            QPainter pict;
            pict.begin(this);
            pict.setRenderHint(QPainter::Antialiasing, true);
            pict.setBrush(QBrush(Qt::lightGray));
            pict.setPen(QPen(Qt::black));
            pict.drawRoundedRect(sq, 1, 1);
            pict.end();

            QPainter text;
            text.begin(this);
            text.setRenderHint(QPainter::Antialiasing, true);
            if (f.field[i].getStateIsPressed(j)==true) text.setPen(QPen(Qt::cyan, 3, Qt::DashLine));
            if (f.field[i].getData(j)==0) text.drawText(sq, " ", QTextOption(Qt::AlignCenter));
            else text.drawText(sq, QString::number(f.field[i].getData(j)), QTextOption(Qt::AlignCenter));
            text.end();
            x=x+30;

            f.deleteEmptyRow();
            f.field[i].setStateIsPressed(j, false);
        }
        x=30;
        y=y+30;
    }
//     int rowsDisplayed = (height() - 45)/30;
//     if (rowsDisplayed <= f.field.size() )
//         ui->verticalScrollBar->setMaximum(0);
//     else
//         ui->verticalScrollBar->setMaximum(f.field.size() - rowsDisplayed);

}

void MainWindow::on_actionNew_game_activated(){
    if (QMessageBox::question(this, "Question", "Open a new game?",QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes){
        Field field(5);
        f=field;
        repaint();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button()==Qt::LeftButton) leftButtonPressEvent(event);
}

void MainWindow::leftButtonPressEvent(QMouseEvent *event){
    if(firstClick){
        QPoint p;
        p=event->pos();
        startX=((p.ry()-45)/30)+1+myVar;
        startY=((p.rx()-30)/30)+1;
        f.field[startX-1].setStateIsPressed(startY-1, true);
        firstClick=false;
    }
    else {
        QPoint p;
        p=event->pos();
        finishX=((p.ry()-45)/30)+1+myVar;
        finishY=((p.rx()-30)/30)+1;
        f.field[finishX-1].setStateIsPressed(finishY-1, true);
        f.deleteCell(startX,startY,finishX,finishY);
        firstClick = true;
    }
    repaint();
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (QMessageBox::question(this, "Question", "Save game?",QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes) {
        f.saveGame();
        emit exit(1);
    }
    else emit exit(1);
}

bool MainWindow::outLoss(){
    Check check(f);
    if (check.getLoss()==true){
        if (QMessageBox::question(this, "You lose!!!", "Open a new game?",QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes){
            Field field;
            f=field;
            repaint();
        }        
        else exit(1);
        return true;
    }
    else return false;
}

bool MainWindow::outWin(){
    Check check(f);
    if (check.getWin()==true){
        if (QMessageBox::question(this, "You win!!!", "Open a new game?",QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes){
            Field field;
            f=field;
            repaint();
        }
        else exit(1);
        return true;
    }
    else return false;
}

void MainWindow::on_pushButton_clicked(){
    if (outLoss()==0 && outWin()==0) emit f.addCells();
    repaint();
}

void MainWindow::on_actionExit_activated(){
    if (QMessageBox::question(this, "Question", "Save game?",QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes) {
        f.saveGame();
        emit exit(1);
    }
    else emit exit(1);
}

void MainWindow::on_verticalScrollBar_valueChanged(int value){
    myVar=value;
    repaint();
}

void MainWindow::on_actionContinued_activated(){
    f.getState(true);
    f.loadGame();
    repaint();
}
