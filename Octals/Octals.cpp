#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Oct{
    private:
        int num;
    public:
        Oct();
        Oct(int);
        void setnum(int);
        int getnum();
        void convert();
        void display();

};

Oct::Oct(){
    num=888;
}
Oct::Oct(int value){
    num=value;
}

void Oct::setnum(int s){
    num=s;
}
int Oct::getnum(){
    return num;
}
void Oct::convert(){
    int baseten;
    int temp;
    vector <int> baseeight;
    temp=num/8;
    baseeight.push_back(num%8);
    do{
        baseeight.push_back(temp%8);
        temp=temp/8;
    }while(temp>0);
    cout<<"Integer(base 8) : ";
    for(int i=baseeight.size()-1; i>=0; i--){
        cout<<baseeight[i];
    }
    cout<<endl;
}

void Oct::display(){
    convert();
}
int main(){
    int baseten;
    cout<<"Integer(base 10): ";
    cin>>baseten;
    Oct c(baseten);
    c.display();
    return 0;
}
