#include <bits/stdc++.h>
using namespace std;


int main() {

  /*
      01
      00111

      diff = 5 - 2 + 1 => 4
      first loop => ones = 2

      second loop => (i=0)result += 2 -> ones = 3 -> (i=1) result += (4-3) == 3 break;

      https://unstop.com/code/challange-asesment/250546?moduleId=407
  */
    
    string a, b;
    cin>>a>>b;

    long long int i, len1 = a.size(), len2 = b.size(), ones=0, sum=0;
    long long int diff = len2 - len1 + 1;

    for(i=0; i<diff; i++) {
        if(b[i] == '1') ones++;
    }

    for(int i=0; i<len1; i++) {
        if(a[i] == '0') sum +=ones;
        else sum += (diff - ones);
        if(i == len1-1) break;
        if(b[i] == '1') ones--;
        if(b[i+diff] == '1') ones++;
    }

    cout<<sum;
    return 0;
}
