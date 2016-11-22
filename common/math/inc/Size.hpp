//!  Short description for Size
/*!
     Detailed description for Size
*/

#ifndef _CBTEK_COMMON_MATH_SIZE
#define _CBTEK_COMMON_MATH_SIZE

#include <cinttypes>

namespace cbtek {
namespace common {
namespace math {

template<typename T>
class Size 
{
	public:	
    Size(T w=0., T h=0.);
    T getW() const;
    T getH() const;
    void setW(T w);
    void setH(T h);
    void incrementW(T dw);
    void incrementH(T dh);
    void resize(T w, T h);
    private:
    T m_w,m_h;
};


template <typename T>
Size<T>::Size(T w, T h)
{
    resize(w,h);
}

template <typename T>
T Size<T>::getW() const
{
    return m_w;
}

template <typename T>
T Size<T>::getH() const
{
    return m_h;
}

template <typename T>
void Size<T>::setW(T w)
{
    m_w=w;
}

template <typename T>
void Size<T>::setH(T h)
{
    m_h=h;
}

template <typename T>
void Size<T>::incrementW(T dw)
{
    m_w+=dw;
}

template <typename T>
void Size<T>::incrementH(T dh)
{
    m_h+=dh;
}

template <typename T>
void Size<T>::resize(T w, T h)
{
    m_w=w;
    m_h=h;
}

typedef Size<std::int64_t> Size2i;
typedef Size<double>Size2d;
typedef Size<float>Size2f;
}}}//end namespace
#endif //_CBTEK_COMMON_MATH_SIZE

