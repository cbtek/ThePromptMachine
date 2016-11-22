#ifndef _CBTEK_COMMON_MATH_HEXAGON_H
#define _CBTEK_COMMON_MATH_HEXAGON_H

#include "Line.hpp"
#include "Point.hpp"
#include "Quad.hpp"
#include "MathUtils.hpp"

#include <iostream>

namespace cbtek {
namespace common {
namespace math {

class Hexagon
{

public:

    Hexagon(const int & x=0, const int & y=0, const int & width=4 , const int & height=4);
    const Line2i * getSide(const int &index) const;
    const int x() const;
    const int y() const;
    const int w() const;
    const int h() const;
    void move(const int & x, const int & y);
    void resize(const int & w, const int & h);
    void setBounds(const int & x, const int & y,const int & w, const int & h);
    const bool contains(const int & x, const int & y)const;
    const bool intersects(const int & x, const int & y)const;

private:
    void update();
    Line2i m_sides[6];
    Quad<std::int64_t> m_quad;


};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_HEXAGON_H
