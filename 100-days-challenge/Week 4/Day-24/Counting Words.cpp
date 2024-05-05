#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250897?moduleId=428*/   
    

    string s1;
    getline(cin,s1);

    istringstream ss(s1);

    string word;
    int maxi = 0, count = 0;
    while(ss>>word){
        count++;
        int idx = (int)word.size();
        if(word[idx-1] == '.' || word[idx-1] == ','){
          maxi = max(maxi, count);
          count = 0;
        }
    }
    maxi = max(maxi, count);
    cout<<maxi;
        

    return 0;
}