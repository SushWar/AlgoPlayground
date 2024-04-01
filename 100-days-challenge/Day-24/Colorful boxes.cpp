#include <bits/stdc++.h>
using namespace std;



string helper(string s){
        istringstream ss(s);
        
        vector<string>vstr;
        
        string word;
        while(ss>>word){
            vstr.push_back(word);
        }
        
        string ans="";
        
        for(auto word:vstr){
            reverse(begin(word),end(word));
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250162?moduleId=428
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    getline(cin, s1);

    string res = helper(s1);
    cout<<res<<endl;

    return 0;
}