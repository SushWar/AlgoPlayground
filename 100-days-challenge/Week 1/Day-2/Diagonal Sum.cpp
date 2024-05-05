#include <bits/stdc++.h>
using namespace std;


int main() {
    
        /*
        Problem Statement
            One day, Chris arrived at the entrance of Adventureland. There is an n × n magic grid on the entrance, which is filled with only 1s.

            Any person gets the entry when they count the sum of the diagonal integers right. Chris is working on counting the sum.

            Can you help him to solve it fast? (https://unstop.com/code/challange-asesment/250506?moduleId=406)


        Input Format
            The first line of input consists of integer n – representing the number of rows and columns of the matrix.

        Output Format
            Print a single line of output consisting of the sum of the diagonal integers

        Sample Testcase 0
            Testcase Input
                2
            Testcase Output
                4
  */
    int n;
    cin>>n;
   
    int result = n*2;

    if(n%2 != 0) result--;
      
    cout<<result<<endl;
    
    
    return 0;
}