#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);



        int i = 0, n = version1.size(), j = 0, m = version2.size();

        
        while(i<n && j<m){
            int currVer1 = 0, currVer2 = 0;
            while(i<n && version1[i] != '.'){
                currVer1 = (currVer1*10) + (version1[i]-'0');
                i++;
            }

            while(j<m && version2[j] != '.'){
                currVer2 = (currVer2*10) + (version2[j]-'0');
                j++;
            }

            if(currVer1 < currVer2){ return -1;}
            else if(currVer1 > currVer2){return 1;}

            i++;
            j++;
        }

        while(i<n){
            if(version1[i] != '.' && version1[i] > '0'){return 1;}
            i++;
        }

        while(j<m){
            if(version2[j] != '.' && version2[j] > '0'){return -1;}
            j++;
        }

        return 0;
        
    }
};