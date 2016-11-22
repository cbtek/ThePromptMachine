#include "HexagonGrid.h"

namespace cbtek {
namespace common {
namespace math {

HexagonGrid::HexagonGrid()
{
}

HexagonGrid::HexagonGrid(const int &rows, const int &columns, const int & width, const int & height)
{
    this->initialize(rows,columns);
}

void HexagonGrid::initialize(const int &rows, const int &columns,const int & width, const int & height)
{
    this->m_colCount=columns;
    this->m_rowCount=rows;
    this->m_count=rows*columns;
    this->m_grid = new common::math::Hexagon [m_count];

    size_t shiftX=0;
    for (size_t y = 0;y<(size_t)rows;++y)
    {
        for (size_t x = 0;x<(size_t)columns;++x)
        {
            size_t index = x*rows+y;
            shiftX=(y % 2)?0:(width/2) ;
            this->m_grid[index].setBounds(shiftX+(x*width),(y*((height/2)+(height/4))),width,height);
        }
    }
}

const common::math::Hexagon *HexagonGrid::getHexagon(const size_t &index)
{
    return (index<this->m_count)?&this->m_grid[index]:0;
}

const common::math::Hexagon *HexagonGrid::getHexagon(const size_t &row, const size_t &column)
{
    size_t index = column * this->m_rowCount+row;
    return this->getHexagon(index);
}

const size_t HexagonGrid::getCount()
{
    return this->m_count;
}

const size_t HexagonGrid::rowCount()
{
    return this->m_rowCount;
}

const size_t HexagonGrid::columnCount()
{
    return this->m_colCount;
}
}}} //namespace
