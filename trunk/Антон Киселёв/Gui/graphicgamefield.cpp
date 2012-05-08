#include "graphicgamefield.h"
#include "ui_graphicgamefield.h"
#include "savegamedialog.h"
#include <QPainter>
#include "field.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
graphicgamefield::graphicgamefield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphicgamefield)
{
    ui->setupUi(this);
    GameField = new Field(1);
    GameField->Fill_Zero(1);

    Create_Button_1();
    Create_Button_2();
    Create_Button_3();
    Create_Button_4();
    Create_Button_5();
    Create_Button_6();
    Create_Button_7();
    Create_Button_8();
    Create_Button_9();
    Create_Button_10();
    Create_Button_11();
    Create_Button_11();
    Create_Button_12();
    Create_Button_13();
    Create_Button_14();
    Create_Button_15();
    Create_Button_16();
    Create_Button_17();
    Create_Button_18();
    Create_Button_19();
    Create_Button_20();
    Create_Button_21();
    Create_Button_22();
    Create_Button_23();
    Create_Button_24();
    Create_Button_25();
    Create_Button_26();
    Create_Button_27();
    Create_Button_28();
    Create_Button_29();
    Create_Button_30();
    Create_Button_31();
    Create_Button_32();
    Create_Button_33();
    Create_Button_34();
    Create_Button_35();
    Create_Button_36();
    Create_Button_37();
    Create_Button_38();
    Create_Button_39();
    Create_Button_40();
    Create_Button_41();
    Create_Button_42();
    Create_Button_43();
    Create_Button_44();
    Create_Button_45();
    Create_Button_46();
    Create_Button_47();
    Create_Button_48();
    Create_Button_49();
    Create_Button_50();
    Create_Button_51();
    Create_Button_52();
    Create_Button_53();
    Create_Button_54();
    Create_Button_55();
    Create_Button_56();
    Create_Button_57();
    Create_Button_58();
    Create_Button_59();
    Create_Button_60();
    Create_Button_61();
    Create_Button_62();
    Create_Button_63();
    Create_Button_64();
    Create_Button_65();
    Create_Button_66();
    Create_Button_67();
    Create_Button_68();
    Create_Button_69();
    Create_Button_70();
    Create_Button_71();
    Create_Button_72();
    Create_Button_73();
    Create_Button_74();
    Create_Button_75();
    Create_Button_76();
    Create_Button_77();
    Create_Button_78();
    Create_Button_79();
    Create_Button_80();
    Create_Button_81();

    QObject::connect(ui->CheckButton,SIGNAL(clicked()),this,SLOT(on_CheckButton_clicked()));
    QObject::connect(ui->SaveButton,SIGNAL(clicked()),this,SLOT(on_SaveButton_clicked()));

    QObject::connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_pushButton_1_clicked()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
    QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_3_clicked()));
    QObject::connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_4_clicked()));
    QObject::connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_pushButton_5_clicked()));
    QObject::connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_pushButton_6_clicked()));
    QObject::connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_pushButton_7_clicked()));
    QObject::connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_pushButton_8_clicked()));
    QObject::connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_pushButton_9_clicked()));
    QObject::connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(on_pushButton_10_clicked()));
    QObject::connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(on_pushButton_11_clicked()));
    QObject::connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(on_pushButton_12_clicked()));
    QObject::connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(on_pushButton_13_clicked()));
    QObject::connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(on_pushButton_14_clicked()));
    QObject::connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(on_pushButton_15_clicked()));
    QObject::connect(ui->pushButton_16,SIGNAL(clicked()),this,SLOT(on_pushButton_16_clicked()));
    QObject::connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(on_pushButton_17_clicked()));
    QObject::connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(on_pushButton_18_clicked()));
    QObject::connect(ui->pushButton_19,SIGNAL(clicked()),this,SLOT(on_pushButton_19_clicked()));
    QObject::connect(ui->pushButton_20,SIGNAL(clicked()),this,SLOT(on_pushButton_20_clicked()));
    QObject::connect(ui->pushButton_21,SIGNAL(clicked()),this,SLOT(on_pushButton_21_clicked()));
    QObject::connect(ui->pushButton_22,SIGNAL(clicked()),this,SLOT(on_pushButton_22_clicked()));
    QObject::connect(ui->pushButton_23,SIGNAL(clicked()),this,SLOT(on_pushButton_23_clicked()));
    QObject::connect(ui->pushButton_24,SIGNAL(clicked()),this,SLOT(on_pushButton_24_clicked()));
    QObject::connect(ui->pushButton_25,SIGNAL(clicked()),this,SLOT(on_pushButton_25_clicked()));
    QObject::connect(ui->pushButton_26,SIGNAL(clicked()),this,SLOT(on_pushButton_26_clicked()));
    QObject::connect(ui->pushButton_27,SIGNAL(clicked()),this,SLOT(on_pushButton_27_clicked()));
    QObject::connect(ui->pushButton_28,SIGNAL(clicked()),this,SLOT(on_pushButton_28_clicked()));
    QObject::connect(ui->pushButton_29,SIGNAL(clicked()),this,SLOT(on_pushButton_29_clicked()));
    QObject::connect(ui->pushButton_30,SIGNAL(clicked()),this,SLOT(on_pushButton_30_clicked()));
    QObject::connect(ui->pushButton_31,SIGNAL(clicked()),this,SLOT(on_pushButton_31_clicked()));
    QObject::connect(ui->pushButton_32,SIGNAL(clicked()),this,SLOT(on_pushButton_32_clicked()));
    QObject::connect(ui->pushButton_33,SIGNAL(clicked()),this,SLOT(on_pushButton_33_clicked()));
    QObject::connect(ui->pushButton_34,SIGNAL(clicked()),this,SLOT(on_pushButton_34_clicked()));
    QObject::connect(ui->pushButton_35,SIGNAL(clicked()),this,SLOT(on_pushButton_35_clicked()));
    QObject::connect(ui->pushButton_36,SIGNAL(clicked()),this,SLOT(on_pushButton_36_clicked()));
    QObject::connect(ui->pushButton_37,SIGNAL(clicked()),this,SLOT(on_pushButton_37_clicked()));
    QObject::connect(ui->pushButton_38,SIGNAL(clicked()),this,SLOT(on_pushButton_38_clicked()));
    QObject::connect(ui->pushButton_39,SIGNAL(clicked()),this,SLOT(on_pushButton_39_clicked()));
    QObject::connect(ui->pushButton_40,SIGNAL(clicked()),this,SLOT(on_pushButton_40_clicked()));
    QObject::connect(ui->pushButton_41,SIGNAL(clicked()),this,SLOT(on_pushButton_41_clicked()));
    QObject::connect(ui->pushButton_42,SIGNAL(clicked()),this,SLOT(on_pushButton_42_clicked()));
    QObject::connect(ui->pushButton_43,SIGNAL(clicked()),this,SLOT(on_pushButton_43_clicked()));
    QObject::connect(ui->pushButton_44,SIGNAL(clicked()),this,SLOT(on_pushButton_44_clicked()));
    QObject::connect(ui->pushButton_45,SIGNAL(clicked()),this,SLOT(on_pushButton_45_clicked()));
    QObject::connect(ui->pushButton_46,SIGNAL(clicked()),this,SLOT(on_pushButton_46_clicked()));
    QObject::connect(ui->pushButton_47,SIGNAL(clicked()),this,SLOT(on_pushButton_47_clicked()));
    QObject::connect(ui->pushButton_48,SIGNAL(clicked()),this,SLOT(on_pushButton_48_clicked()));
    QObject::connect(ui->pushButton_49,SIGNAL(clicked()),this,SLOT(on_pushButton_49_clicked()));
    QObject::connect(ui->pushButton_50,SIGNAL(clicked()),this,SLOT(on_pushButton_50_clicked()));
    QObject::connect(ui->pushButton_51,SIGNAL(clicked()),this,SLOT(on_pushButton_51_clicked()));
    QObject::connect(ui->pushButton_52,SIGNAL(clicked()),this,SLOT(on_pushButton_52_clicked()));
    QObject::connect(ui->pushButton_53,SIGNAL(clicked()),this,SLOT(on_pushButton_53_clicked()));
    QObject::connect(ui->pushButton_54,SIGNAL(clicked()),this,SLOT(on_pushButton_54_clicked()));
    QObject::connect(ui->pushButton_55,SIGNAL(clicked()),this,SLOT(on_pushButton_55_clicked()));
    QObject::connect(ui->pushButton_56,SIGNAL(clicked()),this,SLOT(on_pushButton_56_clicked()));
    QObject::connect(ui->pushButton_57,SIGNAL(clicked()),this,SLOT(on_pushButton_57_clicked()));
    QObject::connect(ui->pushButton_58,SIGNAL(clicked()),this,SLOT(on_pushButton_58_clicked()));
    QObject::connect(ui->pushButton_59,SIGNAL(clicked()),this,SLOT(on_pushButton_59_clicked()));
    QObject::connect(ui->pushButton_60,SIGNAL(clicked()),this,SLOT(on_pushButton_60_clicked()));
    QObject::connect(ui->pushButton_61,SIGNAL(clicked()),this,SLOT(on_pushButton_61_clicked()));
    QObject::connect(ui->pushButton_62,SIGNAL(clicked()),this,SLOT(on_pushButton_62_clicked()));
    QObject::connect(ui->pushButton_63,SIGNAL(clicked()),this,SLOT(on_pushButton_63_clicked()));
    QObject::connect(ui->pushButton_64,SIGNAL(clicked()),this,SLOT(on_pushButton_64_clicked()));
    QObject::connect(ui->pushButton_65,SIGNAL(clicked()),this,SLOT(on_pushButton_65_clicked()));
    QObject::connect(ui->pushButton_66,SIGNAL(clicked()),this,SLOT(on_pushButton_66_clicked()));
    QObject::connect(ui->pushButton_67,SIGNAL(clicked()),this,SLOT(on_pushButton_67_clicked()));
    QObject::connect(ui->pushButton_68,SIGNAL(clicked()),this,SLOT(on_pushButton_68_clicked()));
    QObject::connect(ui->pushButton_69,SIGNAL(clicked()),this,SLOT(on_pushButton_69_clicked()));
    QObject::connect(ui->pushButton_70,SIGNAL(clicked()),this,SLOT(on_pushButton_70_clicked()));
    QObject::connect(ui->pushButton_71,SIGNAL(clicked()),this,SLOT(on_pushButton_71_clicked()));
    QObject::connect(ui->pushButton_72,SIGNAL(clicked()),this,SLOT(on_pushButton_72_clicked()));
    QObject::connect(ui->pushButton_73,SIGNAL(clicked()),this,SLOT(on_pushButton_73_clicked()));
    QObject::connect(ui->pushButton_74,SIGNAL(clicked()),this,SLOT(on_pushButton_74_clicked()));
    QObject::connect(ui->pushButton_75,SIGNAL(clicked()),this,SLOT(on_pushButton_75_clicked()));
    QObject::connect(ui->pushButton_76,SIGNAL(clicked()),this,SLOT(on_pushButton_76_clicked()));
    QObject::connect(ui->pushButton_77,SIGNAL(clicked()),this,SLOT(on_pushButton_77_clicked()));
    QObject::connect(ui->pushButton_78,SIGNAL(clicked()),this,SLOT(on_pushButton_78_clicked()));
    QObject::connect(ui->pushButton_79,SIGNAL(clicked()),this,SLOT(on_pushButton_79_clicked()));
    QObject::connect(ui->pushButton_80,SIGNAL(clicked()),this,SLOT(on_pushButton_80_clicked()));
    QObject::connect(ui->pushButton_81,SIGNAL(clicked()),this,SLOT(on_pushButton_81_clicked()));
}

