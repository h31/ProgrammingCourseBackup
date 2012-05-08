#ifndef GRAPHICGAMEFIELD_H
#define GRAPHICGAMEFIELD_H

#include <QWidget>
#include "field.h"
#include "savedgames.h"

namespace Ui {
class graphicgamefield;
}

class graphicgamefield : public QWidget
{
    Q_OBJECT
    
public:
    explicit graphicgamefield(QWidget *parent = 0);
    Field *GameField;
    char DefineChislo(int chislo);
    ~graphicgamefield();
    
protected:
    void changeEvent(QEvent *e);
    
private slots:

    void on_CheckButton_clicked();

    void on_SaveButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_66_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_70_clicked();

    void on_pushButton_71_clicked();

    void on_pushButton_72_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_74_clicked();

    void on_pushButton_75_clicked();

    void on_pushButton_76_clicked();

    void on_pushButton_77_clicked();

    void on_pushButton_78_clicked();

    void on_pushButton_79_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_81_clicked();

    void Create_Button_1();
    void Create_Button_2();
    void Create_Button_3();
    void Create_Button_4();
    void Create_Button_5();
    void Create_Button_6();
    void Create_Button_7();
    void Create_Button_8();
    void Create_Button_9();
    void Create_Button_10();
    void Create_Button_11();
    void Create_Button_12();
    void Create_Button_13();
    void Create_Button_14();
    void Create_Button_15();
    void Create_Button_16();
    void Create_Button_17();
    void Create_Button_18();
    void Create_Button_19();
    void Create_Button_20();
    void Create_Button_21();
    void Create_Button_22();
    void Create_Button_23();
    void Create_Button_24();
    void Create_Button_25();
    void Create_Button_26();
    void Create_Button_27();
    void Create_Button_28();
    void Create_Button_29();
    void Create_Button_30();
    void Create_Button_31();
    void Create_Button_32();
    void Create_Button_33();
    void Create_Button_34();
    void Create_Button_35();
    void Create_Button_36();
    void Create_Button_37();
    void Create_Button_38();
    void Create_Button_39();
    void Create_Button_40();
    void Create_Button_41();
    void Create_Button_42();
    void Create_Button_43();
    void Create_Button_44();
    void Create_Button_45();
    void Create_Button_46();
    void Create_Button_47();
    void Create_Button_48();
    void Create_Button_49();
    void Create_Button_50();
    void Create_Button_51();
    void Create_Button_52();
    void Create_Button_53();
    void Create_Button_54();
    void Create_Button_55();
    void Create_Button_56();
    void Create_Button_57();
    void Create_Button_58();
    void Create_Button_59();
    void Create_Button_60();
    void Create_Button_61();
    void Create_Button_62();
    void Create_Button_63();
    void Create_Button_64();
    void Create_Button_65();
    void Create_Button_66();
    void Create_Button_67();
    void Create_Button_68();
    void Create_Button_69();
    void Create_Button_70();
    void Create_Button_71();
    void Create_Button_72();
    void Create_Button_73();
    void Create_Button_74();
    void Create_Button_75();
    void Create_Button_76();
    void Create_Button_77();
    void Create_Button_78();
    void Create_Button_79();
    void Create_Button_80();
    void Create_Button_81();

private:
    Ui::graphicgamefield *ui;
};

#endif // GRAPHICGAMEFIELD_H
