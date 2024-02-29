#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


void bruteForceApproach(vector<pp>&arr,int &n){


  sort(begin(arr),end(arr));  //nlogn
  vector<int>result(n,0);
  unordered_map<int,int>timeSaver;

  for(int i=n-1;i>=0;i--){
      int val = arr[i].first;
      if(timeSaver[val]){
        result[arr[i].second] = timeSaver[val];
      }
      else{
        int temp = i;
        while(val == arr[temp-1].first){
          temp--;
        }
        timeSaver[val] = temp;
        result[arr[i].second] = temp;
      }
      
  }

  for(int x: result){
    cout<<x<<" ";
  }
  return;
}

int main() {
    /* https://unstop.com/code/challange-asesment/250260?moduleId=410 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pp>arr(n);
    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      arr[i] = {val, i};
    }

    bruteForceApproach(arr,n);
    return 0;
}