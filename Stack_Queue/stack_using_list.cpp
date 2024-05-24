#include <iostream>
using namespace std;

class stacklist{
    int *data;
    int nextid;
    int capacity;
    public:
    stacklist(int size){
        data = new int[size];
        nextid = 0;
        capacity = size;
    }
    void push(int val){
        if(isfull()){
            cout<<"stack full"<<endl;
            return;
        }
        data[nextid] = val;
        nextid++;
    } 
    bool isempty(){
        return (nextid==0);
    }
    bool isfull(){
        return (nextid==capacity);
    }
    void pop(){
        if(isempty()){
            printf("stack is empty");
        }
        nextid--;
        cout<<"deleted:"<<data[nextid]<<endl;
    }
    void peek(){
         if(isempty()){
            printf("stack is empty");
        }
        cout<<"Top: "<<data[nextid-1]<<endl;
    }
    void size(){
        cout<<"size: "<<capacity<<endl;
    }
};

int main(){
    stacklist s(4);
    cout<<s.isempty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(3);
    s.peek();
    s.push(4);
    s.push(5);
    s.size();
    return 0;
}