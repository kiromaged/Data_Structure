#include<iostream>
using namespace std;
 class node{
 public:
     int data;
     node* next;
     node*prev;
     node(){
         next=prev=NULL;
     }
 };
 class dublylist{
     node*head;
     node*tale;
     dublylist(){
         head=tale=NULL;
     }
     void display(){
         if(head==NULL)
             cout<<"nothing to dispaly\n";
         else {
             node *temp = head;
             while (temp!=NULL){
                 cout<<temp->data<<" ";
                 temp=temp->next;
             }
         }
     }
     bool isempty(){return head==NULL; }
     void insertfirst(int val){
         node* newnode = new node;
         newnode->next=head;
         head->prev=newnode;
         head=newnode;
         newnode->data=val;
     }
     void insertlast(int val){
         node* newnode=new node;
         newnode->data=val;
         tale->next=newnode;
         newnode->prev=tale;
         tale=newnode;
     }
     void insertmiddle(int val,int index){
         if(index==0)
             insertfirst(val);
         else{
             node*temp=head;
             index--;
             while(index-- and temp->next!=NULL){
                 temp=temp->next;
             }
             node*newnode=new node;
             newnode->data=val;
             newnode->next=temp->next;
             temp->next->prev=newnode;
             temp->next=newnode;
             newnode->prev=temp;

         }
     }

 };
int main() {
}
