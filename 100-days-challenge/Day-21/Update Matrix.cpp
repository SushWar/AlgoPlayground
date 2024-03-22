#include<bits/stdc++.h>
using namespace std;

int oddCells(int n, int m, vector<vector<int>>& indices) 
{
    vector<bool> N(n, false);
    vector<bool> M(m, false);

    for(int i=0; i<indices.size(); i++) 
    {
        N[indices[i][0]] = N[indices[i][0]]^true;
        M[indices[i][1]] = M[indices[i][1]]^true;
    }

    int r = 0;
    int c = 0;

    for(int i=0; i<n; i++) 
    {
        if(N[i])
            r++;
    }

    for(int j=0; j<m; j++) 
    {
        if(M[j])
            c++;
    }

    return  r*m + c*n - 2*r*c;
}

void solve()
{
  int n,m; 
  cin>>n>>m;

  int q; 
  cin>>q;
  vector<vector<int>> indices;

  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    indices.push_back({a,b});
  }
  cout<<oddCells(n,m,indices);
}

signed main()
{ 
  //https://unstop.com/code/challange-asesment/250604?moduleId=425
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
    
    return 0;
}