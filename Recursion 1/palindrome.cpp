#include <iostream>
using namespace std;
int plaindrome(int arr[],int n,int size){
    if(size==1){
        return 1;
    }
    else if(arr[0]!=arr[n-1]){
        return -1;
    }
    
    else{
        size=size-2;
        plaindrome(arr+1,n-1,size);
    }
}
int main(){
    int arr[5]={1,1,0,1,1};
    cout<<plaindrome(arr,5,5);
}