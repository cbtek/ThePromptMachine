#include "Triangle.h"

namespace cbtek {
namespace common {
namespace math {

Triangle::Triangle(const Vector3f &a, const Vector3f &b, const Vector3f &c)
{
    m_a=a;
    m_b=b;
    m_c=c;
}

Vector3f Triangle::getPointA() const
{
    return m_a;
}

Vector3f Triangle::getPointB() const
{
    return m_b;
}

Vector3f Triangle::getPointC() const
{
    return m_c;
}

void Triangle::setPointA(const Vector3f &pt)
{
    m_a=pt;
}

void Triangle::setPointB(const Vector3f &pt)
{
    m_b=pt;
}

void Triangle::setPointC(const Vector3f &pt)
{
    m_c=pt;
}

bool Triangle::contains(const Vector3f &point) const
{
    return MathUtils::isPointInTriangle(point,m_a,m_b,m_c);
}


}}} //namespace
