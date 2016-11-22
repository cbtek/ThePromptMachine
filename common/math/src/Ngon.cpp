#include "Ngon.h"

namespace cbtek {
namespace common {
namespace math {

Ngon::Ngon()
{

}

const common::math::Vector3f &Ngon::vertex(const size_t &index)
{
    if (index<this->m_vertices.size())
    {
        return this->m_vertices[index];
    }
}

const size_t Ngon::vertexCount()
{
    return this->m_vertices.size();
}

void Ngon::addVertex(const Vector3f &vertex)
{
    this->m_vertices.push_back(vertex);
}

void Ngon::setVertex(const size_t &index, const Vector3f &vertex)
{
    if (index<this->m_vertices.size())
    {
          this->m_vertices[index]=vertex;
    }


}

const bool Ngon::contains(const Vector3f &point)
{

}

}}} //namespace
