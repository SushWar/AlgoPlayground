#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


int helper(vector<vector<char>>board, pp position){

int count = 0;
int i = position.first, j = position.second;
// cout<<"POS --> "<<i<<" , "<<j<<endl;
//up
for(int k=i;k>=0;k--){
  // cout<<"Trvelling up"<<endl;
  if(board[k][j] == 'p'){
    // cout<<"Inside"<<endl;
    count++;
    break;
  }
  else if(board[k][j] == 'B'){
    break;
  }
}

//right
for(int k=j;k<8;k++){
  // cout<<"Trvelling right"<<endl;
  if(board[i][k] == 'B'){
    break;
  }
  else if(board[k][j] == 'p'){
    // cout<<"Inside"<<endl;
    count++;
    break;
  }
}

//down
for(int k=i;k<8;k++){
  // cout<<"Trvelling Down"<<endl;
  if(board[k][j] == 'B'){
    break;
  }
  else if(board[k][j] == 'p'){
    // cout<<"Inside"<<endl;
    count++;
    break;
  }
}

//left
for(int k=j;k>=0;k--){
  // cout<<"Trvelling left"<<endl;
  if(board[i][k] == 'B'){
    break;
  }
  else if(board[i][k] == 'p'){
    // cout<<"Inside"<<endl;
    count++;
    break;
  }
}

return count;
  
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250511?moduleId=420
    
    */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<char>>board(8);
    pp position;

    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        char val;
        cin>>val;
        board[i].push_back(val);

        if(val == 'R'){
          position = {i,j};
        }
        // cout<<board[i][j]<<" ";
      }
      // cout<<endl;
    }

    
    int result = helper(board, position);
    cout<<result<<endl;
    return 0;
}