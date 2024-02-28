#include <bits/stdc++.h>
#define pp pair<int,string>
using namespace std;

string longestPalindrome(const string& str) {
  int n = str.length();
  if (n == 0) return "";

  int start = 0, maxLength = 1;

  // Iterate through the string, considering every character as a potential center
  for (int i = 0; i < n; i++) {
    // Expand around center for odd-length palindromes
    for (int j = 0; i - j >= 0 && i + j < n && str[i - j] == str[i + j]; j++) {
      if (maxLength < 2 * j + 1) {
        start = i - j;
        maxLength = 2 * j + 1;
      }
    }

    // Expand around center for even-length palindromes
    for (int j = 0; i - j >= 0 && i + j + 1 < n && str[i - j] == str[i + j + 1]; j++) {
      if (maxLength < 2 * j + 2) {
        start = i - j;
        maxLength = 2 * j + 2;
      }
    }
  }

  return str.substr(start, maxLength);
}


int main() {
    /* https://unstop.com/code/challange-asesment/250143?moduleId=409 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len;
    cin>>len;
    string ravi;
    cin>>ravi;

    string result = longestPalindrome(ravi);
    cout<<result.length();

    return 0;
}