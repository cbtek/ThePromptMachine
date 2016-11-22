#include "Quaternion.h"
#include "Vector3.hpp"

#include <sstream>


namespace cbtek {
namespace common {
namespace math {

Quaternion::Quaternion()
{
    this->set(0,0,0,0);
}

Quaternion::Quaternion(const float &x, const float &y, const float &z, const float &w)
{
    this->set(x,y,z,w);
}

Quaternion::Quaternion(const Vector3f &vec)
{
    this->set(vec.getX(),vec.getY(),vec.getZ(),0);
}

Quaternion::Quaternion(const Vector3f &axis, const float &radians)
{
    Vector3f returnVector=axis;
    returnVector.normalize();
    float sinAngle = std::sin(radians*0.5);
    this->set(returnVector.getX()*sinAngle,returnVector.getY()*sinAngle,returnVector.getZ()*sinAngle,std::cos(radians));

}


Quaternion::Quaternion(const Quaternion &quat)
{
    this->setVector(quat.getVector());
    this->setW(quat.getW());
}

Quaternion::Quaternion(const Matrix &matrix)
{
    if (matrix.columns()>2 && matrix.rows()>2)
    {

        float m11,m22,m33,m12,m13,m21,m23,m31,m32;
        m11=matrix.getValue(0,0);
        m12=matrix.getValue(0,1);
        m13=matrix.getValue(0,2);
        m21=matrix.getValue(1,0);
        m22=matrix.getValue(1,1);
        m23=matrix.getValue(1,2);
        m31=matrix.getValue(2,0);
        m32=matrix.getValue(2,1);
        m33=matrix.getValue(2,2);

        float trace = m11+m22+m33;
        if (trace>0)
        {
            float t=(1/(2*std::sqrt(trace+1)));
            this->set((m23-m32)*t,(m31-m13)*t,(m12-m21)*t,0.25/t);
        }
        else
        {
            if (m11 > m22 && m11 > m33)
            {

                float t=(1/(2*std::sqrt(1+(m11-m22+m33))));
                this->set((m21-m12)*t,(m13-m31)*t,(m32-m23)*t,0.25/t);

            }
            else if (m22 > m11 && m22 > m33)
            {
                float t=(1/(std::sqrt(1+(m22-m11-m33))));
                this->set(0.25/t,(m32-m23)*t,(m13-m31)*t,(m21-m12)*t);

            }
            else
            {
                float t=(1/(std::sqrt(1+(m33-m11-m22))));
                this->set((m32-m23)*t,0.25/t,(m21-m12)*t,(m13-m31)*t);
            }
        }
    }
}

Quaternion::Quaternion(const float &axisAngleX, const float &axisAngleY, const float &axisAngleZ)
{
    float p=axisAngleX;
    float y=axisAngleY;
    float r=axisAngleZ;
    float sinp = std::sin(p);
    float siny = std::sin(y);
    float sinr = std::sin(r);
    float cosp = std::cos(p);
    float cosy = std::cos(y);
    float cosr = std::cos(r);
    setX(sinr * cosp * cosy - cosr * sinp * siny);
    setY(cosr * sinp * cosy + sinr * cosp * siny);
    setZ(cosr * cosp * siny - sinr * sinp * cosy);
    setW(cosr * cosp * cosy + sinr * sinp * siny);
    this->normalize();
}

Quaternion &Quaternion::operator =(const Quaternion &quat)
{
    this->setVector(quat.getVector());
    this->setW(quat.getW());
    return *this;
}

void Quaternion::setVector(const Vector3f &vec)
{
    this->m_values[0]=vec.getX();
    this->m_values[1]=vec.getY();
    this->m_values[2]=vec.getZ();
}

Vector3f Quaternion::getVector() const
{
    return common::math::Vector3f(this->getX(),this->getY(),this->getZ());
}


void Quaternion::set(const float &x, const float &y, const float &z, const float & w)
{
    this->m_values[0]=x;
    this->m_values[1]=y;
    this->m_values[2]=z;
    this->m_values[3]=w;
}

float Quaternion::getX() const
{
    return this->m_values[0];
}

float Quaternion::getY() const
{
    return this->m_values[1];
}

float Quaternion::getZ() const
{
    return this->m_values[2];
}

float Quaternion::getW() const
{
    return this->m_values[3];
}

void Quaternion::setX(const float &x)
{
    this->m_values[0]=x;
}

void Quaternion::setY(const float &y)
{
    this->m_values[1]=y;
}

void Quaternion::setZ(const float &z)
{
    this->m_values[2]=z;
}

void Quaternion::setW(const float &w)
{
    this->m_values[3]=w;
}

Quaternion Quaternion::operator +(const Quaternion &quat)
{
    return Quaternion(quat.getX()+getX(),quat.getY()+getY(),quat.getZ()+getZ(),quat.getW()+getW());
}

Quaternion Quaternion::operator -(const Quaternion &quat)
{

    return Quaternion(getX()-quat.getX(),getY()-quat.getY(),getZ()-quat.getZ(),quat.getW()+getW());
}

float *Quaternion::array()
{
    return this->m_values;
}

Quaternion Quaternion::operator *(const float &scalar)
{
    return Quaternion(getX()*scalar,getY()*scalar,getZ()*scalar,getW()*scalar);
}

Quaternion Quaternion::operator *(const Quaternion &quat)
{
    return Quaternion(getW() * quat.getX() + getX() * quat.getW() + getY() * quat.getZ() - getZ() * quat.getY(),
                      getW() * quat.getY() + getY() * quat.getW() + getZ() * quat.getX() - getX() * quat.getZ(),
                      getW() * quat.getZ() + getZ() * quat.getW() + getX() * quat.getY() - getY() * quat.getX(),
                      getW() * quat.getW() - getX() * quat.getX() - getY() * quat.getY() - getZ() * quat.getZ());

}

Vector3f Quaternion::operator *(const Vector3f &vec)
{
    Vector3f returnVector=vec;
    returnVector=returnVector.getNormalized();
    Quaternion vecQuat(returnVector,0), resQuat;
    resQuat = vecQuat * this->getConjugate();
    resQuat = *this * resQuat;
    return (Vector3f(resQuat.getX(), resQuat.getY(), resQuat.getZ()));
}

Quaternion Quaternion::operator /(const Quaternion &quat)
{
    if (quat.getX()!=0 && quat.getY()!=0 && quat.getZ()!=0 && quat.getW()!=0)
    {
        return Quaternion(getX()/quat.getX(),getY()/quat.getY(),getZ()/quat.getZ(),getW()/quat.getW());
    }
    return Quaternion();
}

Quaternion Quaternion::getConjugate()
{
    Quaternion q(*this);
    q.set(this->getX()*-1,this->getY()*-1,this->getZ()*-1,this->getW());
    return q;
}

void Quaternion::normalize()
{
    float mag = std::sqrt((getW() * getW()) + (getX() * getX()) + (getY() * getY()) + (getZ() * getZ()));
    if (mag!=0)
    {
        this->set(getX()/mag,getY()/mag,getZ()/mag,getW()/mag);
    }
}

Quaternion Quaternion::getNormalized()
{
    float mag = std::sqrt((getW() * getW()) + (getX() * getX()) + (getY() * getY()) + (getZ() * getZ()));
    if (mag!=0)
    {
        return Quaternion(getX()/mag,getY()/mag,getZ()/mag,getW()/mag);
    }
    return Quaternion();
}

void Quaternion::toAxisAngle(Vector3f &axis, float & radians)
{
    // Converts this quaternion to an axis and an angle
    float sinHalfThetaSq = 1.0f - getW() * getW();

    // Guard against numerical imprecision and identity quaternions.
    if (sinHalfThetaSq <= 0.0f)
    {
        axis.set(1,0,0);
        radians = 0.0f;
    }
    else
    {
        float invSinHalfTheta = 1.0f / std::sqrt(sinHalfThetaSq);
        axis.set(getX()*invSinHalfTheta,getY()*invSinHalfTheta,getZ()*invSinHalfTheta);
        radians = (2.0f * std::cos(getW()));
    }
}

void Quaternion::setAsIdentity()
{
    this->set(0,0,0,1);
}

std::string Quaternion::toString()
{
    std::ostringstream out;
    out << "X:"<<this->m_values[0]<<" Y:"<<this->m_values[1]<<" Z:"<<this->m_values[2]<<" W:"<<this->m_values[3];
    return out.str();
}

float Quaternion::getXRotation()
{
    return std::atan2(2*(getY()*getZ() + getW()*getX()), getW()*getW() - getX()*getX() - getY()*getY() + getZ()*getZ());
}

float Quaternion::getYRotation()
{
    return std::asin(-2*(getX()*getZ() - getW()*getY()));
}

float Quaternion::getZRotation()
{
    return std::atan2(2*(getX()*getY() + getW()*getZ()), getW()*getW() + getX()*getX() - getY()*getY() - getZ()*getZ());
}

Vector3f Quaternion::getRotatedVector(const Vector3f &vec)
{
    Vector3f returnVector=vec;
    returnVector=(this->getConjugate() * ((*this)*returnVector));
    return returnVector;
}




}}} //namespace

