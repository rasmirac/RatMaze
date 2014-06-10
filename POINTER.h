/*
 CS142, Spring 2013
 Assignment 5
 Rachel Smith
*/

#include <iostream>
using namespace std;

#ifndef POINT_H
#define POINT_H


class Point
{
    
public:
	Point(int myl=0, int myw=0);
	
	//accessors
	int getL() const;
	int getW() const;
    
	//mutators
	void setL(int newL);
	void setW(int newW);
	
	void incrementL(); 
	void decrementL();
	void incrementW();
	void decrementW();
	
	void print(); 
    
    
private:
	int w, l;

};

#endif
