#ifndef VERTEX_H
#define VERTEX_H
# include <QVector3D>

class   Vertex
{
public:
        Q_DECL_CONSTEXPR Vertex();
        Q_DECL_CONSTEXPR explicit Vertex(const QVector3D &position);
        Q_DECL_CONSTEXPR Vertex(const QVector3D &position, const QVector3D &color);

        Q_DECL_CONSTEXPR const QVector3D &position(void)const;
        Q_DECL_CONSTEXPR const QVector3D &color(void)const;
        void   setPosition(const QVector3D &position);
        void   setColor(const QVector3D &color);

        static  const     int   PositionTupleSize{3};
        static  const     int   ColorTupleSize{3};
        static  Q_DECL_CONSTEXPR int    positionOffset(void);
        static  Q_DECL_CONSTEXPR int    colorOffset(void);
        static  Q_DECL_CONSTEXPR int    stride(void);

private:
        QVector3D   m_position;
        QVector3D   m_color;
};

Q_DECLARE_TYPEINFO(Vertex, Q_MOVABLE_TYPE);

Q_DECL_CONSTEXPR    inline  Vertex::Vertex(){};
Q_DECL_CONSTEXPR    inline  Vertex::Vertex(const QVector3D &position):m_position(position){}
Q_DECL_CONSTEXPR    inline  Vertex::Vertex(const QVector3D &position, const QVector3D &color):m_position(position),m_color(color){}

Q_DECL_CONSTEXPR    inline  const QVector3D &Vertex::position(void)const{return (m_position);}
Q_DECL_CONSTEXPR    inline  const QVector3D &Vertex::color(void)const {return (m_color);}
void                inline  Vertex::setPosition(const QVector3D &position){m_position = position;}
void                inline  Vertex::setColor(const QVector3D &color){m_color = color;}

Q_DECL_CONSTEXPR    inline  int     Vertex::positionOffset(void){return (offsetof(Vertex, m_position));}
Q_DECL_CONSTEXPR    inline  int     Vertex::colorOffset(void){return (offsetof(Vertex, m_color));}
Q_DECL_CONSTEXPR    inline  int     Vertex::stride(void){return (sizeof(Vertex));}


#endif // VERTEX_H
