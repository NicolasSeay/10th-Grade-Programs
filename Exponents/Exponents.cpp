#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout<<setprecision(3)<<fixed;
    int int1, int2, sum=0;
    int frac;
    double deci=0;
    cout<<"Integer 1: ";
    cin>>int1;
    cout<<"Integer 2: ";
    cin>>int2;
    cout<<endl;
    sum=int1*int1;
    if((int1==0)&&(int2<0)){
        cout<<"Does not exist"<<endl;
        return 0;
    }
    else if(int2==0){
        cout<<"1"<<endl;
        return 0;
    }
    else if((int1==0)&&(int2>0)){
        cout<<"0"<<endl;
        return 0;
    }
    else if((int1==0)&&(int2==0)){
        cout<<"Indeterminate"<<endl;
        return 0;
    }
    else if((int1<0)&&(int2<0)){
        for(int a=0; a<int2-2; a++){
            sum=(sum*int1);
        }
        if(0==int2%2){
            cout<<"Fraction: 1/"<<sum<<endl;
            deci=(double(1)/double(sum));
            cout<<"Decimal: "<<deci<<endl;
        }
        if(1==int2%2){
            cout<<"Fraction: 1/-"<<sum<<endl;
            deci=(double(1)/double(sum));
            cout<<"Decimal: "<<deci<<endl;
        }
    }
    else if(int2>0){
        for(int a=0; a<int2-2; a++){
            sum=(sum*int1);
        }
        cout<<sum<<endl;
    }
    /*else if(int2==2){
        sum=int1*int1;
        cout<<sum<<endl;
    }

    else if(int2==1){
        cout<<int1<<endl;
    }*/
    else if((int2==(-1))&&(int1>=1)){
        cout<<"Fraction: 1/"<<int1<<endl;
        deci=(1.0/(double)int1);
        cout<<"Decimal: "<<deci<<endl;
    }
    else if((int2==(-2))&&(int1>=1)){
        frac=(int1*int1);
        cout<<"Fraction: 1/"<<frac<<endl;
        deci=(1.0/(double)frac);
        cout<<"Decimal: "<<deci<<endl;
    }
    else if((int2<=(-3))&&(int1>=1)){
        sum=int1;
        for(int a=0; a>int2+1; a--){
            sum=(sum*int1);
        }
        cout<<"Fraction: 1/"<<sum<<endl;
        deci=(1.0/(double)sum);
        cout<<"Decimal: "<<deci<<endl;
    }
    return 0;
}
