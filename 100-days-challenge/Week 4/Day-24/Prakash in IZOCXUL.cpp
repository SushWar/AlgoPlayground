#include <bits/stdc++.h>
using namespace std;


bool hasUniqueCharacters(const string& s) {
    unordered_set<char> seen;
    for (char c : s) {
        if (seen.count(c) > 0) {
            return false;
        }
        seen.insert(c);
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250758?moduleId=428
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin>>S;

    int K;
    cin>>K;

    for (int size = 2; size <= K; ++size) {
        int count = 0;
        for (int i = 0; i <= S.size() - size; ++i) {
            if (hasUniqueCharacters(S.substr(i, size))) {
                count++;
            }
        }
        cout << count << endl;
    }
    // map<int,int>order;
    
    // helper(0,s.size(),k,order,"");

  //   for(int i=0;i<s.size();i++){
  //     int count = 1;
  //     vector<int>alpha(26,0);
  //     alpha[s[i]-'a']++;
  //     for(int j=i+1;j<s.size() && count <= k;j++){
  //       if(alpha[s[j]-'a'] == 1){break;}
  //       alpha[s[j]-'a']++;
  //       count++;
  //       order[count]++;
  //     }
  //   }

  // k--;
  //   for(auto x: order){
  //     cout<<x.second<<endl;
  //     k--;
  //   }

  //   while(k--){
  //     cout<<0<<endl;
  //   }



    return 0;
}