#include <iostream>
#include <iomanip>

using namespace std;

class node{
    private:
        int data;
        node*next;
    public:
        node(int d, node*n){
            data=d;
            next=n;
        }
        int getData(){
            return(data);
        }
        void setNext(node*n){
            next=n;
        }
        node* getNext(){
            return(next);
        }
};
class list{
    private:
        node*first;
    public:
        list(){
            first=NULL;
        }
        void print();
        void insert(int x);
        void remove(int y);
        void menu();
};

void list::print(){
    node*temp=first;
    if(!temp){
        cout<<"Nothing";
    }
    else{
        do {
            cout<< temp->getData() <<" ";
            temp=temp->getNext();
        }while(temp!=NULL);
    }
    cout<<endl<<endl;
}
void list::insert(int x){
    if(first==NULL){
        //cout<<"created first node"<<endl;
        first=new node(x, NULL);
    }
    else{
        node* next=first;
        node* previous=NULL;
        // find insertion point between previous and next
        while((next != NULL) && (next->getData()<x)) {
            //cout << "previous=next" << endl;
            previous=next;
            //cout << "next=next.getNext" << endl;
            next=next->getNext();
        }

        node* newnum=new node(x, NULL);
        //cout << "created newnum" << endl;
        if ((next != NULL) && (newnum->getData() < next->getData())){
            //cout << "newnum.setNext" << endl;
            newnum->setNext(next);
        }

        if(previous != NULL){
            //cout << "previous.setNext" << endl;
            previous->setNext(newnum);
        }
        else{
            //cout << "first=newnum" << endl;
            first=newnum;
        }
        // insert the new value after the last node
    }
}

void list::remove(int y){
    if (first == NULL){
        cout<<"Empty";
    }
    else {
        node* next=first;
        node* previous=NULL;
        while ((next->getNext() != NULL) && (next->getData()<y)){
            //cout<<"hello";
            previous=next;
            next=next->getNext();
        }
        if ((next->getData() != y) && (next->getNext() == NULL)){
            cout<<"Value not in the list";
        }
        else {
            if (previous == NULL){
                //cout<<"hey";
                first=first->getNext();
            }
            else {
                if (next->getNext() != NULL){
                    previous = next->getNext();
                    //cout<<"1";
                }
                else {
                    node* prev=previous->getNext();
                    prev=next->getNext();
                    //cout<<"2";
                }
            }
        }
    }
    cout<<endl<<endl;
}

void list::menu(){
    int status;
    cout<<"1. Print"<<endl;
    cout<<"2. Insert"<<endl;
    cout<<"3. Delete"<<endl;
    cout<<"4. End"<<endl;
    do{
        cin>>status;
        if (status == 1){
            print();
        }
        else if (status == 2){
            int x;
            cin>>x;
            insert(x);
        }
        else if (status == 3){
            int y;
            cin>>y;
            remove(y);
        }
        else if (status >= 5){
            cout<<"Invalid input"<<endl<<endl;
        }
    }while (status != 4);
}

int main (){
    list l;
    l.menu();
    return 0;
}
