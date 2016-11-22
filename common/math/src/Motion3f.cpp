#include "Motion3f.h"

namespace cbtek {
namespace common {
namespace math {


Motion3f::Motion3f(const float &x, const float &y, const float &z)
    :Vector3f(x,y,z)
{
}

void Motion3f::setVelocity(const Vector3f &velocity)
{
    m_velocity=velocity;
}

const Vector3f &Motion3f::getVelocity() const
{
    return m_velocity;
}

void Motion3f::setSpeed(const float &speed)
{
    m_speed=speed;
}

const float Motion3f::getSpeed() const
{
    return m_speed;
}

}}} //namespace
