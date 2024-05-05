
#include<bits/stdc++.h>
using namespace std;

int main(){
  // https://unstop.com/code/challange-asesment/250155?moduleId=429
    string a, b;
    cin >> a >> b;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == '#') {
            i--;
            while (i >= 0 && a[i] == '#') i--;
            if (i >= 0) i--;
        } else if (b[j] == '#') {
            j--;
            while (j >= 0 && b[j] == '#') j--;
            if (j >= 0) j--;
        } else if (a[i] != b[j]) {
            cout << "NO" << endl;
            return 0;
        } else {
            i--;
            j--;
        }
    }
    if (i == -1 && j == -1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}