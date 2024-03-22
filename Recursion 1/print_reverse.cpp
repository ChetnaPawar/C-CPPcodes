#include <iostream>
using namespace std;
int first(int arr[],int n,int x,int count){
    if(n==1){
        return -1;
    }
    else if(arr[0]==x){
        return count;
    }
    else{
        count++;
        first(arr+1,n-1,x,count);
    }
}
int main(){
    int arr[5]={2,1,3,7,1};
    cout<<first(arr,5,4,1);   
}