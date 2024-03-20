#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unsigned int findPair(unsigned int n) {
  // Invert all bits and subtract 1 (Two's complement) https://unstop.com/code/challange-asesment/250914?moduleId=424
  return ~n;
}

int main() {
  unsigned int n;

  cin >> n;

  unsigned int m = findPair(n);

  cout << m << endl;

  return 0;
}