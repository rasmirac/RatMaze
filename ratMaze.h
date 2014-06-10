/*
 CS142, Spring 2013
 Assignment 5
 Rachel Smith
*/


#include "POINTER.h"
#include <iostream>
#include <fstream>
using namespace std;


const int MAXSIZE=1000;

class ratMaze
{
public:
    //constructor
    ratMaze(string filename);
    
    //mutators
    bool goNorth();
    bool goSouth();
    bool goEast();
    bool goWest();
    Point northRat(Point pt);
    Point southRat(Point pt);
    Point eastRat(Point pt);
    Point westRat(Point pt);
    bool moveCheese(Point pt);
    bool moveRat(Point pt);
    void reset(string filename);
    
    //accessors
    Point getCheese() const;
    Point getRat() const;
    void print();
    void solveMaze(); 
    bool solveAux(Point curr,char newM[][MAXSIZE]);

    
private:
	Point rat,cheese;
	int len,wid;
	char theMaze[MAXSIZE][MAXSIZE]; 
};



