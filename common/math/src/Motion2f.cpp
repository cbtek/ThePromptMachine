#include "Motion2f.h"

namespace cbtek {
namespace common {
namespace math {


Motion2f::Motion2f(const float &x, const float &y, const float &speed, const float &heading, const Point<float> &velocity)
    :Point<float>(x,y)
{
    m_velocity=velocity;
    m_heading=heading;
    m_speed=speed;
}

void Motion2f::move()
{
    Point<float>::move(m_heading,m_speed,m_velocity.getX(),m_velocity.getY());
}
void Motion2f::setVelocity(const Point<float> &vel)
{
    m_velocity=vel;
}

const Point<float> &Motion2f::getVelocity() const
{
    return m_velocity;
}

void Motion2f::setSpeed(const float &speed)
{
    m_speed=speed;
}

const float Motion2f::getSpeed() const
{
    return m_speed;
}

const float Motion2f::getHeading() const
{
    return m_heading;
}

void Motion2f::setHeading(const float &heading)
{
    m_heading=heading;
}

}}} //namespace
