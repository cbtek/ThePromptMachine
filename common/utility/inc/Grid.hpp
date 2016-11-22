#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <vector>

namespace cbtek {
namespace common {
namespace utility {

template<class T> class Grid
{
public:

    Grid()
    {
        this->m_initialized=false;
    }

    Grid(const Grid & grid);
    Grid & operator=(const Grid & grid);

    void initialize(const size_t rowCount=0, const size_t columnCount=0,const size_t tileHeight=0, const size_t tileWidth=0);
    void setCellData(const size_t & row, const size_t & column,const T & item);
    void setCellData(const size_t & index,const T & value);
    T getCellData(const size_t & row, const size_t & column)const;
    T getCellData(const size_t &index)const;

    T * getCellDataPtr(const size_t & row, const size_t & column);
    T * getCellDataPtr(const size_t &index);

    void addCellData(const T & value);
    size_t getX(const size_t & column)const;
    size_t getY(const size_t & row)const;
    size_t getRow(const size_t &yPos)const;
    size_t getColumn(const size_t & xPos)const;
    bool isValidRow(const size_t &row) const;
    bool isValidColumn(const size_t &column) const;
    bool isValidCell(const size_t &row, const size_t &column) const;
    bool isValid() const;
    size_t rowCount() const;
    size_t columnCount() const;
    size_t count() const;
    size_t tileWidth()const;
    size_t tileHeight() const;
    size_t width() const;
    size_t height() const;
    size_t setAllCellsEqualTo(const T & value);
    bool contains(const size_t & row, const size_t & column) const;
    const T * array() const;
    void clear();
private:
        size_t index(const size_t & row, const size_t & column) const;
        std::vector<T> m_cells;
        size_t m_tileW,m_tileH,m_rowCount,m_colCount,m_count;
        bool m_initialized;
        size_t m_addRowIndex;
        size_t m_addColumnIndex;
};

template<class T>
Grid<T>::Grid(const Grid &grid)
{
    this->initialize(grid.rowCount(),grid.columnCount(),grid.tileWidth(),grid.tileHeight());
    for (size_t a1=0;a1<grid.count();++a1)
    {
        this->setCellData(a1,grid.getCellData(a1));
    }
     this->m_initialized=true;
}

template<class T>
Grid<T> & Grid<T>::operator =(const Grid &grid)
{
    this->initialize(grid.rowCount(),grid.columnCount(),grid.tileWidth(),grid.tileHeight());
    for (size_t a1=0;a1<grid.count();++a1)
    {
        this->setCellData(a1,grid.getCellData(a1));
    }
    return *this;
}

template<typename T>
void Grid<T>::clear()
{
    this->m_cells.clear();
    this->m_rowCount=0;
    this->m_colCount=0;
    this->m_tileW = 0;
    this->m_tileH = 0;
    this->m_count = 0;
    this->m_initialized=false;
    this->m_addRowIndex=0;
    this->m_addColumnIndex=0;

}

template<class T>
void Grid<T>::initialize(const size_t rowCount, const size_t columnCount, const size_t tileHeight, const size_t tileWidth)
{
    this->m_cells.clear();
    this->m_rowCount=rowCount;
    this->m_colCount=columnCount;
    this->m_tileW = tileWidth;
    this->m_tileH = tileHeight;
    this->m_count = this->m_rowCount* this->m_colCount;
    this->m_cells.resize(this->m_count);
    this->m_initialized=true;
    this->m_addRowIndex=0;
    this->m_addColumnIndex=0;


}

template<class T>
void Grid<T>::setCellData(const size_t &row, const size_t &column, const T &item)
{
    size_t index=this->index(row,column);
    this->setCellData(index,item);
}

template<class T>
void Grid<T>::setCellData(const size_t &index, const T &value)
{
    if (index <this->m_count)
    {
        this->m_cells[index]=value;
    }
}

template<class T>
size_t Grid<T>::index(const size_t &row, const size_t &column)const
{
    return row * columnCount()+column;
}

template<class T>
size_t Grid<T>::tileHeight()const
{
    return m_tileH;
}

template<class T>
size_t Grid<T>::width() const
{
    return this->m_colCount * this->m_tileW;
}

template<class T>
size_t Grid<T>::height() const
{
    return this->m_rowCount*this->m_tileH;
}

template<class T>
size_t Grid<T>::setAllCellsEqualTo(const T &value)
{
    for (size_t a1=0;a1<this->m_cells.size();++a1)
    {
        this->m_cells[a1]=value;
    }
	return 0;
}

template<class T>
bool Grid<T>::contains(const size_t &row, const size_t &column) const
{
    return (row < this->m_rowCount && column < this->m_colCount);
}


template<class T>
const T *Grid<T>::array() const
{
    return this->m_cells.size()>0? &this->m_cells[0]:NULL;
}

template<class T>
size_t Grid<T>::tileWidth()  const
{
    return this->m_tileW;
}

template<class T>
size_t Grid<T>::count() const
{
    return this->m_count;
}

template<class T>
size_t Grid<T>::columnCount() const
{
    return m_colCount;
}

template<class T>
size_t Grid<T>::rowCount()  const
{
    return m_rowCount;
}

template<class T>
T Grid<T>::getCellData(const size_t &row, const size_t &column)const
{
    size_t index=this->index(row,column);
    return getCellData(index);
}

template<class T>
T * Grid<T>::getCellDataPtr(const size_t &row, const size_t &column)
{
    size_t index=this->index(row,column);
    return getCellDataPtr(index);
}

template<class T>
T * Grid<T>::getCellDataPtr(const size_t &index)
{
    return (index <this->m_count)?&m_cells[index]:NULL;
}

template<class T>
T Grid<T>::getCellData(const size_t &index)const
{
    return (index <this->m_count)?m_cells[index]:T();
}

template<class T>
void Grid<T>::addCellData(const T &value)
{
    if (this->m_addColumnIndex==this->m_colCount)
    {
        this->m_addColumnIndex=0;
        ++this->m_addRowIndex;
        if (this->m_addRowIndex==this->m_rowCount)
        {
            this->m_addRowIndex=0;
        }
    }
    this->setCellData(m_addRowIndex,m_addColumnIndex,value);
    ++this->m_addColumnIndex;
}

template<class T>
bool Grid<T>::isValid() const
{
    return this->m_initialized;
}

template<class T>
size_t Grid<T>::getY(const size_t &row) const
{
    return row*m_tileH;
}

template<class T>
size_t Grid<T>::getRow(const size_t &yPos) const
{
    if (m_tileH==0)return 0;
    return yPos/m_tileH;
}

template<class T>
size_t Grid<T>::getColumn(const size_t &xPos) const
{
    if (m_tileW==0)return 0;
    return xPos/m_tileW;
}


template<class T>
size_t Grid<T>::getX(const size_t &column) const
{
    return column*m_tileW;
}



template <class T>
bool Grid<T>::isValidRow(const size_t & row) const
{
    return (row >=0 && row < rowCount());
}

template <class T>
bool Grid<T>::isValidColumn(const size_t & column) const
{
    return (column >=0 && column < columnCount());
}

template <class T>
bool Grid<T>::isValidCell(const size_t & row,const size_t & column) const
{
    return isValidRow(row) && isValidColumn(column);
}

}}}//namespace
#endif // GRID_H

