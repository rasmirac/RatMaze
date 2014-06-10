
/*
 CS142, Spring 2013
 Assignment 5
 Rachel Smith
*/


#include "RatMaze.h"

/*
 Function: ratMaze
 --------------------
 constructor
 takes in file name
 reads in first line as length
 "" second as width
 sets 2d array,theMaze,equal to contents
 returns nothing
*/

ratMaze::ratMaze(string filename)
{

    ifstream mazef(filename);
    mazef>>len;
    mazef>>wid;
        char ch;
        for (int i=0;i<len;i++)
        {
            for(int j=0;j<wid;j++)
            {
                mazef>>ch;
                if (ch=='R')
                {
                    rat.setL(i);
                    rat.setW(j);
                    theMaze[i][j]='.';
                }
                else if (ch=='C')
                {
                    cheese.setL(i);
                    cheese.setW(j);
                    theMaze[i][j]='.';
                }
                else
                    theMaze[i][j]=ch;
             
            }
        }
    mazef.close();
}

/*
 Function: goNorth
 --------------------
 checks boundaries around rat 
 and returns true if it can go
 north, false otherwise
 prints message if found cheese
*/

bool ratMaze::goNorth()
{
    if (rat.getL()==0||theMaze[rat.getL()-1][rat.getW()]=='#')
        return false;
    else
    {
        rat.decrementL();
        if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
            cout<<"You found the cheese!"<<endl;
    }
    return true;
}


/*
 Function: goSouth
 --------------------
 checks boundaries around rat
 and returns true if it can go
 south, false otherwise
 prints message if found cheese
*/

bool ratMaze::goSouth()
{
    if (rat.getL()==len-1||theMaze[rat.getL()+1][rat.getW()]=='#')
        return false;
    else
        {
            rat.incrementL();
            if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
                cout<<"You found the cheese!"<<endl;
        }
    return true;
}

/*
 Function: goEast
 --------------------
 checks boundaries around rat
 and returns true if it can go
 east, false otherwise
 prints message if found cheese
*/

bool ratMaze::goEast()
{
    if (rat.getW()==wid-1||theMaze[rat.getL()][rat.getW()+1]=='#')
        return false;
    else
    {
        rat.incrementW();
        if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
            cout<<"You found the cheese!"<<endl;
    }
    return true;
}

/*
 Function: goWest
 --------------------
 checks boundaries around rat
 and returns true if it can go
 west, false otherwise
 prints message if found cheese
*/

bool ratMaze::goWest()
{
    if (rat.getW()==0||theMaze[rat.getL()][rat.getW()-1]=='#')
        return false;
    else
    {
        rat.decrementW();
        if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
            cout<<"You found the cheese!"<<endl;
    }
    return true;
}

/*
 Function: northRat
 --------------------
 moves pt north and returns pt
 
*/

Point ratMaze::northRat(Point pt)
{
    pt.decrementL();
    return pt;
}

/*
 Function: southRat
 --------------------
 moves pt south and returns pt
 
*/

Point ratMaze::southRat(Point pt)
{
    pt.incrementL();
    return pt;
}

/*
 Function: eastRat
 --------------------
 moves pt east and returns pt
 
*/

Point ratMaze::eastRat(Point pt)
{
    pt.incrementW();
    return pt;
}

/*
 Function: westRat
 --------------------
 moves pt west and returns pt
 
*/

Point ratMaze::westRat(Point pt)
{
    pt.decrementW();
    return pt;
}

/*
 Function: moveCheese
 --------------------
 returns true if it is possible
 to move cheese to pt
 false otherwise
 
*/

bool ratMaze::moveCheese(Point pt)
{
    if (pt.getL()>=len||pt.getL()<0)
        return false;
    if (pt.getW()>=wid||pt.getW()<0)
        return false;
    if (theMaze[pt.getL()][pt.getW()]=='#')
        return false;
    else
    {
        cheese.setW(pt.getW());
        cheese.setL(pt.getL());
    }
    return true;
}

/*
 Function: moveRat
 --------------------
 returns true if it is possible
 to move rat to pt
 false otherwise
 
*/

