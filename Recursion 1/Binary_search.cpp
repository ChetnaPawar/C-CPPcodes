#include <iostream>
using namespace std;
int binary(int arr[],int si,int ei,int x){
    int mid=(si+ei)/2;
    if(si>=ei){
        return -1;
    }
    else if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        binary(arr,si,mid,x);
    }
    else{
        binary(arr,mid+1,ei,x);
    }
}
int main(){
    int arr[5]={1,2,3,4,9};
    cout<<binary(arr,0,4,8);
}