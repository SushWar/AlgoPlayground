#include <bits/stdc++.h>
using namespace std;


int main() {

      /*
        Problem Statement
            In a lively car showroom, an array of cars awaits, each with its distinctive features. Picture yourself mixing and matching these cars in unique combinations to create dream blends which has a fscore equal to the XOR value of the combination. 

            Your mission: compute the blend score, which is the XOR of the fscore values for all these dreamy combinations.  (https://unstop.com/code/challange-asesment/261990?moduleId=406)

            Now, it's time to reveal the grand total!

        Input Format
            The first line of input consists of the integer n – representing the number of cars in the showroom.

            The second line consists of n integers - representing the features of the car. 

        Output Format
            Print the sum of fscore obtained.   
        
        Sample Testcase 0
        Testcase Input
            5
            4 3 5 1 2
        Testcase Output
            3

  */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;

    vector<int>cars(n);
    for(auto &i : cars){
      cin>>i;
    }
    int res = 0;
    if(n & 1){
      for(int i = 0; i < n; i+=2){
        res ^= cars[i];
      }
    }
    cout << res << endl;
    return 0;
}