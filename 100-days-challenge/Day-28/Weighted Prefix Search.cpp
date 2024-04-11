#include <bits/stdc++.h>
#define pp pair<string,int>
using namespace std;

struct Chain{

  Chain *alpha[26];
  int weight = 0;    

  bool containKey(char key) {
		return (alpha[key - 'a'] != NULL);
	}
	
	void put(char key, Chain *val) {
		alpha[key - 'a'] = val;
	}
	
	Chain *get(char key) {
		return alpha[key - 'a'];
	}
};


class Trie {
  private:
    Chain *root;
  public:

  Trie(){
    root = new Chain();
  }

  void insert(string word, int value) {
		
		Chain *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Chain());
			}
			//moves to reference trie
      node->weight += value;
			node = node->get(word[i]);
		}
		
	}


  int prefixVal(string word){
    Chain *node = root;

    for(int i=0;i<word.size();i++){
      if (!node->containKey(word[i])) {
        return 0;
      }
      node = node->get(word[i]);
    }

    return node->weight;
  }
};




pp extractPair(string s1){
  
  istringstream ss(s1);

  string word;
  pp res = {"",-1};
  while(ss>>word){
    // cout<<word<<" --> ";
    if(res.first == ""){
      res.first = word;
    }
    else{
      res.second = stoi(word);
    }
  }

  return res;
  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250433?moduleId=433*/   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Trie trie;
    unordered_map<string,int>order;
    while(true){
      string s1;
      getline(cin,s1);
      

      pp take = extractPair(s1);

      if(take.first == "exit") break;

      if(take.second == -1){
        // int val = trie.prefixVal(take.first);
        // cout<<val<<endl;
        int ans = 0;
        string key = take.first;
        int n = key.size();
        for(auto x: order){
          if(x.first.size() >= n){
            if(x.first.substr(0,n) == key) ans += x.second;
          }
        }

        cout<<ans<<endl;
      }
      else{
        order[take.first] = take.second;
        // trie.insert(take.first, take.second);
      }
      // cout<<take.first<<" --> "<<take.second<<endl;
      // cout<<s1<<endl;
    }

    return 0;
}