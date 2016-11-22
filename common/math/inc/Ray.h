#ifndef _CBTEK_COMMON_MATH_RAY_H
#define _CBTEK_COMMON_MATH_RAY_H

#include "Vector3.hpp"

namespace cbtek {
namespace common {
namespace math {
class Ray
{

public:

    Ray();

    void setDirection(const common::math::Vector3f & origin);

    void setOrigin(const common::math::Vector3f & origin);

    const common::math::Vector3f & getOrigin() const;

    const common::math::Vector3f & getDirection() const;

private:

    Vector3f m_origin;

    Vector3f m_direction;
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_RAY_H
