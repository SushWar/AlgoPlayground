#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>arr){

  int n = arr.size();
  int counter = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if((arr[i]&arr[j]&arr[k])==0){
          counter++;
        }
      }
    }
  }

  return counter;

}


int main() {
    /* https://unstop.com/code/challange-asesment/250608?moduleId=409*/   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    int result = helper(arr);
    cout<<result<<endl;
    
 
    return 0;
}