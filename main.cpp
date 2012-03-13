#include <QtCore/QCoreApplication>
#include "jarjestelmaohjain.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    JarjestelmaOhjain *mp_ohjain = new JarjestelmaOhjain();

    delete mp_ohjain;

    return a.exec();
}
