//Single linked list implementasi Sequence Search
//Siti Zubaidah
//G1A021002
//Informatika B 21

#include<iostream>
using namespace std;
class node{
public:
   int data;
   node*next;
   node(int d){
      data=d;
      node*next= NULL;
   }
};
void insertAt(node*&head, int data){
   node*n= new node(data);
   n->next= head;
   head= n;
}
bool searchSequential(node*head,int key){
   if(head==NULL){
      return false;
   }
   if(head->data==key){
      return true;
   }
   else{
      return searchSequential(head->next, key);
   }
}
void printNode(node*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
int main(){
   node*head= NULL;
   insertAt(head,5);
   insertAt(head,4);
   insertAt(head,3);
   insertAt(head,2);
   insertAt(head,1);
   printNode(head);
   if(searchSequential(head,3)){
      cout<<"present"<<endl;
   }
   else{
      cout<<"Not Present"<<endl;
   }
}