graphicgamefield::~graphicgamefield()
{
    delete ui;
}

void graphicgamefield::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

char graphicgamefield::DefineChislo(int chislo)
{
    char text;
    if (chislo == 0)
        text = '0';
    else if (chislo == 1)
        text = '1';
    else if (chislo == 2)
        text = '2';
    else if (chislo == 3)
        text = '3';
    else if (chislo == 4)
        text = '4';
    else if (chislo == 5)
        text = '5';
    else if (chislo == 6)
        text = '6';
    else if (chislo == 7)
        text = '7';
    else if (chislo == 8)
        text = '8';
    else if (chislo == 9)
        text = '9';
    return text;
}

void graphicgamefield::on_CheckButton_clicked()
{

}


void graphicgamefield::on_SaveButton_clicked()
{
    SaveGameDialog* Dialog = new SaveGameDialog;
    Dialog->show();
}

void graphicgamefield::on_pushButton_1_clicked()
{
    int chislo = GameField->GetCell(0, 0);
    if (chislo == 0)
        ui->pushButton_1->setText("0");
    else if (chislo == 1)
        ui->pushButton_1->setText("1");
    else if (chislo == 2)
        ui->pushButton_1->setText("2");
    else if (chislo == 3)
        ui->pushButton_1->setText("3");
    else if (chislo == 4)
        ui->pushButton_1->setText("4");
    else if (chislo == 5)
        ui->pushButton_1->setText("5");
    else if (chislo == 6)
        ui->pushButton_1->setText("6");
    else if (chislo == 7)
        ui->pushButton_1->setText("7");
    else if (chislo == 8)
        ui->pushButton_1->setText("8");
    else if (chislo == 9)
        ui->pushButton_1->setText("9");
}

