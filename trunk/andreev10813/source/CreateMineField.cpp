
#include "CreateMineField.h"

CreateMineField::CreateMineField()
 {
 sa.setValue(10);
 sb.setValue(10);
 sc.setValue(10);
 la.setText(tr("Colums"));
 lb.setText(tr("Rows"));
 lc.setText(tr("Mines"));
 hi.addWidget(& la);
 hi.addWidget(& sa);
 hi.addWidget(& lb);
 hi.addWidget(& sb);
 hi.addWidget(& lc);
 hi.addWidget(& sc);
 ok.setText(tr("OK"));
 connect(& ok,SIGNAL(clicked()),this,SLOT(ok_presed()));
 cancel.setText(tr("Cancel"));
 connect(& cancel,SIGNAL(clicked()),this,SLOT(cancel_presed()));
 lo.addWidget(& ok);
 lo.addWidget(& cancel);
 layout.addLayout(& hi);
 layout.addLayout(& lo);
 this->setLayout(& layout);
 }

void CreateMineField::ok_presed()
 {
 emit acepted(sa.value(),sb.value(),sc.value());
 this->close();
 }

void CreateMineField::cancel_presed()
 {
 this->close();
 }
