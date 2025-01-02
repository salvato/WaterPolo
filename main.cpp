#include "waterpoloapp.h"

#include <QSurfaceFormat>


int
main(int argc, char *argv[]) {

    QSurfaceFormat format;
    format.setDepthBufferSize(32);
    format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    WaterPoloApp a(argc, argv);
    QString sVersion = QString("1.01");
    a.setApplicationVersion(sVersion);

    int iResult = a.exec();
    return iResult;
}
