#ifndef _CBTEK_COMMON_MATH_SIMPLEPOLYGON_H
#define _CBTEK_COMMON_MATH_SIMPLEPOLYGON_H

#include "Vector3.hpp"


namespace cbtek {
namespace common {
namespace math {

class SimplePolygon
{
public:
    virtual const common::math::Vector3f & vertex(const size_t & index)=0;

    virtual const size_t vertexCount()=0;

    virtual void addVertex(const common::math::Vector3f & vertex)=0;

    virtual void setVertex(const size_t & index, const common::math::Vector3f & vertex)=0;

    virtual const bool contains(const common::math::Vector3f & point)=0;

};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_SIMPLEPOLYGON_H
