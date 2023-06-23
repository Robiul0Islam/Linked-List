#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data=val;
            next=NULL;
        }
};

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}



void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

bool search(node* head,int key){
    node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
    
}
//key means after this element I want to insert a number;
void insertAfterAny(node* &head,int key,int val){
    node* n=new node(val);
   
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            node* temp2=temp;
            temp=temp->next;
            n->next=temp;
            temp2->next=n;
            return;
        }
        temp=temp->next;
    }
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    insertAfterAny(head,4,9);

    display(head);
    
}