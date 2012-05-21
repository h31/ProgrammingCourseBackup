
#include "ExitDialog.h"

ExitDialog::ExitDialog(QString a)
 {
 label.setText(a);
 ok.setText(tr("New Game"));
 connect(& ok,SIGNAL(clicked()),this,SLOT(ok_presed()));
 cancel.setText(tr("Cancel"));
 connect(& cancel,SIGNAL(clicked()),this,SLOT(cancel_presed()));
 exit.setText(tr("Exit"));
 connect(& exit,SIGNAL(clicked()),this,SLOT(exit_presed()));
 hi.addWidget(& label);
 lo.addWidget(& ok);
 lo.addWidget(& cancel);
 lo.addWidget(& exit);
 lay.addLayout(& hi);
 lay.addLayout(& lo);
 this->setLayout(& lay);
 }

void ExitDialog::ok_presed()
 {
 emit this->accepted();
 this->close();
 }
 void ExitDialog::cancel_presed()
 {
 emit reject();
 this->close();
 }
 void ExitDialog::exit_presed()
 {
 emit exits();
 this->close();
 }
