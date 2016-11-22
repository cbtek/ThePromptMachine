#ifndef _CBTEK_COMMON_MATH_NGON_H
#define _CBTEK_COMMON_MATH_NGON_H

#include "SimplePolygon.h"

#include "utility/inc/Exception.hpp"

#include <vector>

namespace cbtek {
namespace common {
namespace math {

CREATE_EXCEPTION(VertexOutOfBoundsException, "Vertex index is out of bounds")

class Ngon : public SimplePolygon
{
public:
    Ngon();

    const common::math::Vector3f & vertex(const size_t & index);

    const size_t vertexCount();

    void addVertex(const common::math::Vector3f & vertex);

    void setVertex(const size_t & index, const common::math::Vector3f & vertex);

    const bool contains(const common::math::Vector3f & point);
private:
    typedef std::vector<Vector3f> VertexVector;
     VertexVector m_vertices;
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_NGON_H
