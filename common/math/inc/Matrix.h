#ifndef _CBTEK_COMMON_MATH_MATRIX_H
#define _CBTEK_COMMON_MATH_MATRIX_H

#include <cstdlib>
#include <string>
#include <cmath>

#include "utility/inc/Grid.hpp"

#include "Vector3.hpp"


namespace cbtek {
namespace common {
namespace math {


class Matrix
{
public:

    Matrix();
    Matrix(size_t rows, size_t columns);
    Matrix(const Matrix & matrix);
    Matrix(const common::math::Vector3f & vector, const size_t defaultRowSize=3);
    Matrix(size_t rows, size_t columns, const std::vector<double> & values);
    Matrix & operator=(const Matrix & matrix);
    Matrix operator+(const Matrix & matrix);
    Matrix operator-(const Matrix & matrix);
    Matrix operator*(const float & scalar);
    Matrix operator*(const Matrix & scalar);
    common::math::Vector3f operator*(const common::math::Vector3f & vec);
    Matrix & operator<<(const float & value);


    float getDeterminate();
    float getInverse();
    Matrix getTransposed();
    float getValue(const size_t & rowIndex, const size_t & columnIndex)const;
    void setValue(const size_t & rowIndex, const size_t & columnIndex, const float & value);
    void setValues(const std::vector<double>& values);
    void initialize(const size_t &rows, const size_t &columns, const float &value=0.0f);
    size_t size()const;
    size_t rows()const;
    size_t columns()const;
    bool isValid()const;
    std::string toString();
    void setAsIdentity();
    std::vector<double> getValues() const;
    const double *array() const;
protected:
    common::utility::Grid<double> m_cells;
};
}}} //namespace
#endif // _CBTEK_COMMON_MATH_MATRIX_H
