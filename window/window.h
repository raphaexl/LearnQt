#ifndef WINDOW_H
#define WINDOW_H
# include <QOpenGLWindow>
# include <QOpenGLFunctions>
# include <QOpenGLBuffer>
# include <QOpenGLVertexArrayObject>
# include <QOpenGLShaderProgram>
# include <QGuiApplication>
# include <QString>
# include <QDebug>

# include "vertex.h"


class Window : public QOpenGLWindow,
        protected QOpenGLFunctions
{
public:
    ~Window();

    void    initializeGL(void);
    void    resizeGL(int width, int height);
    void    paintGL(void);
    void    cleanupGL(void);

private:
    QOpenGLBuffer               m_vbo;
    QOpenGLVertexArrayObject    m_vao;
    QOpenGLShaderProgram        *m_program;

    void    printContexInformations(void);
};

#endif // WINDOW_H
