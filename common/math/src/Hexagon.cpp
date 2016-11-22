#include "Hexagon.h"


namespace cbtek {
namespace common {
namespace math {


Hexagon::Hexagon(const int &x, const int &y, const int &width, const int &height)
{
    this->move(x,y);
    this->resize(width,height);
}

const Line2i *Hexagon::getSide(const int & index)const
{
    return index>=0 && index<6 ? &this->m_sides[index]:0;
}

const int Hexagon::x() const
{
    return this->m_quad.getX();
}

const int Hexagon::y() const
{
    return this->m_quad.getY();
}

const int Hexagon::w() const
{
    return this->m_quad.getW();
}

const int Hexagon::h() const
{
    return this->m_quad.getH();
}

void Hexagon::move(const int &x, const int &y)
{
    this->m_quad.setPosition(x,y);
    this->update();
}

void Hexagon::resize(const int &w, const int &h)
{
    this->m_quad.setSize(w,h);
    this->update();
}

void Hexagon::setBounds(const int &x, const int &y, const int &w, const int &h)
{
    this->m_quad.set(x,y,w,h);
    this->update();
}


const bool Hexagon::contains(const int &x, const int &y) const
{
    Quad<std::int64_t> quad(this->m_sides[5].getX1(),this->m_sides[5].getY1(),this->w(),this->m_sides[4].getY1()-this->m_sides[5].getY1());


    if (quad.contains(x,y))
    {

        return true;
    }
    else
    {
        int x1 = this->m_sides[5].getX1();
        int y1 = this->m_sides[5].getY1();

        int x2 = this->m_sides[0].getX1();
        int y2 = this->m_sides[0].getY1();

        int x3 = this->m_sides[1].getX1();
        int y3 = this->m_sides[1].getY1();


        if (common::math::MathUtils::pointExistsInTriangle2i(x,y,x1,y1,x2,y2,x3,y3))
        {


            return true;
        }
        else
        {
            x1 = this->m_sides[2].getX1();
            y1 = this->m_sides[2].getY1();

            x2 = this->m_sides[3].getX1();
            y2 = this->m_sides[3].getY1();

            x3 = this->m_sides[4].getX1();
            y3 = this->m_sides[4].getY1();

            if (common::math::MathUtils::pointExistsInTriangle2i(x,y,x1,y1,x2,y2,x3,y3))
            {
                return true;
            }
            else return false;
        }
    }
    return false;
}

const bool Hexagon::intersects(const int &x, const int &y) const
{
//    for (int a1 = 0;a1<6;++a1)
//    {
//        if (this->m_sides[a1].contains(x,y))
//        {
//            return true;
//        }
//    }
    return false;
}

void Hexagon::update()
{
    int halfW=this->w()/2;
    //int quarterW =this->w()/4;
    int halfH=this->h()/2;
    int quarterH =this->h()/4;

    this->m_sides[0].set(this->x(),this->y()-halfH ,this->x()+halfW,this->y()-quarterH);
    this->m_sides[1].set(this->x()+halfW,this->y()-quarterH,this->x()+halfW,this->y()+quarterH);
    this->m_sides[2].set(this->x()+halfW,this->y()+quarterH,this->x(),this->y()+halfH );
    this->m_sides[3].set(this->x(),this->y()+halfH,this->x()-halfW,this->y()+quarterH );
    this->m_sides[4].set(this->x()-halfW,this->y()+quarterH, this->x()-halfW,this->y()-quarterH );
    this->m_sides[5].set(this->x()-halfW,this->y()-quarterH ,this->x(),this->y()-halfH );
    }

}}} //namespace
