#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>mat, int row, int col, int target){

  int count = 0;
  for(int i=0;i<row;i++){
    for(int j=1;j<col;j++){
      mat[i][j] += mat[i][j-1];
    }
  }

  for(int start=0;start<col;start++){
    for(int end = start;end<col;end++){
      int tempSum = 0;
      // unordered_map<int,int>order;
      map<int,int>order;
      order[0] = 1;
      for(int i=0;i<row;i++){
        
        tempSum += mat[i][end] - (start ? mat[i][start-1] : 0);
        if(order.find(tempSum - target) != order.end()){
          // cout<<"Yes"<<endl;
          count += order[tempSum-target];
        }
        order[tempSum]++;
        // count += order.getOrDefault(tempSum-target, 0);
        // order.put(tempSum, order.getOrDefault(tempSum, 0)+1);
        // cout<<"start --> "<<start<<" , end --> "<<end<<" , row --> "<<i<<" , map.count() "<<(tempSum-target)<<endl;
      }
    }
  }
  return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
      
     0 1 0
     1 1 1
     0 1 0

    0 1 1
    1 2 3
    0 1 1
    target = 0;
    map = {
      0:1
      1:0
    }
    start = 0, end = 1, row = 0 => mat[row][end] - mat[row][start] = 1 => map.count(1-0) no
    start = 0, end = 1, row = 1 => mat[row][end] - mat[row][start] = 1+1 = >map.count()
    
    
    https://unstop.com/code/challange-asesment/250465?moduleId=418
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int row,col;
    cin>>row>>col;

    vector<vector<int>>mat(row);
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        int ele;
        cin>>ele;
        mat[i].push_back(ele);
      }
    }

    int target;
    cin>>target;
    int result = helper(mat, row, col, target);

    cout<<result<<endl;

    return 0;
}