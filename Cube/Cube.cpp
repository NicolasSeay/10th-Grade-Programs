#include <iostream>
#include <iomanip>

using namespace std;

class Cube{
    private:
        double Side;
    public:
        Cube();
        Cube(int);
        void setSide(double s);
        double getSide();
        double Area();
        double Volume();
        void properties();
};
Cube::Cube(){
    Side=8;
}
Cube::Cube(int value){
    Side=value;
}
void Cube::setSide(double s){
    Side=s;
}
double Cube::getSide(){
    return Side;
}
double Cube::Area(){
    return(6*Side*Side);
}
double Cube::Volume(){
    return(Side*Side*Side);
}
void Cube::properties(){
    cout<<"Side     "<<getSide()<<endl;
    cout<<"Area     "<<Area()<<endl;
    cout<<"Volume   "<<Volume()<<endl;
}
int main(){
    Cube c;
    c.properties();
    return 0;
}
