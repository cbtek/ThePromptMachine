//#-------------------------------------------------
//#
//# File Line.h created by shadowefusion on 04-09-2014 at 10:21:42 PM
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_MATH_LINE
#define _CBTEK_COMMON_MATH_LINE


namespace cbtek {
namespace common {
namespace math {


template <typename T>
class Line3
{

public:
	Line3(T x1=0, T y1=0, T z1=0, T x2=0, T y2=0, T z2=0);

	void set(T x1, T y1, T z1, T x2,T y2, T z2);
	
	T getX1() const;
	void setX1(const T & x1);

	T getX2() const;
	void setX2(const T & x2);

	T getY1() const;
	void setY1(const T & y1);

	T getY2() const;
	void setY2(const T & y2);

    T getZ1() const;
    void setZ1(const T & z1);

    T getZ2() const;
    void setZ2(const T & z2);

private:
	T m_x1;
	T m_x2;
	T m_y1;
	T m_y2;
    T m_z1;
    T m_z2;

protected:

};
template <typename T> T Line3<T>::getX1() const
{
    return m_x1;
}
template <typename T> T Line3<T>::getY1() const
{
    return m_y1;
}
template <typename T> T Line3<T>::getZ1() const
{
    return m_z1;
}

template <typename T> T Line3<T>::getX2() const
{
    return m_x2;
}
template <typename T> T Line3<T>::getY2() const
{
    return m_y2;
}
template <typename T> T Line3<T>::getZ2() const
{
    return m_z2;
}
template <typename T> void Line3<T>::setX1(const T & value)
{
    m_x1=value;
}
template <typename T> void Line3<T>::setY1(const T & value)
{
    m_y1=value;
}
template <typename T> void Line3<T>::setZ1(const T & value)
{
    m_z1=value;
}
template <typename T> void Line3<T>::setX2(const T & value)
{
    m_x2=value;
}
template <typename T> void Line3<T>::setY2(const T & value)
{
    m_y2=value;
}
template <typename T> void Line3<T>::setZ2(const T & value)
{
    m_z2=value;
}

template <typename T>
Line3<T>::Line3(T x1, T y1, T z1, T x2,T y2, T z2)
{
	m_x1=x1;
	m_x2=x2;
	m_y1=y1;
	m_y2=y2;
	m_z1=z1;
	m_z2=z2;
}

template <typename T>
void Line3<T>::set(T x1, T y1, T z1, T x2,T y2, T z2)
{
	m_x1=x1;
	m_x2=x2;
	m_y1=y1;
	m_y2=y2;
	m_z1=z1;
	m_z2=z2;
}

template <typename T>
class Line2
{

public:
	Line2(T x1=0, T y1=0, T x2=0, T y2=0);

	void set(T x1, T y1, T x2, T y2);
	
	T getX1() const;
	void setX1(const T & x1);

	T getX2() const;
	void setX2(const T & x2);

	T getY1() const;
	void setY1(const T & y1);

	T getY2() const;
	void setY2(const T & y2);

private:
	T m_x1;
	T m_x2;
	T m_y1;
	T m_y2;

protected:

};


template <typename T>
Line2<T>::Line2(T x1, T y1, T x2, T y2)
{
	m_x1=x1;
	m_x2=x2;
	m_y1=y1;
	m_y2=y2;
}

template <typename T>
void Line2<T>::set(T x1, T y1, T x2, T y2)
{
	m_x1=x1;
	m_x2=x2;
	m_y1=y1;
	m_y2=y2;
}
	
template <typename T> T Line2<T>::getX1() const
{
    return m_x1;
}
template <typename T> T Line2<T>::getY1() const
{
    return m_y1;
}
template <typename T> T Line2<T>::getX2() const
{
    return m_x2;
}
template <typename T> T Line2<T>::getY2() const
{
    return m_y2;
}
template <typename T> void Line2<T>::setX1(const T & value)
{
    m_x1=value;
}
template <typename T> void Line2<T>::setY1(const T & value)
{
    m_y1=value;
}
template <typename T> void Line2<T>::setX2(const T & value)
{
    m_x2=value;
}
template <typename T> void Line2<T>::setY2(const T & value)
{
    m_y2=value;
}

typedef Line2<double> Line2f;
typedef Line2<int> Line2i;
}}} //namespace
#endif //_CBTEK_COMMON_MATH_LINE
