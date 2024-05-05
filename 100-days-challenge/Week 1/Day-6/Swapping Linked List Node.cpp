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

Linked *helper(Linked *root, int k, int n){

  Linked *first = root;
  Linked *second = root;

  int start = k;
  int end = n-k+1;
  // cout<<"start --> "<<start<<"  end --> "<<end<<endl;
  while(start > 1){
    // cout<<"FIRST val --> "<<first->val<<endl;
    first = first->next;
    start--;
  }
  // cout<<"FIRST val --> "<<first->val<<endl;
  while(end > 1){
    // cout<<"SECOND val --> "<<second->val<<endl;
    second = second->next;
    end--;
  }
  // cout<<"SECOND val --> "<<second->val<<endl;
  swap(first->val, second->val);

  return root;


}

int main() {
    /* https://unstop.com/code/challange-asesment/250244?moduleId=410 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;

    Linked *root = new Linked(-1);
    Linked *temp = root;
    for(int i=0;i<n;i++){
      int data;
      cin>>data;
      Linked *insert = new Linked(data);
      temp->next = insert;
      temp = temp->next;
    }

    int k;
    cin>>k;

    Linked *result = helper(root->next, k, n);

    while(result != NULL){
      cout<<result->val<<" ";
      result = result->next;
    }
    return 0;
}