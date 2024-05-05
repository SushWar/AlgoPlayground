#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT https://unstop.com/code/challange-asesment/250653?moduleId=433*/   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string temp;
    cin>>temp;

    int loop;
    cin>>loop;
    unordered_map<string,string>order;

    for(int i=0;i<loop;i++){
      string key,value;
      cin>>key;
      cin>>value;
      order[key] = value;
      // cout<<key<<"  -->   "<<value<<endl;
    }

    string ans = "", find = "";
    bool open = false;
    for(char x: temp){
      if(x=='('){
        open = true;
      }
      else if(x==')'){
        open = false;
        if(order.count(find)) ans += order[find];
        else ans += '?';

        find = "";
      }
      else{
        if(open) find += x;
        else ans+=x;
      }
    }

    cout<<ans<<endl;
    return 0;
}