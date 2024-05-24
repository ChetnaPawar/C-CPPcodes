#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        next=NULL;
    }
    Node* append(){
        int data;
        cin>>data;
        Node*head = NULL;
        Node*tail = NULL;
        while(data!=-1){
            Node *newnode = new Node(data);
            if(head == NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next = newnode;
                tail=tail->next;
            }
            cin>>data;
        }
        return head;
    }
    void print(Node*temp){
        if(temp==NULL){
            cout<<endl;
            return;
        }
        cout<<temp->data<<" ";
        print(temp->next);
    }
    Node* insert(Node*temp,Node*newnode,int pos){
        if(pos==1){
            newnode->next = temp;
            temp = newnode;
            return temp;
        }
        if(pos==2){
            newnode->next = temp->next;
            temp->next=newnode;
            return NULL;
        }
        insert(temp->next,newnode,pos-1);
    }
    Node* del(Node*temp,int data,Node*prev){
        if(temp==NULL){
            cout<<"element not found";
            return NULL;
        }
        if(temp->data == data){
            if(prev == temp){
                temp = temp->next;
                delete prev;
                return temp;
            }
            else{
            prev->next = temp->next;
            delete temp;
            return NULL;
            }
        }
        del(temp->next,data,temp);
    }
};
int main(){
    Node*n;
    Node*head = n->append();
    //insert
     Node* newnode = new Node(1);
    Node*h = n->insert(head,newnode,1);
    if(h!=NULL){
        head = h;
    }
    //delete
    Node*h=n->del(head,1,head);
    if(h!=NULL){
        head = h;
    }
    n->print(head);
}
