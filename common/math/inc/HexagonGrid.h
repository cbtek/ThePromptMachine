#ifndef _CBTEK_COMMON_MATH_HEXAGONGRID_H
#define _CBTEK_COMMON_MATH_HEXAGONGRID_H

#include "Hexagon.h"

#include <cstdlib>


namespace cbtek {
namespace common {
namespace math {


class HexagonGrid
{
public:
    HexagonGrid();
    HexagonGrid(const int &rows, const int & columns,const int & width=4, const int & height=4);
    void initialize(const int &rows, const int & columns,const int & width=4, const int & height=4);
    const common::math::Hexagon * getHexagon(const size_t & index);
    const common::math::Hexagon * getHexagon(const size_t & row,const size_t & column);
    const size_t getCount();
    const size_t rowCount();
    const size_t columnCount();

private:
    size_t m_count,m_rowCount,m_colCount;
    common::math::Hexagon * m_grid;
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_HEXAGONGRID_H
