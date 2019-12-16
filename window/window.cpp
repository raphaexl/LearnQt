#include "window.h"

static  Vertex  qd_vertices[] = {
    Vertex(QVector3D(-1.0f, -1.0f, 1.0f), QVector3D(1.0, 0.0, 0.0)),
    Vertex(QVector3D(-1.0,  1.0, 1.0), QVector3D(0.0, 0.0, 1.0)),
    Vertex(QVector3D(1.0, 1.0, 1.0), QVector3D(0.0, 1.0, 0.0)),
    Vertex(QVector3D(1.0, 1.0, 1.0), QVector3D(0.0, 1.0, 0.0)),
    Vertex(QVector3D(1.0, -1.0, 1.0), QVector3D(1.0, 1.0, 0.0)),
     Vertex(QVector3D(-1.0f, -1.0f, 1.0f), QVector3D(1.0, 0.0, 0.0))
};

void    Window::initializeGL(void)
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    {
        m_program = new QOpenGLShaderProgram();
        m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple_v.vert");
        m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple_f.frag");
        m_program->link();
        m_program->bind();

        m_vbo.create();
        m_vbo.bind();
        m_vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
        m_vbo.allocate(qd_vertices, sizeof (qd_vertices));

        m_vao.create();
        m_vao.bind();
        m_program->enableAttributeArray(0);
        m_program->enableAttributeArray(1);
        m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
        m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

        m_vbo.release();
        m_vao.release();
        m_program->release();
    }
}

void    Window::resizeGL(int width, int height)
{
    (void)width;
    (void)height;
}

void    Window::paintGL(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    m_program->bind();
    {
        m_vao.bind();
        glDrawArrays(GL_TRIANGLES, 0, sizeof(qd_vertices) / sizeof(qd_vertices[0]));
        m_vao.release();
    }
    m_program->release();
}

void    Window::printContexInformations(void)
{
    QString glType;
    QString glVersion;
    QString glProfile;

    glType = (context()->isOpenGLES()) ? "OPENGL ES" : "OPENGL";
    glVersion = reinterpret_cast<const char *>(glGetString(GL_VERSION));

#define CASE(c) case QSurfaceFormat::c:glProfile = #c; break;
    switch (format().profile())
    {
        CASE(NoProfile)
        CASE(CoreProfile)
        CASE(CompatibilityProfile)
    }
#undef  CASE
    qDebug() << qPrintable(glType) << qPrintable(glVersion) << "("<<qPrintable(glProfile)<<")";
}

void    Window::cleanupGL()
{
    m_vbo.destroy();
    m_vao.destroy();
    delete m_program;
}

Window::~Window()
{
    makeCurrent();
    cleanupGL();
}
