#ifndef _CBTEK_COMMON_MATH_POINT_H
#define _CBTEK_COMMON_MATH_POINT_H

#include <string>
#include <sstream>
#include <cmath>

#include "utility/inc/ObjectList.hpp"

namespace cbtek {
namespace common {
namespace math {

template <typename T>
class Point
{
public:

    Point(const T & x=0, const T & y=0);

    void set(const T & x, const T & y);

    const T & getX() const;

    const T & getY() const;

    void setX(const T &x);

    void setY(const T &y);

    const std::string toString();

    void rotate(const size_t & degree, const size_t &originX=0, const size_t &originY=0);

    void move(const T & angle, const T & radius, const T & velX=0,const T & velY=0);

    void incrementX(const T & dx);

    void incrementY(const T & dy);
private:

    T m_x,m_y;

private:

};

template <typename T>
Point<T>::Point(const T & x, const T & y)
{
    this->m_x=x;this->m_y=y;
}

template <typename T>
void Point<T>::set(const T &x, const T &y)
{
    this->m_x=x;this->m_y=y;
}

template <typename T>
const T &Point<T>::getX() const
{
    return this->m_x;
}

template <typename T>
const T &Point<T>::getY() const
{
    return this->m_y;
}

template <typename T>
void Point<T>::setX(const T &x)
{
    this->m_x=x;
}

template <typename T>
void Point<T>::setY(const T &y)
{
    this->m_y=y;
}

template <typename T>
const std::string Point<T>::toString()
{
    std::ostringstream out;
    out << this->m_x<<" "<<this->m_y;
    return out.str();
}

template <typename T>
void Point<T>::rotate(const size_t &degree,const size_t & originX,const size_t & originY)
{
    if (degree<360)
    {
        double x=this->m_x,y=this->m_y,ox=originX,oy=originY;
        double radian=degree*0.0174532925;
        double cosValue=std::cos(radian);
        double sinValue=std::sin(radian);
        m_x = (cosValue * (x-ox)) - (sinValue*(y-oy)) + ox;
        m_y = (cosValue * (x-ox)) + (sinValue*(y-oy)) + oy;
    }
}

template <typename T>
void Point<T>::move(const T &angle, const T &radius, const T &velX, const T &velY)
{
    T degree=angle;
    if (angle>360)
    {
        degree=angle-360;
    }
    else if (angle<0)
    {
        degree= 360+angle;
    }

    double radian=(double)degree*0.0174532925;
    double cosValue=std::cos(radian);
    double sinValue=std::sin(radian);
    m_x+=((velX)+(cosValue * radius));
    m_y+=((velY)+(sinValue * radius));
}

template <typename T>
void Point<T>::incrementX(const T &dx)
{
    m_x+=dx;
}

template <typename T>
void Point<T>::incrementY(const T &dy)
{
    m_y+=dy;
}

typedef Point<float> Point2f;
typedef Point<int> Point2i;

typedef common::utility::ObjectList<Point2f> Point2fList;
typedef common::utility::ObjectList<Point2i> Point2iList;
}}} //namespace
#endif //_CBTEK_COMMON_MATH_POINT_H
