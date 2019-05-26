#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;


class LinkedList{
public:
  node *head=NULL;
  node *tail=NULL;
  int length;

  void createlist(int data);
  void display(node *temp);
  void deletele(node *temp, int pos);

};

 void LinkedList:: createlist(int data){
   node *newnode=new node();
   newnode->data=data;
   newnode->next=NULL;

  if(head==NULL){
    head=newnode;
    tail=newnode;
    length++;
  }
  else{
    tail->next=newnode;
    tail=newnode;
    length++;
  }

 }



void LinkedList::deletele(node *temp, int pos){
 

  if(pos<1 || pos>length)
    cout<<"Error in Deleting "<<endl;

  //1. Delete first position (update head pointer)
  else if(pos==1){
    head=head->next;
    delete[] temp;
    length--;
  }

  //2. Delete last position (update tail pointer)
  else if(pos==length){
    while(temp->next!=tail){
      temp=temp->next;
    }
    tail=temp;
    length--;
    
    temp=temp->next;
    tail->next=NULL;
    delete[] temp;
  }
  
  //3. Delete any position
  else {
    node *pre=NULL;

    for(int i=0; i<pos-1; i++){
      pre=temp;
      temp=temp->next;
    }
    pre->next=temp->next;
    delete[] temp;
    length--;
  }
}

void LinkedList:: display(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){

  LinkedList *list = new LinkedList();
  for(int i=0; i<10; i++)
    list->createlist(rand()%100);
  //list->display(list->head);

  list->deletele(list->head, 0);
  list->display(list->head);
  cout<<list->length<<endl;
 
  list->deletele(list->head, 10);
  list->display(list->head);
  cout<<list->length<<endl;
 
  list->deletele(list->head, 1);
  list->display(list->head);
  cout<<list->length<<endl;
 
  list->deletele(list->head, 4);
  list->display(list->head);
  cout<<list->length<<endl;
}
