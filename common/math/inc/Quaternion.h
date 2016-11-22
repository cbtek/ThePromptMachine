#ifndef _CBTEK_COMMON_MATH_QUATERNION_H
#define _CBTEK_COMMON_MATH_QUATERNION_H

#include <string>

#include "Vector3.hpp"
#include "Matrix.h"

namespace cbtek {
namespace common {
namespace math {

class Quaternion
{
public:

    Quaternion();
    Quaternion(const float & x, const float & y, const float & z, const float & w);
    Quaternion(const common::math::Vector3f & vec);
    Quaternion(const common::math::Vector3f & axis, const float & radians);

    Quaternion(const Quaternion & quat);
    Quaternion(const Matrix & matrix);
    Quaternion(const float & axisAngleX, const float & axisAngleY, const float & axisAngleZ);
    Quaternion & operator=(const Quaternion & quat);

    void set(const float & x, const float & y, const float & z,const float & w);
    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;
    void setVector(const common::math::Vector3f & vec);
    common::math::Vector3f getVector() const;
    void setX(const float &x);
    void setY(const float &y);
    void setZ(const float &z);
    void setW(const float &w);

    Quaternion operator+(const Quaternion & quat);
    Quaternion operator-(const Quaternion & quat);
    Quaternion operator*(const float & scalar);
    Quaternion operator*(const Quaternion & quat);
    common::math::Vector3f operator*(const common::math::Vector3f & vec);
    Quaternion operator/(const Quaternion & quat);
    Quaternion getConjugate();
    Quaternion getNormalized();
    void toAxisAngle(Vector3f & axis, float & radians);
    void setAsIdentity();
    void normalize();



    common::math::Vector3f getRotatedVector(const common::math::Vector3f & vec);
    float * array();
    std::string toString();
    float getXRotation(); //pitch
    float getYRotation(); //yaw
    float getZRotation(); //roll

private:
    float m_values[4];
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_QUATERNION_H
