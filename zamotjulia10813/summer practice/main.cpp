#include <QtGui/QApplication>
#include "widget.h"
#include <phonon/phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));
    Widget w;
    w.show();

    Phonon::MediaObject media;
    Phonon::AudioOutput ao(Phonon::MusicCategory);
    Phonon::createPath (&media, &ao);
   // QObject::connect(&media, SIGNAL(finished()), &app, SLOT(quit()));
    media.setCurrentSource(Phonon::MediaSource(":/coca"));
    media.enqueue(Phonon::MediaSource(":/coca"));
    media.enqueue(Phonon::MediaSource(":/coca"));
    media.play();

    return a.exec();
}
