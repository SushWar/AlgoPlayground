#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int seats[n], students[n];
  for(int i = 0; i < n; i++){
    cin >> seats[i];
  }
  for(int i = 0; i < n; i++){
    cin >> students[i];
  }
  
  int minMoves = 0;
  sort(seats, seats+n);
  sort(students, students+n);
  
  for(int i = 0; i < n; i++){
    minMoves += abs(seats[i] - students[i]);
  }
  
  cout << minMoves << '\n';
  
  return 0;
}