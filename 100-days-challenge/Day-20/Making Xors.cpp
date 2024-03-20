#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll helper(int arr[], int n){

 

  
  // ll bits = 0; 
  
    
  //   for (int i=0; i < n; ++i) 
  //       bits |= arr[i]; 
  
  //   ll ans = bits * pow(2, n-1); 
  
  //   return ans; 

  // for storing result
    int ans=0;
    // looping over the 32 bits
    for(int i=0; i<32; i++)
    {
    	// creating a mask.
        int mask=1<<i;
        // maintaining count
        int count=0;
        for(int j=0; j<n; j++)
        {
        	// if nums[j]&mask increment the count
            if(arr[j]&mask) count++;
        }
        if(count)
            ans+=mask*(1<<(count-1))*(1<<(n-count));
    }

    return ans;
  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250586?moduleId=424
      12+14 => 26
        5 1 6 
      5 5 4 3
      1 4 1 7
      6 3 7 6

      i=0,j=1 => pick = 4, notpick = 5 => 9
      i=0,j=2 => pick = , notpick =  => 
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

    ll result = helper(arr,n);

    cout<<result<<endl;

    return 0;
}