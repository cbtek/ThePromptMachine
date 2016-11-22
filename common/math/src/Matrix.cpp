#include "Matrix.h"

#include <sstream>
#include <iostream>

namespace cbtek {
namespace common {
namespace math {


Matrix::Matrix()
{
}

Matrix::Matrix(size_t rows, size_t columns)
{
    this->initialize(rows,columns);
}

Matrix::Matrix(const Matrix &matrix)
{
    this->initialize(matrix.rows(),matrix.columns());
    this->setValues(matrix.getValues());
}

Matrix::Matrix(const Vector3f &vec,const size_t defaultRowSize)
{
    this->initialize(defaultRowSize,1);
    this->setValue(0,0,vec.getX());
    this->setValue(1,0,vec.getY());
    this->setValue(2,0,vec.getZ());

    //fill rest of vector matrix with one of it is greater than a 3x1 matrix
    for (size_t a1=3;a1<defaultRowSize;++a1)
    {
        this->setValue(a1,0,1);
    }
}

Matrix::Matrix(size_t rows, size_t columns, const std::vector<double> &values)
{
    this->initialize(rows,columns);
    this->setValues(values);
}

Matrix &Matrix::operator =(const Matrix &matrix)
{
    this->initialize(matrix.rows(),matrix.columns());
    this->setValues(matrix.getValues());
	return (*this);
}

Matrix Matrix::operator +(const Matrix &matrix)
{
    Matrix newMatrix;
    if (this->size()!=matrix.size())
    {
        return newMatrix;
    }
    newMatrix.initialize(this->rows(),this->columns());
    for(size_t r=0;r<matrix.rows();++r)
    {
        for (size_t c=0;c<matrix.columns();++c)
        {
            newMatrix.setValue(r,c,this->getValue(r,c)+matrix.getValue(r,c));
        }
    }
    return newMatrix;
}

Matrix Matrix::operator -(const Matrix &matrix)
{
    Matrix newMatrix;
    if (this->size()!=matrix.size())
    {
        return newMatrix;
    }
    newMatrix.initialize(this->rows(),this->columns());
    for(size_t r=0;r<matrix.rows();++r)
    {
        for (size_t c=0;c<matrix.columns();++c)
        {
            newMatrix.setValue(r,c,this->getValue(r,c)-matrix.getValue(r,c));
        }
    }
    return newMatrix;

}

Matrix Matrix::operator *(const float &scalar)
{
    Matrix newMatrix;
    newMatrix.initialize(this->rows(),this->columns());
    for(size_t r=0;r<rows();++r)
    {
        for (size_t c=0;c<columns();++c)
        {
            newMatrix.setValue(r,c,this->getValue(r,c)*scalar);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator *(const Matrix &matrix)
{
    Matrix newMatrix;

    //check for comformability
    if (this->columns()!=matrix.rows())
    {
        return newMatrix;
    }

    newMatrix.initialize(matrix.rows()>rows()?matrix.rows():rows(),
                         matrix.columns()>columns()?matrix.columns():columns());

    std::vector<double> values;
    for (size_t r1=0;r1<this->rows();++r1)
    {

        for (size_t c2=0;c2<matrix.columns();++c2)
        {
            float value=0.0f;
            for (size_t r2=0;r2<matrix.rows();++r2)
            {
                value+=this->getValue(r1,r2)*matrix.getValue(r2,c2);
            }
            values.push_back(value);
        }

    }

    newMatrix.setValues(values);
    std::cerr<<newMatrix.getValues()[0]<<"\n";
    return newMatrix;
}

common::math::Vector3f Matrix::operator *(const common::math::Vector3f & vec)
{
    Matrix matrix(vec,this->rows());
    matrix=this->operator *(matrix);
    if (matrix.columns()>=3)
    {
        return common::math::Vector3f(matrix.getValue(0,0),matrix.getValue(0,1),matrix.getValue(0,2));
    }
    return common::math::Vector3f();
}

Matrix &Matrix::operator <<(const float &value)
{
    this->m_cells.addCellData(value);
    return *this;
}

float Matrix::getDeterminate()
{
    for(size_t r=0;r<rows();++r)
    {
        for (size_t c=0;c<columns();++c)
        {
          std::pow(-1.0,c+r);
        }
    }
	return 0.;
}

float Matrix::getInverse()
{
return 0.;
}

Matrix Matrix::getTransposed()
{
    Matrix matrix;
    matrix.initialize(columns(),rows());
    for(size_t r=0;r<rows();++r)
    {
        for (size_t c=0;c<columns();++c)
        {
            matrix.setValue(c,r,this->getValue(r,c));
        }
    }
    return matrix;
}
void Matrix::setValue(const size_t & rowIndex, const size_t & columnIndex, const float & value)
{
    this->m_cells.setCellData(rowIndex,columnIndex,value);
}

void Matrix::setValues(const std::vector<double> &values)
{
    for (size_t a1=0;a1<values.size();++a1)
    {
        this->m_cells.addCellData(values[a1]);
    }
}

float Matrix::getValue(const size_t &rowIndex, const size_t &columnIndex) const
{
    return (rowIndex<this->rows() && columnIndex<this->columns())?m_cells.getCellData(rowIndex,columnIndex):0.0f;
}

void Matrix::initialize(const size_t &rows, const size_t &columns, const float &value)
{
    this->m_cells.initialize(rows,columns);
    this->m_cells.setAllCellsEqualTo(value);

}

size_t Matrix::size() const
{
    return this->m_cells.count();
}

size_t Matrix::rows() const
{
    return this->m_cells.rowCount();
}

size_t Matrix::columns() const
{
    return this->m_cells.columnCount();
}

bool Matrix::isValid() const
{
    return this->m_cells.isValid();
}

std::string Matrix::toString()
{
    std::ostringstream out;
    for(size_t r=0;r<rows();++r)
    {
        for (size_t c=0;c<columns();++c)
        {
            out<<this->m_cells.getCellData(r,c)<<" ";
        }
        out<<"\n";
    }
    return out.str();
}

void Matrix::setAsIdentity()
{
    if (this->rows()!=this->columns())
    {
        return;
    }

    for (size_t a1=0;a1<this->rows();++a1)
    {
        this->m_cells.setCellData(a1,a1,1);
    }

}

std::vector<double> Matrix::getValues() const
{
    std::vector<double> values;
    for(size_t r=0;r<rows();++r)
    {
        for (size_t c=0;c<columns();++c)
        {
            values.push_back(this->m_cells.getCellData(r,c));
        }
    }
    return values;
}

const double *Matrix::array() const
{
    return this->m_cells.array();
}
}}} //namespace
