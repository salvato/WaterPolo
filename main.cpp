#include "waterpoloapp.h"

#include <QSurfaceFormat>


int
main(int argc, char *argv[]) {

    QSurfaceFormat format;
    format.setVersion(3, 3);
    format.setDepthBufferSize(32);
    format.setSamples(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setOption(QSurfaceFormat::DeprecatedFunctions, false);
    QSurfaceFormat::setDefaultFormat(format);

    WaterPoloApp a(argc, argv);
    QString sVersion = QString("3.00");
    a.setApplicationVersion(sVersion);

    int iResult = a.exec();
    return iResult;
}
