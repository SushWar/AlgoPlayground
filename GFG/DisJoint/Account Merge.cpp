/*
Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.
*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disJointSet{
  vector<int>parent,rank,size;
  public:
  
    disJointSet(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        size.resize(n,0);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findParent(int baccha){
        
        if(baccha == parent[baccha]){
            return baccha;
        }
        
        return parent[baccha] = findParent(parent[baccha]);
    }
    
    void unionByRank(int baccha, int baap){
        
        int baccheKaBaap = findParent(baccha);
        int baapKaBaap = findParent(baap);
        
        if(baccheKaBaap == baapKaBaap) return;
        
        if(rank[baccheKaBaap] < rank[baapKaBaap]){
            parent[baccheKaBaap] = baapKaBaap;
        }
        else if(rank[baccheKaBaap] > rank[baapKaBaap]){
            parent[baapKaBaap] = baccheKaBaap;
        }
        else{
            parent[baccheKaBaap] = baapKaBaap;
            rank[baapKaBaap]++;
        }
    }
    
     void unionBySize(int baccha, int baap){
        
        int baccheKaBaap = findParent(baccha);
        int baapKaBaap = findParent(baap);
        
        if(baccheKaBaap == baapKaBaap) return;
        
        if(size[baccheKaBaap] < size[baapKaBaap]){
            parent[baccheKaBaap] = baapKaBaap;
            size[baapKaBaap] += size[baccheKaBaap];
        }
        else{
            parent[baapKaBaap] = baccheKaBaap;
             size[baccheKaBaap] += size[baapKaBaap];
        }
       
    }
    
    
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
        /*
            2 accounts belong to person if common email is there 
            
            account name with same name can be many
            
            same email on different name, then account can be merged
            
        */
        int n = accounts.size();
        disJointSet dumRoo(n);
        
        unordered_map<string,int>order;
        for(int i=0;i<n;i++){
            int sze = accounts[i].size();
            for(int j=1;j<sze;j++){
                string mail = accounts[i][j];
                
                if(order.find(mail) == order.end()){
                    order[mail] = i;
                }
                else{
                    dumRoo.unionBySize(i, order[mail]);
                }
            }
        }
        
        vector<string>adj[n];
        
        for(auto &it:order){
            string mail = it.first;
            int asliBaap = dumRoo.findParent(it.second);
            adj[asliBaap].push_back(mail);
        }
        
        vector<vector<string>>result;
        
        for(int i=0;i<n;i++){
            if(adj[i].size() == 0) continue;
            
            sort(begin(adj[i]),end(adj[i]));
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(string &st: adj[i]){
                temp.push_back(st);
            }
            
            result.push_back(temp);
        }
        
        return result;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends