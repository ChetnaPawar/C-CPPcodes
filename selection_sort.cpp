#include <iostream>
using namespace std;
void selection(int arr[],int s){
    for(int i=0;i<s;i++){
        int temp;
        int min = arr[i];
        int minindex = i;
        for(int j=i+1;j<s;j++){
            if(arr[j]<min){
                min = arr[j];
                minindex = j;
            }
        }
        //swap the min most element
        temp = arr[i];
        arr[i] = min;
        arr[minindex] = temp;
    }
}
int main(){
    int arr[]={4,3,2,1};
    int s = sizeof(arr)/sizeof(arr[0]);
    selection(arr,s);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}