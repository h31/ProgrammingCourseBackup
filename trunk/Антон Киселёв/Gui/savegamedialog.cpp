#include "savegamedialog.h"
#include "savedgames.h"
#include "mainwidget.h"

SaveGameDialog::SaveGameDialog():QDialog()
{
    save = new QPushButton("&Save");
    cancel = new QPushButton("&Cancel");
    lay = new QGridLayout;
    connect(save,SIGNAL(clicked()),SLOT(save_pressed()));
    connect(cancel,SIGNAL(clicked()),SLOT(cancel_press()));
    lay->addWidget(save, 0, 0);
    lay->addWidget(cancel, 0, 1);
    this->setLayout(lay);
}

SaveGameDialog::~SaveGameDialog()
{
    delete[] save;
    delete[] cancel;
    delete[] lay;
}

void SaveGameDialog::save_pressed(Field* GameField)
{
    SavedGames* SaveGame = new SavedGames;
    SaveGame->SaveRequest(GameField);
    exits();
}

void SaveGameDialog::cancel_press()
{
    exits();
}
