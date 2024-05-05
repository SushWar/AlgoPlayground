#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

class Tree{
  int result;
  public:
  
  Tree(){
    result = 0;
  }

  int travel(int idx ,vector<pp>graph[]){
    if(idx == -1){return 0;}
    int left = graph[idx][0].first, right = graph[idx][0].second;

    // if(left == -1 && right == -1){
    //   return 0;
    // }
    // cout<<"At IDX --> "<<idx<<"  left child -> "<<left<<" right child -> "<<right<<endl;

    int goLeft = travel(left, graph);
    int goRight = travel(right, graph);
    result = max(result, (goLeft+goRight));

    return 1 + max(goRight, goLeft);
  }

  int helper(int city, vector<pp>graph[]){
    
    int temp = travel(1, graph);
    // cout<<"Temp --> "<<temp<<endl;
    return result;
  }
};



int main() {
    /* https://unstop.com/code/challange-asesment/250159?moduleId=411
    
    1  5 3
    2  -1 -1
    3  -1 -1
    4  -1 -1
    5  7 2
    6  -1 4
    7  6 -1
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int city;
    cin>>city;
    vector<pp>graph[city+1];

    for(int i=1;i<=city;i++){
      int left,right;
      cin>>left>>right;

      graph[i].push_back({left,right});
    }

    

    //checking 
    // for(int i=1;i<=city;i++){
    //   cout<<"Graph --> "<<i<<" --> {"<<graph[i][0].first<<" , "<<graph[i][0].second<<" }"<<endl;
    // }

    Tree newTree;
    int result = newTree.helper(city, graph);

    cout<<result<<endl;

    return 0;
}