void graphicgamefield::on_pushButton_2_clicked()
{
}

void graphicgamefield::on_pushButton_3_clicked()
{

}

void graphicgamefield::on_pushButton_4_clicked()
{
}

void graphicgamefield::on_pushButton_5_clicked()
{
}

void graphicgamefield::on_pushButton_6_clicked()
{
}

void graphicgamefield::on_pushButton_7_clicked()
{
}

void graphicgamefield::on_pushButton_8_clicked()
{
}

void graphicgamefield::on_pushButton_9_clicked()
{
}

void graphicgamefield::on_pushButton_10_clicked()
{

}

void graphicgamefield::on_pushButton_11_clicked()
{

}

void graphicgamefield::on_pushButton_12_clicked()
{

}

void graphicgamefield::on_pushButton_13_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_14_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_15_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_16_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_17_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_18_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_19_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_20_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_21_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_22_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_23_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_24_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_25_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_26_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_27_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_28_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_29_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_30_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_31_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_32_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_33_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_34_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_35_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_36_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_37_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_38_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_39_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_40_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_41_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_42_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_43_clicked()
{
    int chislo = GameField->GetCell(0, 1);
    char C = DefineChislo(chislo);
    char* p =&C;
    ui->pushButton_2->setText(p);

}

void graphicgamefield::on_pushButton_44_clicked()
{

}

