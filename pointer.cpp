/*
 CS142, Spring 2013
 Assignment 5
 Rachel Smith
*/

#include "POINTER.h"

Point::Point(int myl, int myw)
{
    l=myl;
    w=myw;
}

/*
 Function: getW
 --------------------
 returns w (x coord of point)
*/

int Point::getW() const
{
    return w;
}

/*
 Function: getL
 --------------------
 returns l (y coord)
*/

int Point::getL() const
{
    return l;
}

/*
 Function: getL
 --------------------
 sets y coord of point 
 to newL
*/
void Point::setL(int newL)
{
    l=newL;
}

/*
 Function: getW
 --------------------
 sets x coord of point
 to newW
*/

void Point::setW(int newW)
{
    w=newW;
}

/*
 Function: incrementL
 --------------------
 adds one to l
*/

void Point::incrementL()
{
    l+=1;
}

/*
 Function: decrementL
 --------------------
 subtracts one from l
*/

void Point::decrementL()
{
    l-=1;
}

/*
 Function: incrementW
 --------------------
 adds one to w
*/

void Point::incrementW()
{
    w+=1;
}

/*
 Function: decrementW
 --------------------
 subtracts one from w
*/

void Point::decrementW()
{
    w-=1;
}

/*
 Function: print
 --------------------
 prints (l,w)
*/

void Point::print()
{
    cout<<w<<", "<<l;
}

