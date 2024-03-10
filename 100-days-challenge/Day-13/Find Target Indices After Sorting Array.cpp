#include <bits/stdc++.h>
#define pp pair<int,vector<int>>
using namespace std;

vector<int> countTargets(int n,int k, vector<int>&order){

  /*
    1 2 2 3 5
  */

  int low = 0;
  int high = n-1;
  vector<int>result;
  while(low <= high){
    int mid = low + ((high-low)/2);
    // cout<<"mid --> "<<mid<<endl;
    if(order[mid]==k){
      
      int goLeft = mid-1, goRight = mid+1;
      while(goLeft >= low && order[goLeft] == k){
        result.push_back(goLeft);
        goLeft--;
      }
      sort(begin(result),end(result));
      result.push_back(mid);
      while(goRight <= high && order[goRight] == k){
        result.push_back(goRight);
        goRight++;
      }
      break;
    }
    else if(order[mid] > k){
      high--;
    }
    else{
      low++;
    }
  }
  
  return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250510?moduleId=417
    */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n;

    vector<int>order(n);

    for(int i=0;i<n;i++){
      cin>>order[i];
    }
    cin>>k;



    sort(begin(order),end(order));
    vector<int> result = countTargets(n,k,order);
    

    cout<<result.size()<<endl;
    for(int x: result){
      cout<<x<<" ";
    }
    return 0;
}