bool ratMaze::moveRat(Point pt)
{
    if (pt.getL()>=len||pt.getL()<0)
        return false;
    if (pt.getW()>=wid||pt.getW()<0)
        return false;
    if (theMaze[pt.getL()][pt.getW()]=='#')
        return false;
    else
    {
        rat.setW(pt.getW());
        rat.setL(pt.getL());
    }
    return true;
}

/*
 Function: reset
 --------------------
 resets theMaze to maze contained
 in specified file
 
*/

void ratMaze::reset(string filename)
{
    ifstream mazef(filename);
    mazef>>len;
    mazef>>wid;
    char ch;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            mazef>>ch;
            if (ch=='R')
            {
                rat.setL(i);
                rat.setW(j);
                theMaze[i][j]='.';
            }
            else if (ch=='C')
            {
                cheese.setL(i);
                cheese.setW(j);
                theMaze[i][j]='.';
            }
            else
                theMaze[i][j]=ch;
        }
    }
}

/*
 Function: getRat
 --------------------
 returns pt corresponding to rat
 
*/

Point ratMaze::getRat() const
{
    return rat;
}

/*
 Function: getCheese
 --------------------
 returns pt corresponding to cheese
 
*/

Point ratMaze::getCheese() const
{
    return cheese;
}

/*
 Function: print
 --------------------
 prints maze with 'R' in 
 spot corresponding to pt.rat
 and 'C' in spot corresponding to 
 pt.cheese
 
*/

void ratMaze::print()
{
    cout<<endl;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<wid;j++)
        {
            if (cheese.getL()==i&&cheese.getW()==j)
            {
                if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
                    cout<<'&';
                else
                    cout<<'C';
            }
            else if (rat.getL()==i&&rat.getW()==j)
            {
                if (rat.getL()==cheese.getL()&&rat.getW()==cheese.getW())
                    cout<<'&';
                else
                    cout<<'R';
            }
            else
                cout<<theMaze[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
 Function: solveMaze
 --------------------
 creates new array that is 
 a copy of theMaze. calls 
 auxillary function solveAux
 prints out solution if it exist
 message indicating no solution if 
 not
 
 */

void ratMaze::solveMaze()
{
    char m[MAXSIZE][MAXSIZE];
    for (int i=0;i<len;i++)
    {
        for (int j=0;j<wid;j++)
        {
            m[i][j]=theMaze[i][j];
        }
    }
    bool isSolve(solveAux(getRat(), m));
    if (isSolve)
    {
        cout<<endl;
        cout<<"Here is a solution: "<<endl<<endl;
        for (int i=0;i<len;i++)
        {
            for(int j=0;j<wid;j++)
            {
                if (cheese.getL()==i&&cheese.getW()==j)
                    cout<<'C';
                else if (rat.getL()==i&&rat.getW()==j)
                    cout<<'R';
                else
                    cout<<m[i][j];
            }
            cout<<endl;
        }
    }
    else
        cout<<endl<<"This maze has no solution"<<endl;
}

/*
 Function: solveAux
 --------------------
 recursive function that solves maze 
 returns true if a solution is found
 false if not
 replaces maze copy with 'P''s indicating path
 
*/

bool ratMaze::solveAux(Point curr,char newM[][MAXSIZE])
{
    if (curr.getW()==cheese.getW()&&curr.getL()==cheese.getL())
        return true;
    if (curr.getW()<0||curr.getW()>=wid||curr.getL()<0||curr.getL()>=len)
        return false;
    if (newM[curr.getL()][curr.getW()]=='#')
        return false;
    if (newM[curr.getL()][curr.getW()]=='P')
        return false;
    //else
    newM[curr.getL()][curr.getW()]='P';
    if (solveAux(northRat(curr), newM))
        return true;
    if (solveAux(eastRat(curr), newM))
        return true;
    if (solveAux(southRat(curr), newM))
        return true;
    if (solveAux(westRat(curr), newM))
        return true;
    newM[curr.getL()][curr.getW()]='.'; 
    return false;
}   
