#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    /*
        Problem Statement
            In a game, there are 2 queens which are to be placed on 2 mats. The mats are arranged with orders specified with numbers on them. The placement of the queen is to be done in such a manner that when one of the orders of the mat, when divided with the other order, gives the maximum possible value. The order of the mats is between the two integers denoted by l and r.

            Find the order of mats on which the two queens can be placed. (https://unstop.com/code/challange-asesment/259978?moduleId=406)

        Input Format
            The first line contains one positive integer t (1 ≤ t ≤ 104), denoting the number of test cases.

            The only line of each test case contains two integers l, r.

        Output Format
            For every test case, output the largest possible value of a % b over all pairs (a, b denoting the order of mats) for which l <= b <= a <= r.
        
        Sample Testcase 
            Testcase Input
                3
                1 1
                2 12
                4 9 
            Testcase Output
                0
                5
                4

  */
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;

    while(test--){
      ll left, right;
      cin>>left>>right;

      int lastSegment = right / 2;
      
      if(lastSegment >= left){
        cout<<(right%(lastSegment+1))<<endl;
      }
      else{
        cout<<(right%left)<<endl;
      }

    }
    return 0;
}