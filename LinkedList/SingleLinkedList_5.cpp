#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;

class LinkedList{
  public:
  node *head=NULL;
  node *tail=NULL;
  int length=0;

  void createlist(int data);
  void displaylist(node *temp);
  void removeduplicates(node *temp);
};



void LinkedList:: createlist(int data){
  node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL){
    head=newnode;
    tail=newnode;
  }
  else{
    tail->next=newnode;
    tail=newnode;
  }
  length++;
}

void LinkedList:: removeduplicates(node *temp){
  node *p=temp->next;
  while(p){
    if(p->data==temp->data){
      temp->next=p->next;
      delete[] p;
      length--;
      p=temp->next;
    }
    else{
      temp=p;
      p=p->next;
    }
    tail=temp; //Update the tail pointer
  }
}



void LinkedList::displaylist(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
}


int main(){

  int A[]={11,10,4,99,2,11,3,5,12,79,2,33,10,99};
  int size=sizeof(A)/sizeof(A[0]);
  sort(A,A+size);

  LinkedList *list=new LinkedList();
  for(int i=0; i<size; i++)
    list->createlist(A[i]);
  
  cout<<"Before Deleting the Duplicates-->"; 
  list->displaylist(list->head);
  cout<<"Length of the list:"<<list->length<<endl;

  cout<<endl<<endl<<"After Deleting the Duplicates-->";
  list->removeduplicates(list->head);
  list->displaylist(list->head);
  cout<<"Length of the list:"<<list->length<<endl;


  list->createlist(100);
  list->displaylist(list->head);

return 0;

}
