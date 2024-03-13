class Solution {
public:
    int pivotInteger(int n) {

        /*

            1 2 3 4 5 6 7 8

            1-1 1-8
            1-2 2-8
            1-3 3-8
            https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13
        */

        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += i;
        }
        
        int tempSum = 0;
        // if(tempSum == sum){return 1;}

        for(int i=1;i<=n;i++){
            tempSum += i;
            sum -= (i-1);
            if(tempSum == sum){return i;}

        }

        // int tempSum = 0;
        

        return -1;
    }
};