#include <iostream>
using namespace std;
void removex(char arr[]){
    if(arr[0]=='\0'){
        return;
    }
    if(arr[0]=='x'){
        for(int i=0;arr[i]!='\0';i++){
            arr[i]=arr[i+1];
        }
        if(arr[0]=='x'){    //removing consecutive eg.xxxa;
            removex(arr);
        }
    }
    removex(arr+1);
}
int main(){
    char arr[]="xaxxxxbc";
    removex(arr);
    cout<<arr;
}