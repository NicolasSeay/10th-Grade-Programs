#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
//#include "H:\C++ Programs\myHeader.h"

using namespace std;

int movecounter=0;
COORD coord={0,0};

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

class disc{
    private:
        int data;
        disc*next;
    public:
        disc(int d, disc*n){
            data=d;
            next=n;
        }
        int getData(){
            return(data);
        }
        void setNext(disc*n){
            next=n;
        }
        disc* getNext(){
            return(next);
        }
};

/// stack of disks
class stack{
    private:
        disc* top;
    public:
        stack(){
            /// pegs start with no disc
            top=NULL;
        }
        /// print the discs just in this stack
        void print(){
            disc* holder=getTop();
            while ( holder != NULL ){
                cout<<holder->getData();
                holder=holder->getNext();
            }
            cout<<endl;
        }


        /// insert 1 disc of given size on top of stack
        /// x = disc size
        void insert(int x){
            disc* oldTop=top;

            if(top == NULL){
                top=new disc(x, NULL);
            }
            else{
                disc* newTop=new disc(x, oldTop);
                top = newTop;
            }
        }
        /// pop top disc from stack
        void remove(){
            disc* next=top;
            if(top->getNext() == NULL){
                top=NULL;
            }
            else{
                top=top->getNext();
            }
            cout<<endl;
        }
        disc* getTop(){
            return top;
        }
        void setTop(disc*d){
            top=d;
        }
        /// prepares discs on pegs
        void setup(int numDiscs){
           int counter=numDiscs;
            while ( counter > 0 ){
                insert(counter);
                counter--;
            }
        }
};


class tower{
    private:
        stack *peg1, *peg2, *peg3;
        int num;
    public:
        tower(int numDiscs){
            peg1=new stack();
            peg2=new stack();
            peg3=new stack();
            peg1->setup(numDiscs);
            peg2->setup(0);
            peg3->setup(0);
            num=numDiscs;
            display();
        }
        void execute();
        void move1(stack *start, stack *end);
        void move2(stack *start, stack *end, stack* temp);
        void move3(stack *start, stack *end, stack* temp);
        void move4(stack *start, stack *end, stack* temp);
        void move5(stack *start, stack *end, stack* temp);
        void move6(stack *start, stack *end, stack* temp);
        void move7(stack *start, stack *end, stack* temp);
        void move8(stack *start, stack *end, stack* temp);
        void move9(stack *start, stack *end, stack* temp);
        void move10(stack *start, stack *end, stack* temp);
        void display(){
            system("CLS");
            gotoxy(0,0);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED);
            cout<<"S1: ";
            peg1->print();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN);
            cout<<"S2: ";
            peg2->print();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN);
            cout<<"S3: ";
            peg3->print();
            cout<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            cout<<"Moves: "<<movecounter<<endl;
            movecounter++;
            Sleep(50);
        }
        int getNumDiscs(){
            return num;
        }
};

void tower::move1(stack* p1, stack* p2){
    ///move 1 piece from peg1 to peg2
    int discSize=p1->getTop()->getData();
    disc*d=new disc(discSize, NULL);
    d->setNext(p2->getTop());
    p2->setTop(d);
    p1->remove();
    display();
}

/// move 2 piece from p1 to p3 (p2 is the other peg)
void tower::move2(stack* p1, stack* p3, stack* p2){
    move1(p1, p2);
    move1(p1, p3);
    move1(p2, p3);
}
void tower::move3(stack* p1, stack* p3, stack* p2){
    move2(p1, p2, p3);
    move1(p1, p3);
    move2(p2, p3, p1);
}
void tower::move4(stack* p1, stack* p3, stack* p2){
    move3(p1,p2,p3);
    move1(p1,p3);
    move3(p2,p3,p1);
}
void tower::move5(stack* p1, stack* p3, stack* p2){
    move4(p1,p2,p3);
    move1(p1,p3);
    move4(p2,p3,p1);
}
void tower::move6(stack* p1, stack* p3, stack* p2){
    move5(p1,p2,p3);
    move1(p1,p3);
    move5(p2,p3,p1);
}
void tower::move7(stack* p1, stack* p3, stack* p2){
    move6(p1,p2,p3);
    move1(p1,p3);
    move6(p2,p3,p1);
}
void tower::move8(stack* p1, stack* p3, stack* p2){
    move7(p1,p2,p3);
    move1(p1,p3);
    move7(p2,p3,p1);
}
void tower::move9(stack* p1, stack* p3, stack* p2){
    move8(p1,p2,p3);
    move1(p1,p3);
    move8(p2,p3,p1);
}
void tower::move10(stack* p1, stack* p3, stack* p2){
    move9(p1,p2,p3);
    move1(p1,p3);
    move9(p2,p3,p1);
}


void tower::execute(){
    if ( getNumDiscs() == 1 ){
        move1(peg1, peg3);
    }
    else if ( getNumDiscs() == 2 ){
        move2(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 3 ){
        move3(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 4 ){
        move4(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 5 ){
        move5(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 6 ){
        move6(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 7 ){
        move7(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 8 ){
        move8(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 9 ){
        move9(peg1, peg3, peg2);
    }
    else if ( getNumDiscs() == 10 ){
        move10(peg1, peg3, peg2);
    }
}

int main (){
    cout<<"Enter number of rings: ";
    int input;
    cin>>input;
    tower t(input);
    t.execute();
    return 0;
}
