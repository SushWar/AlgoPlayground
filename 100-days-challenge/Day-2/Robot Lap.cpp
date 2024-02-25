#include <bits/stdc++.h>
using namespace std;


int main() {

    /*
        Problem Statement
            In a magical land, there is a young explorer named Raju who embarks on a thrilling adventure with his enchanted vehicle. This magical vehicle can only move in four directions: right (R), left (L), up (U), and down (D). Raju starts his journey at the heart of the mystical forest, located at coordinates (0, 0).

            As Raju follows a sequence of mysterious symbols etched on ancient stones, he maneuvers his magical vehicle accordingly. 'R' guides him to the right, 'L' to the left, 'U' upwards, and 'D' downwards. The direction he faces does not matter; the symbols' magic ensures his vehicle moves in the intended direction.

            Your mission is to help Raju determine whether he will return to the enchanted forest's center (0,0) after completing all his moves. If he successfully navigates back to the starting point, the forest's magic will protect him, and he will be able to continue his adventure. If not, he might be lost in the mystical realm forever.

            Can you assist Raju in deciphering his fate? If he ends up back at the starting point, please say YES; otherwise, say NO. (https://unstop.com/code/challange-asesment/250441?moduleId=406)

        Input Format
            The first line of the input contains an integer n  — the size of string moves
            The second line contains the string moves
        Output Format
            Raju needs to print ”YES” if car returns to origin, else “NO”.
        
        Sample Testcase 0
        Testcase Input
            6
            UUDDLR
        Testcase Output
            YES

  */
       
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int moves;
    cin>>moves;

    string dir;
    cin>>dir;

    int xAxis=0, yAxis=0;

    for(char &x: dir){
      if(x=='U'){
        yAxis++;
      }
      else if(x=='D'){
        yAxis--;
      }
      else if(x=='L'){
        xAxis++;
      }
      else{
        xAxis--;
      }
    }

    if(xAxis==0 && yAxis==0){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
    return 0;
}