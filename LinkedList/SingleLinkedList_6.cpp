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
  node* merginglist(node *first, node *second);
  
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


node* LinkedList::merginglist(node *first, node *second){
  node *third;
  node *last;

  if(first->data<second->data){
    third=last=first;
    first=first->next;
    last->next=NULL;
  }
  else{
    third=last=second;
    second=second->next;
    last->next=NULL; 
  }

  while(first && second){
    if(first->data<second->data){
      last->next=first;
      last=first;
      first=first->next;
      last->next=NULL;

    }
    else{
      last->next=second;
      last=second;
      second=second->next;
      last->next=NULL; 
    }  
  }
  if(first)
    last->next=first;
  if(second)
    last->next=second;
  
  return third;
}

void LinkedList::displaylist(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl<<endl;
}


int main(){

  int A[]={11,10,4,99,2,11,3,5,12,79,2,33,10,99};
  int B[]={1,22,17,77,81,63};
  int m=sizeof(A)/sizeof(A[0]);
  int n=sizeof(B)/sizeof(B[0]);

  sort(A,A+m);
  sort(B,B+n);

  LinkedList *list1=new LinkedList();
  for(int i=0; i<m; i++)
    list1->createlist(A[i]);
  cout<<"Displaying List1: ";
  list1->displaylist(list1->head);


  LinkedList *list2=new LinkedList();
  for(int i=0; i<n; i++)
    list2->createlist(B[i]);
  cout<<"Displaying List2: ";
  list2->displaylist(list2->head);

  
  LinkedList *list3=new LinkedList();
  list3->head=list3->merginglist(list1->head, list2->head);
  cout<<"Displaying List after Merging: ";
  list3->displaylist(list3->head);

  
  
return 0;

}
