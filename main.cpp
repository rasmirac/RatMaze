/*
 CS142, Spring 2013
 Assignment 5
 Rachel Smith
*/

#include "ratMaze.h"
#include "POINTER.h"

void printHeader();
void printChoices();
void choice1(ratMaze m);
void goDirection(char direction, ratMaze&m);
void choice4(ratMaze &m);
void choice5(ratMaze &m);


/*
 Function: main
 --------------------
 runs basic format for program
 prints header/choices
 calls functions for each answer choice
 checks choice
 returns: nothing
*/

int main()
{
	printHeader();
    ratMaze m("maze.txt");
    m.print();
    
    printChoices();
    int choice;
    cout<<"What do you want to do? ";
    cin>>choice;
    while (choice<1||choice>6)
    {
        cout<<"Invalid choice. Please enter a number between 1 and 6"<<endl;
        cout<<"Re-Enter choice: ";
        cin>>choice;
    }
    while (choice!=6)
    {
        if (choice==1)
            choice1(m);
        
        else if (choice==2)
            m.solveMaze();
        
        else if (choice==3)
        {
            string newFile;
            cout<<endl<<"What file do you want to use? ";
            cin>>newFile;
            m.reset(newFile);
            m.print();
        }
        
        else if (choice==4)
            choice4(m);
    
        else if (choice==5)
            choice5(m);
        
        printChoices();
        cout<<"What do you want to do? ";
        cin>>choice;
    }
    cout<<endl<<"GameOver"<<endl;
}

/*
 Function: printHeader
 --------------------
 prints header for game
 returns: nothing
 */
void printHeader()
{
    cout<<"Welcome to the game of RATMAZE!"<<endl<<endl;
    cout<<"Printed below is the maze. R represents the rat and "<<endl;
    cout<<"C represents the cheese."<<endl;
}

/*
 Function: printChoices
 --------------------
 prints choices for game
 returns: nothing
*/
void printChoices()
{
    cout<<endl;
    cout<<"Here are your choices: "<<endl;
    cout<<"1) Solve the maze yourself by moving the rat with the keyboard"<<endl;
    cout<<"2) Let the computer show you a solution to the maze"<<endl;
    cout<<"3) Load a new maze"<<endl;
    cout<<"4) Move the rat to a new location"<<endl;
    cout<<"5) Move the cheese to a new location"<<endl;
    cout<<"6) Quit"<<endl;
    cout<<endl;
}

/*
 Function: choice1
 --------------------
 takes in maze and prompts user
 for direction
 checks user's choice
 calls goDirection
 runs loop so user can continue
 moving rat
 returns nothing
 
*/

void choice1(ratMaze m)
{
    char direction;
    cout<<endl<<"You can move this rat around by entering u (up), n (down), "<<endl;
    cout<<"h (left), j (right), q (quit). "<<endl<<endl;
    
    m.print();
    cout<<"Where would you like to go? "<<endl;
    cin>>direction;
    while (direction!='u'&&direction!='n'&&direction!='h'&&direction!='j'&&direction!='q')
    {
        cout<<endl<<"Invalid choice. Please chose u, n, h, j, or q"<<endl;
        cout<<"Enter choice: ";
        cin>>direction;
    }
    while (direction!='q')
    {
        goDirection(direction,m);
        cout<<"u (up), n (down), h (left), j (right), q (quit)"<<endl<<endl; 
        cout<<"Which way now? ";
        cin>>direction;
    }
    cout<<endl<<"You have chosen to go back to the main menu."<<endl;
    return;
    
}

/*
 Function: goDirection
 --------------------
 moves rat in direction specified by
 user. replaces maze with new rat 
 location. 
 returns nothing.
*/

void goDirection(char direction,ratMaze&m)
{
    if (direction=='u')
    {
        if (m.goNorth())
            m.print();
        else
            cout<<"Sorry! You can't go that way!"<<endl<<endl;
    }
    else if (direction=='n')
    {
        if (m.goSouth())
            m.print();
        else
            cout<<"Sorry! You can't go that way!"<<endl<<endl;
    }
    else if (direction=='h')
    {
        if (m.goWest())
            m.print();
        else
            cout<<"Sorry! You can't go that way!"<<endl<<endl;
    }
    else if (direction=='j')
    {
        if (m.goEast())
            m.print();
        else
            cout<<"Sorry! You can't go that way!"<<endl;;
    }
}

/*
 Function: choice4
 --------------------
 takes in maze and puts rat 
 in new location using
 function moveRat from 
 ratmaze class
 checks coordinates
 prints new maze
*/

void choice4(ratMaze &m)
{
    m.print();
    Point pt;
    cout<<"Right now, the rat's position is ";
    (m.getRat()).print();
    cout<<endl;
    int w;
    cout<<endl<<"Enter a new x coordinate for the rat: ";
    cin>>w;
    pt.setW(w);
    int l;
    cout<<endl<<"Enter a new y coordinate for the rat: ";
    cin>>l;
    pt.setL(l);
    while (!(m.moveRat(pt)))
    {   cout<<endl<<"Sorry, ("<<w<<", "<<l<<") doesn't work."<<endl;
        cout<<endl<<"Enter new x coordinate: ";
        cin>>w;
        pt.setW(w);
        cout<<endl<<"Enter new y coordinate: ";
        cin>>l;
        pt.setL(l);
    }
    m.print();
}

/*
 Function: choice5
 --------------------
 takes in maze and puts cheese
 in new location using
 function moveCheese from
 ratmaze class
 checks coordinates
 prints new maze
*/

void choice5(ratMaze &m)
{
    m.print();
    Point pt;
    cout<<"Right now, the cheese's position is ";
    (m.getCheese()).print();
    cout<<endl;
    int w;
    cout<<endl<<"Enter x coordinate for the cheese: ";
    cin>>w;
    pt.setW(w);
    int l;
    cout<<endl<<"Enter y coordinate for the cheese: ";
    cin>>l;
    pt.setL(l);
    while (!(m.moveCheese(pt)))
    {   cout<<endl<<"Sorry, ("<<w<<", "<<l<<") doesn't work."<<endl<<endl;
        cout<<endl<<"Enter new x coordinate: ";
        cin>>w;
        pt.setW(w);
        cout<<endl<<"Enter new y coordinate: ";
        cin>>l;
        pt.setL(l);
    }
    m.print();
}