void graphicgamefield::on_pushButton_45_clicked()
{

}

void graphicgamefield::on_pushButton_46_clicked()
{

}

void graphicgamefield::on_pushButton_47_clicked()
{

}

void graphicgamefield::on_pushButton_48_clicked()
{

}

void graphicgamefield::on_pushButton_49_clicked()
{

}

void graphicgamefield::on_pushButton_50_clicked()
{

}

void graphicgamefield::on_pushButton_51_clicked()
{

}

void graphicgamefield::on_pushButton_52_clicked()
{

}

void graphicgamefield::on_pushButton_53_clicked()
{

}

void graphicgamefield::on_pushButton_54_clicked()
{

}

void graphicgamefield::on_pushButton_55_clicked()
{

}

void graphicgamefield::on_pushButton_56_clicked()
{

}

void graphicgamefield::on_pushButton_57_clicked()
{

}

void graphicgamefield::on_pushButton_58_clicked()
{

}

void graphicgamefield::on_pushButton_59_clicked()
{

}

void graphicgamefield::on_pushButton_60_clicked()
{

}

void graphicgamefield::on_pushButton_61_clicked()
{

}

void graphicgamefield::on_pushButton_62_clicked()
{

}

void graphicgamefield::on_pushButton_63_clicked()
{

}

void graphicgamefield::on_pushButton_64_clicked()
{

}

void graphicgamefield::on_pushButton_65_clicked()
{

}

void graphicgamefield::on_pushButton_66_clicked()
{

}

void graphicgamefield::on_pushButton_67_clicked()
{

}

void graphicgamefield::on_pushButton_68_clicked()
{

}

void graphicgamefield::on_pushButton_69_clicked()
{

}

void graphicgamefield::on_pushButton_70_clicked()
{

}

void graphicgamefield::on_pushButton_71_clicked()
{

}

void graphicgamefield::on_pushButton_72_clicked()
{

}

void graphicgamefield::on_pushButton_73_clicked()
{

}

void graphicgamefield::on_pushButton_74_clicked()
{

}

void graphicgamefield::on_pushButton_75_clicked()
{

}

void graphicgamefield::on_pushButton_76_clicked()
{

}

void graphicgamefield::on_pushButton_77_clicked()
{

}

void graphicgamefield::on_pushButton_78_clicked()
{

}

void graphicgamefield::on_pushButton_79_clicked()
{

}

void graphicgamefield::on_pushButton_80_clicked()
{

}

