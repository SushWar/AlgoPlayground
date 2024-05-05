#include <iostream>
#include <vector>

using namespace std;

const int N = 10010;
vector<pair<int, int>> h[N];

int hashFunc(int key) {
    return key % N;
}

void insert(int key, int value) {
    int idx = hashFunc(key);
    for (int i = 0; i < h[idx].size(); i++) {
        if (h[idx][i].first == key) {
            h[idx][i].second = value;
            return;
        }
    }
    h[idx].push_back({key, value});
}

int get(int key) {
    int idx = hashFunc(key);
    for (int i = 0; i < h[idx].size(); i++) {
        if (h[idx][i].first == key) {
            return h[idx][i].second;
        }
    }
    return -1;
}

void del(int key) {
    int idx = hashFunc(key);
    for (int i = 0; i < h[idx].size(); i++) {
        if (h[idx][i].first == key) {
            h[idx].erase(h[idx].begin() + i);
            return;
        }
    }
}

int main() {

  // https://unstop.com/code/challange-asesment/250158?moduleId=429
  
    int n;
    cin >> n;
    while (n--) {
        int type, key, value;
        cin >> type;
        if (type == 1) {
            cin >> key >> value;
            insert(key, value);
        } else if (type == 2) {
            cin >> key;
            cout << get(key) << endl;
        } else {
            cin >> key;
            del(key);
        }
    }
    return 0;
}
                