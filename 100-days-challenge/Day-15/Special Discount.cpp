#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT

    
      4 2 4 2 3
      https://unstop.com/code/challange-asesment/250542?moduleId=419
     */   

     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(arr[j] <= arr[i]){
          arr[i] -= arr[j];
          break;
        }
      }
    }

    for(int x: arr){
      cout<<x<<" ";
    }

    return 0;
}