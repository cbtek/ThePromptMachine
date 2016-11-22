#ifndef _CBTEK_COMMON_MATH_QUAD_H
#define _CBTEK_COMMON_MATH_QUAD_H

#include "MathUtils.hpp"

namespace cbtek {
namespace common {
namespace math {

template <typename T>
class Quad
{
public:

    Quad(const T & x=0, const T & y=0, const T & w=0, const T & h=0);

    T getX()const;

    T getY()const;

    T getMaxX() const;

    T getMaxY() const;

    T getCenterX() const;

    T getCenterY() const;

    void setX(const T & x);

    void setY(const T & y);

    void translate(const T &angle, const T &radius, const T &velX=0, const T &velY=0);

    T getW()const;

    T getH()const;

    void setW(const T & w);

    void setH(const T & h);

    void incrementX(const T & dx);

    void incrementY(const T & dy);

    void incrementW(const T & dw);

    void incrementH(const T & dh);

    void set(const T & x, const T & y, const T & w, const T & h);

    bool contains(const T & x, const T & y) const;

    bool contains(const Quad & q) const;

    void setSize(const T & w, const T & h);

    void setPosition(const T & x, const T & y);

    void moveCenterTo(const T & x, const T & y);

    std::string toString();

    void shrink(const T &dx);

    void grow(const T &dx);
	
    Quad<T> getQuadrent1() const;
    Quad<T> getQuadrent2() const;
    Quad<T> getQuadrent3() const;
    Quad<T> getQuadrent4() const;
	void resize(T w, T h);
	
	void setBottomY(T y);
	
	void setRightX(T x);
	
	T getBottomY() const;
	
	T getRightX() const;
	
	
	
private:

    T m_x,m_y,m_w,m_h;

};

template<class T>
void Quad<T>::setBottomY(T y)
{
	m_y = y-m_h;
}
	
template<class T>
void Quad<T>::setRightX(T x)
{
	m_x = x-m_w;
}

template<class T>
T Quad<T>::getBottomY() const
{
	return m_y+m_h;
}

template<class T>
T Quad<T>::getRightX() const
{
	return m_x+m_w;
}

template<class T>
void Quad<T>::resize(T w, T h)
{
		m_w=w;
		m_h=h;
}

template<class T>
Quad<T>::Quad(const T &x, const T &y, const T &w, const T &h)
{
    set(x,y,w,h);
}

template<class T>
T Quad<T>::getX()const{return m_x;}

template<class T>
T Quad<T>::getY()const{return m_y;}

template<class T>
T Quad<T>::getMaxX() const
{
    return m_x+m_w;
}

template<class T>
T Quad<T>::getMaxY() const
{
    return m_y+m_h;
}

template<class T>
T Quad<T>::getCenterX() const
{
    return m_x+(.5*m_w);
}

template<class T>
T Quad<T>::getCenterY() const
{
    return m_y+(.5*m_h);
}

template<class T>
void Quad<T>::setX(const T & x){m_x=x;}

template<class T>
void Quad<T>::setY(const T & y){m_y=y;}

template<class T>
void Quad<T>::translate(const T &angle, const T &radius, const T &velX, const T &velY)
{
    T degree=MathUtils::getNormalizedDegree(angle);
    m_x+=(((double)velX)+((double)MathUtils::cosd(degree) * (double)radius));
    m_y+=(((double)velY)+((double)MathUtils::sind(degree) * (double)radius));
}

template<class T>
T Quad<T>::getW()const{return m_w;}

template<class T>
T Quad<T>::getH()const{return m_h;}

template<class T>
void Quad<T>::setW(const T & w){m_w=w;}

template<class T>
void Quad<T>::setH(const T & h){m_h=h;}

template<class T>
void Quad<T>::incrementX(const T &dx)
{
    m_x+=dx;
}

template<class T>
void Quad<T>::incrementY(const T &dy)
{
    m_y+=dy;
}

template<class T>
void Quad<T>::incrementW(const T &dw)
{
    m_w+=dw;
}

template<class T>
void Quad<T>::incrementH(const T &dh)
{
    m_h+=dh;
}

template<class T>
void Quad<T>::set(const T & x, const T & y, const T & w, const T & h)
{
    m_x=x;
    m_y=y;
    m_w=w;
    m_h=h;
}

template<class T>
bool Quad<T>::contains(const T &x, const T &y) const
{
    return ((x>=m_x && x<=(m_x+m_w)) && (y>=m_y && y<=(m_y+m_h)));
}

template<class T>
bool Quad<T>::contains(const Quad &q) const
{
    return contains(q.getX(),q.getY()) ||
           contains(q.getMaxX(),q.getMaxY()) ||
           contains(q.getX(),q.getMaxY()) ||
           contains(q.getMaxX(),q.getY());
}

template<class T>
void Quad<T>::moveCenterTo(const T & x, const T & y)
{
    setX(x-(m_w/2));
    setY(y-(m_h/2));
}

template<class T>
std::string Quad<T>::toString()
{
    std::ostringstream out;
    out <<"(x="<< m_x<<", y="<<m_y<<", w="<<m_w<<", h="<<m_h<<")";
    return out.str();
}
template<class T>
void Quad<T>::shrink(const T &dx)
{
    m_w-=dx;
    m_h-=dx;
    m_x+=dx;
    m_y+=dx;
}

template<class T>
void Quad<T>::grow(const T &dx)
{
    m_w+=(dx+dx);
    m_h+=(dx+dx);
    m_x-=dx;
    m_y-=dx;
}

template<class T>
void Quad<T>::setSize(const T &w, const T &h)
{
    m_w=w;
    m_h=h;
}

template<class T>
void Quad<T>::setPosition(const T &x, const T &y)
{
    m_x=x;
    m_y=y;
}
template<class T>
Quad<T> Quad<T>::getQuadrent1() const
{
    Quad<T> q;
    q.set(this->getCenterX(),this->getY(),this->getW()/2,this->getH()/2);
    return q;

}

template<class T>
Quad<T> Quad<T>::getQuadrent2() const
{
    Quad<T> q;
    q.set(this->getX(),this->getY(),this->getW()/2,this->getH()/2);
    return q;
}

template<class T>
Quad<T> Quad<T>::getQuadrent3() const
{
    Quad<T> q;
    q.set(this->getX(),this->getCenterY(),this->getW()/2,this->getH()/2);
    return q;
}

template<class T>
Quad<T> Quad<T>::getQuadrent4() const
{
    Quad<T> q;
    q.set(this->getCenterX(),this->getCenterY(),this->getW()/2,this->getH()/2);
    return q;
}

typedef Quad<float> Quad2f;
typedef Quad<int> Quad2i;
typedef common::utility::ObjectList<Quad2f> Quad2fList;
typedef common::utility::ObjectList<Quad2i> Quad2iList;
}}} //namespace
#endif // _CBTEK_COMMON_MATH_QUAD_H
