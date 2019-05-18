#include<iostream>
using namespace std;

class Array{
  private:
  int *A;
  int size, length;
  
  public:
  Array(int sz){
    size=sz;
    A=new int[size];

    cout<<"Enter the Length of Array: "<<endl;
    cin>>length;

    cout<<"Enter the array Elements: "<<endl;
    for(int i=0; i<length; i++) 
      cin>>A[i];
  }

  void deleteEle();
  void insert();
  void add();
  void display();
  int getLength(){
    return length;
  }
  
};

void Array::deleteEle(){
  int index;
  cout<<"Delete: Enter the index: "<<endl;
  cin>>index;
  if(index>=0 && index<size)
  {
    for(int i=index; i<size; i++)
    A[i]=A[i+1];
    length--;
  }
}

void Array::insert(){
  int index, ele;
  int temp=length;
  cout<<"Insert: Enter the index and Element: "<<endl;
  cin>>index>>ele;
  if(index>=0 && index<size && index<=length)
  {
    while(temp!=index){
    A[temp]=A[temp-1];
    temp--;
    }
    A[index]=ele;
    length++;
  }
  else{
    cout<<"Error in inserting "<<endl;
  }
}


void Array::add(){
int ele;
cout<<"Enter the element to be added: "<<endl;
cin>>ele;
if(length<=size)
  A[length++]=ele;
}


void Array::display(){
  cout<<"Displaying Elements: "<<endl;
  for(int i=0; i<length; i++)
    cout<<A[i]<<endl;
}

int main(){
Array *arr=new Array(15);
//arr->add();
arr->insert();
arr->display();
arr->deleteEle();
arr->display();
cout<<"Array Length: "<<arr->getLength()<<endl;
return 0;
}
