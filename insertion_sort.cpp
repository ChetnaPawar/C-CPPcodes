#include <iostream>
using namespace std;
void insertion(int arr[],int s){
    //first element is considered sorted
    int j;
    for(int i=1;i<s;i++){
        int current = arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>current){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }
}
int main(){
    int arr[] = {4,2,3,1};
    int s = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,s);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}