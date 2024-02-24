#include <bits/stdc++.h>
using namespace std;


int main() {

    /*
    Problem statement :- Once upon a time, a city biker embarked on an exciting road trip. This journey was laid out across a sequence of n+1 points, 
    each with varying altitudes. The biker's adventure commenced at point 0, where the altitude was a humble 0 meters above sea level.During his expedition, 
    he encountered different terrains. For every segment between points i and i+1, where 0≤i<n, the biker faced varying challenges in altitude. 
    Each segment was represented by an integer array called gain of length n, where gain[i] denoted the net gain in altitude between points i and i+1.
    The biker's goal was to find the highest altitude he reached during his journey. This altitude was determined by the net gain in alttude at each point along the way. 
    It could be a thrilling peak or a serene valley, depending on the varying gains between consecutive points. (https://unstop.com/code/challange-asesment/250431?moduleId=372)

    Input format :- The first line of the input contains an integer n  - the number of elements.
                    The next  line contains n space-separated integers.

    TestCase input :- 
    [
      4
      1 -3 5 7
    ]

    TestCase output :-
    [
      10
    ]
  */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int altitude[n];

    for(int i=0;i<n;i++){
      cin>>altitude[i];
    }

    int highestAltitude = 0, sum = 0;

    for(int i=0;i<n;i++){
      sum+=altitude[i];
      highestAltitude = max(highestAltitude, sum);
    }

    cout<<highestAltitude<<endl;

    return 0;
}