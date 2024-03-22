#include <iostream>
using namespace std;
void merge(int arr[],int si,int ei){
    int *temp = new int[(ei-si)+1];
    int i=si;
    int mid = (si+ei)/2;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=ei){
        temp[k]=arr[j];
        k++;
        j++;
    }
    int m=0;
    for(i=si;i<=ei;i++){
        arr[i]=temp[m];
        m++;
    }

}
void mergesort(int arr[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,ei);

}
int main(){
    int arr[] = {4,3,2,1};
    mergesort(arr,0,3);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
}