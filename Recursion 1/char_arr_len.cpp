#include <iostream>
using namespace std;
int charlen(char arr[]){
    if(arr[0]=='\0'){
        return 0;
    }
    else{
        return 1+charlen(arr+1);
    }
}
int main(){
    char arr[]= "chetna sriram pawar";
    cout<<charlen(arr);

}