#include <iostream>
using namespace std;
class fraction{
    public:
    int num;
    int dem;
    fraction(){

    }
    fraction(int num,int dem){
        this->num = num;
        this->dem = dem;
    }
    void print(){
        cout<<num<<" "<<dem<<endl;
    }
    fraction operator+(fraction const &f){
        fraction *fnew = new fraction;
        fnew->num = this->num + f.num;
        fnew->dem = this->dem + f.dem;
        return *fnew;
    }
    fraction operator=(fraction const &f){
        this->num = f.num;
        this->dem = f.dem;
        return *this;
    }
};
int main(){
    fraction *f1 = new fraction(2,4);
    fraction *f2 = new fraction(1,2);
    //fraction f3 = *f1 + *f2;
    *f1 = *f2;
    f1->print();
}