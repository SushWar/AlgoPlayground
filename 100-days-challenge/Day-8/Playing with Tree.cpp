#include <bits/stdc++.h>
using namespace std;

class Linked{
  public:
  int val;
  Linked *next;

  Linked(int ele){
    val = ele;
    next = NULL;
  }
};

Linked *createList(Linked *list, vector<int>arr, int start, int end, int target){

  if(start > end){return new Linked(-100);}
  int mid = start + (end-start)/2;
  // cout<<"inside create LIST --> "<<arr[mid]<<endl;
  Linked *newLink = new Linked(arr[mid]);

  newLink->next = list;
  Linked *result;

  if(target < arr[mid]){
    result =  createList(newLink, arr,start,mid-1,target);
  }
  else if(target > arr[mid]){
    result = createList(newLink, arr,mid+1,end,target);
  }
  else{
    result = newLink;
  }

  return result;
}

int main() {
    /* https://unstop.com/code/challange-asesment/250198?moduleId=412  */   


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>students;
    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      students.push_back(val);
    }
    int x,y;
    cin>>x>>y;
    if(n==2){
      cout<<max(x,y)<<endl;
      return 0;
    }
    // if(__gcd(x,y) == 1){
    //   cout<<1<<endl;
    //   return 0;
    // }

    sort(begin(students),end(students));

    Linked *first = createList(new Linked(-1), students, 0, n-1, x);
    Linked *second = createList(new Linked(-1), students, 0, n-1, y); 


    unordered_set<int>visit;
    while(first->next != NULL){
      // cout<<"FIRST node --> "<<first->val<<endl;
      int val = first->val;
      visit.insert(val);
      first = first->next;
    }

    int result = INT_MAX;
    while(second->next != NULL){
      // cout<<"SECOND node --> "<<second->val<<endl;
      int val = second->val;
      if(visit.count(val)){
        result = min(result, val);
      }
      second = second->next;
    }

    cout<<result<<endl;
    return 0;
}