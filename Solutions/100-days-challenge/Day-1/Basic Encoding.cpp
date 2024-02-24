#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;


int main() {

    /*
        Problem Statement
            A machine could be fed with queries of type (a,b).

            Where (a b) means we have a number ‘b’ ‘a’ times.

            Output the absolute difference between the number that appears most number of times and least number of times (least number of times must be atleast once).

            If there are multiple possible answers print the maximum possible absolute difference.- (https://unstop.com/code/challange-asesment/250902?moduleId=372)

        Input Format
            First line contains a single integer denoting the number of queries.
            Second line onwards: two space separated integers denoting the queries

        Output Format
            Display a single integer, representing the absolute difference between the number that appears most number of times and least number of times.

        Sample Testcase 1
            Testcase Input
                4
                1 2
                1 3
                2 5
                4 4
            Testcase Output
                2
  */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    unordered_map<int,int>order;
    int mini = INT_MAX, maxi = 0;


    for(int i=0;i<n;i++){
      int times, num;
      cin>>times>>num;
      order[num] += times;
    }


    for(auto x: order){
      maxi = max(maxi, x.second);
      mini = min(mini, x.second);
    }


    if(maxi == mini){
      cout<<0<<endl;
      return 0;
    }


    int result = 0;
    pi find1 = {INT_MAX, 0}, find2 = {INT_MAX, 0};    //{small, big}
    for(auto flow:order){
      if(mini == flow.second){
        find1.first = min(find1.first, flow.first);
        find1.second = max(find1.second, flow.first);
      }
      else if(maxi == flow.second){
         find2.first = min(find2.first, flow.first);
        find2.second = max(find2.second, flow.first);
      }
    }

    // cout<<"FIND1 --> "<<find1.first<<" , "<<find1.second<<endl;
    // cout<<"FIND2 --> "<<find2.first<<" , "<<find2.second<<endl;
    result = max(max(abs(find1.first - find2.first),abs(find1.first - find2.second)),max(abs(find1.second - find2.first),abs(find1.second - find2.second)));


   


    cout<<result<<endl;

  return 0;
}