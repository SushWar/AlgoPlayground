#include <bits/stdc++.h>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
        
    // vector<int>result(seq.size(),0);
    // int depth = 0;
    // for(int i=0;i<seq.size();i++){
    //     if(seq[i]=='('){
    //         result[i] = (depth++ % 2);
    //     }
    //     else{
    //         result[i] = (--depth % 2);
    //     }
    // }
    // return result;
     int depth = 0, cur = 0, n = seq.length();
        for (char c : seq)
            depth = max(depth, cur += c == '(' ? 1 : -1);
        vector<int> res(n, 0);
        
        // cur = 0;
        for (int i = 0; i < n; ++i) {
            // if it is over half, throw it to another group (1) instead of keeping it within (0)
            if (seq[i] == '(' && ++cur > depth / 2) res[i] = 1;
            if (seq[i] == ')' && cur-- > depth / 2) res[i] = 1;
        }
        return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    ( ( ) ( ) )
    0 1 1 1 1 0

    ( ) ( ( ) ) ( ) 
    0 0 0 1 1 0 0 0

    https://unstop.com/code/challange-asesment/250487?moduleId=419
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string parent;
    cin>>parent;
    
   vector<int>result = maxDepthAfterSplit(parent);

    for(int x: result){
      cout<<x<<" ";
    }

    return 0;
}