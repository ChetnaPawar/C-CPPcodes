#include <iostream>
using namespace std;
class Fraction{
    public:
    int num;
    int dem;
    Fraction(int num,int dem){
        this->num=num;
        this->dem=dem;
    }
    void print(){
        cout<<this->num<<" "<<this->dem<<" "<<endl;
    }

Fraction& operator+=(Fraction const &f){
    num = (num*f.dem)+(f.num*dem);
    dem = dem*f.dem;
    return*this;
}
};
int main(){
    Fraction f1(10,2);
    Fraction f2(6,3);
    (f1+=f2)+=f2;
    f1.print();
    return 0;
}