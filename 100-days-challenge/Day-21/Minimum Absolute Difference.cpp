#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 

    https://unstop.com/code/challange-asesment/250592?moduleId=425
    
      1 2 3 4

    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    sort(begin(arr),end(arr)); //nlogn

    int mini = INT_MAX;
    vector<pp>res;

    for(int i=1;i<n;i++){
      int diff = arr[i] - arr[i-1];
      if(diff < mini){
        res.clear();
        mini = diff;
        res.clear();
        res.push_back({arr[i-1], arr[i]});
      }
      else if(diff == mini){
       res.push_back({arr[i-1], arr[i]}); 
      }
    }

    cout<<res.size()<<endl;
    for(auto x: res){
      cout<<x.first<<" "<<x.second<<endl;
    }


    return 0;
}