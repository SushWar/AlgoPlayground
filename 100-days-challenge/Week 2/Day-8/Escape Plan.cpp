#include <bits/stdc++.h>
using namespace std;


class Linked {
  public:
  int val;
  Linked *next;

  Linked(int ele){
    this->val = ele;
    this->next = NULL;
  }
};

void insert(Linked *root ,int data){

  while(root->next != NULL && root->next->val <= data){
    root = root->next;
  }

  Linked *newLink = new Linked(data);
  if(root->next==NULL){
    root->next = newLink;
  }
  else{
    Linked *ahead = root->next;
    root->next = newLink;
    newLink->next = ahead;
  }
}


void LinkedListMethod(){
  int n;
  cin>>n;

  Linked *root = new Linked(-1);
  Linked *temp = root;

  for(int i=0;i<n;i++){
    int ele;
    cin>>ele;
    insert(root, ele);
  }
  root = root->next;
  int mid = n/2;
  mid++;

  while(mid > 1){
    root = root->next;
    mid--;
  }
  cout<<root->val<<endl;
}

void niveApproach(){
  int n;
  cin>>n;

  vector<int>arr(n);
  for(int i=0;i<n;i++){cin>>arr[i];}

  sort(begin(arr),end(arr));

  cout<<arr[n/2]<<endl;
}


int main() {
    /* https://unstop.com/code/challange-asesment/250214?moduleId=412

      1 2 3 4 5 6 7 8 9
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LinkedListMethod();
    // niveApproach();

    return 0;
}