#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

void option1(int n, vector<pp>&order){

  sort(begin(order),end(order));

  int result = -1;
  for(int i=1;i<n;i++){
    int prev = order[i-1].first;
    int present = order[i].first;
    result = max(result, (present- prev));
  }

  cout<<result<<endl;
  return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT
    
          
             .. .       . .
          1 2 3 4 5 6 7 8 9

          https://unstop.com/code/challange-asesment/250471?moduleId=417
     */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;

    vector<pp>order(n);

    for(int i=0;i<n;i++){
      int x, y;
      cin>>x>>y;

      order[i] = {x,y};
    }

    option1(n, order);

    return 0;
}