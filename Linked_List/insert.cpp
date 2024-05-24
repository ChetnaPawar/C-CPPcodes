#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        next = NULL;
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
    void print(Node*head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }
    Node* insert(int data,int pos,Node*head){
        Node*temp=head;
        Node* newnode = new Node(data);
        newnode->next = NULL;
        if(pos==1){
            newnode->next = head;
            head = newnode;
        }
        else{
            pos-=2;
            while(pos!=0){
                temp = temp->next;
                pos--;
                }
                newnode->next = temp->next;
                temp->next = newnode;
        }
        return head;
    }
    Node* del(Node*head,int data){
        Node*temp = head;
        Node* prev = head;
        //for first node
        if(temp->data == data){
            head = temp->next;
        }
        else{
        while(temp->data!=data){
            if(temp==NULL){
                cout<<"element not found"<<endl;
            }
            prev = temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        }
        return head;
    }
    int length(Node *head){
    int len=0;
    Node *temp = head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
};
int main(){
    Node* n;
    Node*head = n->append();
    n->print(head);
    // cout<<"insert: ";
    // head = n->insert(1,1,head);
    // n->print(head);
    cout<<"delete"<<endl;
    head = n->del(head,1);
    n->print(head);
}