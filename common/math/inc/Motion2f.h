#ifndef _CBTEK_COMMON_MATH_MOTION2F_H
#define _CBTEK_COMMON_MATH_MOTION2F_H

#include "Point.hpp"

namespace cbtek {
namespace common {
namespace math {

class Motion2f : public Point<float>
{
public:

    Motion2f(const float & x=0, const float & y=0, const float & speed=1, const float & heading=0, const Point<float> & velocity=Point<float>(0,0));

    void move();

    void setVelocity(const Point<float> & vel);

    const Point<float> & getVelocity() const;

    void setSpeed(const float & speed);

    const float getSpeed() const;

    const float getHeading() const;

    void setHeading(const float& heading);

private:

    float m_speed;

    float m_heading;

    Point<float> m_velocity;
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_MOTION2F_H
