#include "window.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat  format;

    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4, 3);

    Window  window;

    window.setFormat(format);
    window.resize(QSize(800, 800));
    window.show();
    return a.exec();
}
