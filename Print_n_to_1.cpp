#include <iostream>
using namespace std;
int print(int n){
    if(n==0){
        return n;
    }
    cout<<n<<endl;
    print(n-1);
}
int main(){
    cout<<"enter the number till where u want the numbers to be printed in reverse: ";
    int n;
    cin>>n;
    cout<<print(n);
}