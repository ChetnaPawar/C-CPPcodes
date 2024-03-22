#include <iostream>
using namespace std;
void swap(int arr[],int elei,int a){
    int temp = arr[a];
    arr[a]=arr[elei];
    arr[elei]=temp;
}
int partition(int arr[],int si,int ei){
    int count=0;
    int elementindex = si;
    for(int i=si+1;i<=ei;i++){
        if(arr[i]<arr[elementindex]){
            count++;
            //swap the element with smaller number
            swap(arr,elementindex,i);
            elementindex++;
        }
    }
    //swap the elementindex with the count
    swap(arr,count+si,elementindex);
    return count;
}
void quicksort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int c = partition(arr,si,ei);
    quicksort(arr,si,c-1);
    quicksort(arr,si+c+1,ei);
}
int main(){
    int arr[5]={25,48,2,0,98};
    quicksort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}