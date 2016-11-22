#ifndef _CBTEK_COMMON_MATH_TRIANGLE_H
#define _CBTEK_COMMON_MATH_TRIANGLE_H

#include "Vector3.hpp"
#include "MathUtils.hpp"

namespace cbtek {
namespace common {
namespace math {

class Triangle
{
public:
    Triangle(const Vector3f & a=Vector3f(),
             const Vector3f & b=Vector3f(),
             const Vector3f & c=Vector3f());

     Vector3f getPointA() const;

     Vector3f getPointB() const;

     Vector3f getPointC() const;

     void setPointA(const Vector3f & pt);

     void setPointB(const Vector3f & pt);

     void setPointC(const Vector3f & pt);

     bool contains(const Vector3f & point) const;

private:
    Vector3f m_a,m_b,m_c;
};

}}} //namespace
#endif // _CBTEK_COMMON_MATH_TRIANGLE_H
