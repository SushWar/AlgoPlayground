#include <bits/stdc++.h>
using namespace std;


int main() {

    /*
    Problem statement :- One day jack finds a string of characters. He is very keen to arrange the characters in reverse order, i.e., 
    first characters become the last characters, second characters become the second-last characters, and so on. Now he wants your help 
    to find the kth character from the new string formed after reverse the original string. (https://unstop.com/code/challange-asesment/250173?moduleId=372)

    Input format :- The first line contains two integers n, k — the length of array and the value of k respectively.
                    The second line contains a string containing n characters.

    TestCase input :- 
    [
      5 2
      abdfa
    ]

    TestCase output :-
    [
      f
    ]
  */
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    string s1;
    cin>>n>>k;
    cin>>s1;

    cout<<s1[n-k]<<endl;
    
    return 0;
}