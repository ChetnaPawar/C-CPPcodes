#include <iostream>
using namespace std;
class polynomial{
    public:
    int *poly;
    int capacity;
    polynomial(){
        this->poly = new int[2];
        capacity = 2;
        for(int i =0;i<capacity;i++)
        this->poly[i]=0;
    }
    polynomial (polynomial &p){
        polynomial *pnew = new polynomial();
        pnew->capacity = p.capacity;
        pnew->poly = new int[p.capacity];
        for(int i=0;i<pnew->capacity;i++){
            pnew->poly[i] = p.poly[i];
        }
        this->poly = pnew->poly;
        this->capacity = pnew->capacity;
    }
    polynomial operator=(polynomial const &p){
        this->capacity = p.capacity;
        int i;
        for(i=0;i<p.capacity;i++){
            this->poly[i] = p.poly[i];
        }
        return *this;
        }
    void print(){
        for(int i=0;i<capacity;i++){
            if(poly[i]!=0){
                cout<<poly[i]<<"X"<<i<<" ";
            }
        }
        cout<<endl;
    }
    void set(int ele,int pos){ 
        polynomial *pnew = this;
        if(pos>=capacity){
            //increase
            int newcap = capacity*2;
            int *newpoly = new int[newcap];
            int i;
            cout<<endl;
            for(i=0;i<capacity;i++){
                newpoly[i] = poly[i];
            }
            while(i<newcap){
                newpoly[i] = 0;
                i++;
            }
            //cout<<"size:"<<pnew->capacity<<endl;
            delete[] poly;
            poly = newpoly;
            capacity = i;
            pnew->set(ele,pos);
        }
        else{
        pnew->poly[pos] = ele;
        //this = pnew;
        //return *pnew;
        }
    }
    polynomial operator+(polynomial &p){
        polynomial *pnew = new polynomial();
        int maxcap = max(capacity,p.capacity);
        pnew->capacity = maxcap;
        pnew->poly = new int[maxcap];
        for(int i=0;i<maxcap;i++){
            int coeff1 = (i<capacity)? poly[i] : 0;
            int coeff2 = (i<p.capacity)? p.poly[i] :0;
            pnew->poly[i] = coeff1 + coeff2;
        }
        return *pnew;
    }
    polynomial operator-(polynomial &p){
        int maxcap = max(capacity,p.capacity);
        polynomial *newp = new polynomial();
        newp->capacity = maxcap;
        newp->poly = new int[maxcap];
        for(int i =0;i<maxcap;i++){
            int coeff1 = (i<capacity)? poly[i] :0;
            int coeff2 = (i<p.capacity)? p.poly[i] :0;
            newp->poly[i] = coeff1 - coeff2;
        }
        return *newp;
    }  
    polynomial operator*(polynomial &p){
        int i = capacity-1;
        while(poly[i]==0){
            i--;
        }
        int j = p.capacity -1;
        while(p.poly[j]==0){
            j--;
        }
        int maxcap = (i*j)+1;
        polynomial *pnew = new polynomial();
        pnew->capacity = maxcap+1;
        pnew->poly = new int[maxcap];
        for(int i=0;i<pnew->capacity;i++){
            pnew->poly[i] = 0;
        }
        for(int k=0;k<=i;k++){
            if(poly[k]!=0){
            for(int l=0;l<=j;l++){
                if(p.poly[l]!=0){
                    int pos = (k<=1 && l<=1)? (k*l)+1 : k+l;
                    pnew->poly[pos] = poly[k]*p.poly[l]; 
                }
            }
        }
        }
        return *pnew;
    } 
};
int main(){
    polynomial *p1 = new polynomial();
    polynomial *p2 = new polynomial();
    //polynomial *p2(p1);
    // *p2=*p1;
    // *p2 = p2->setcoefficient(2,2);
    // *p2 = p2->setcoefficient(5,5);
    p1->set(2,1);
    p1->set(3,0);
    //p1->set(5,3);
    p2->set(2,1);
    p2->set(4,4);
    //polynomial p3 = *p1 + *p2;
    //*p2 = *p1;
    //p1->print();
    //p2->print();
    polynomial *p3 = new polynomial();
    *p3 = *p1 * *p2;
    p3->print();
    return 0;
}