void graphicgamefield::on_pushButton_81_clicked()
{

}
void graphicgamefield::Create_Button_1()
{
}
void graphicgamefield::Create_Button_2()
{
}
void graphicgamefield::Create_Button_3()
{
}
void graphicgamefield::Create_Button_4()
{
}
void graphicgamefield::Create_Button_5()
{
}
void graphicgamefield::Create_Button_6()
{
}
void graphicgamefield::Create_Button_7()
{
}
void graphicgamefield::Create_Button_8()
{
}
void graphicgamefield::Create_Button_9()
{
}
void graphicgamefield::Create_Button_10()
{
}
void graphicgamefield::Create_Button_11()
{
}
void graphicgamefield::Create_Button_12()
{
}
void graphicgamefield::Create_Button_13()
{
}
void graphicgamefield::Create_Button_14()
{
}
void graphicgamefield::Create_Button_15()
{
}
void graphicgamefield::Create_Button_16()
{
}
void graphicgamefield::Create_Button_17()
{
}
void graphicgamefield::Create_Button_18()
{
}
void graphicgamefield::Create_Button_19()
{
}
void graphicgamefield::Create_Button_20()
{
}
void graphicgamefield::Create_Button_21()
{
}
void graphicgamefield::Create_Button_22()
{
}
void graphicgamefield::Create_Button_23()
{
}
void graphicgamefield::Create_Button_24()
{
}
void graphicgamefield::Create_Button_25()
{
}
void graphicgamefield::Create_Button_26()
{
}
void graphicgamefield::Create_Button_27()
{
}
void graphicgamefield::Create_Button_28()
{
}
void graphicgamefield::Create_Button_29()
{
}
void graphicgamefield::Create_Button_30()
{
}
void graphicgamefield::Create_Button_31()
{
}
void graphicgamefield::Create_Button_32()
{
}
void graphicgamefield::Create_Button_33()
{
}
void graphicgamefield::Create_Button_34()
{
}
void graphicgamefield::Create_Button_35()
{
}
void graphicgamefield::Create_Button_36()
{
}
void graphicgamefield::Create_Button_37()
{
}
void graphicgamefield::Create_Button_38()
{
}
void graphicgamefield::Create_Button_39()
{
}
void graphicgamefield::Create_Button_40()
{
}
void graphicgamefield::Create_Button_41()
{
}
void graphicgamefield::Create_Button_42()
{
}
void graphicgamefield::Create_Button_43()
{
}
void graphicgamefield::Create_Button_44()
{
}
void graphicgamefield::Create_Button_45()
{
}
void graphicgamefield::Create_Button_46()
{
}
void graphicgamefield::Create_Button_47()
{
}
void graphicgamefield::Create_Button_48()
{
}
void graphicgamefield::Create_Button_49()
{
}
void graphicgamefield::Create_Button_50()
{
}
void graphicgamefield::Create_Button_51()
{
}
void graphicgamefield::Create_Button_52()
{
}
void graphicgamefield::Create_Button_53()
{
}
void graphicgamefield::Create_Button_54()
{
}
void graphicgamefield::Create_Button_55()
{
}
void graphicgamefield::Create_Button_56()
{
}
void graphicgamefield::Create_Button_57()
{
}
void graphicgamefield::Create_Button_58()
{
}
void graphicgamefield::Create_Button_59()
{
}
void graphicgamefield::Create_Button_60()
{
}
void graphicgamefield::Create_Button_61()
{
}
void graphicgamefield::Create_Button_62()
{
}
void graphicgamefield::Create_Button_63()
{
}
void graphicgamefield::Create_Button_64()
{
}
void graphicgamefield::Create_Button_65()
{
}
void graphicgamefield::Create_Button_66()
{
}
void graphicgamefield::Create_Button_67()
{
}
void graphicgamefield::Create_Button_68()
{
}
void graphicgamefield::Create_Button_69()
{
}
void graphicgamefield::Create_Button_70()
{
}
void graphicgamefield::Create_Button_71()
{
}
void graphicgamefield::Create_Button_72()
{
}
void graphicgamefield::Create_Button_73()
{
}
void graphicgamefield::Create_Button_74()
{
}
void graphicgamefield::Create_Button_75()
{
}
void graphicgamefield::Create_Button_76()
{
}
void graphicgamefield::Create_Button_77()
{
}
void graphicgamefield::Create_Button_78()
{
}
void graphicgamefield::Create_Button_79()
{
}
void graphicgamefield::Create_Button_80()
{
}
void graphicgamefield::Create_Button_81()
{
}
