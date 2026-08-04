/* 

Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity.
The definition of a celebrity is that all the other n - 1 people know the celebrity,
but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one.
You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B.
You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given an integer n and a helper function bool knows(a, b) that tells you whether a knows b.
Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

Note that the n x n 2D array graph given as input is not directly available to you,
and instead only accessible through the helper function knows. graph[i][j] == 1 represents person i knows person j,
wherease graph[i][j] == 0 represents person j does not know person i.




The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {

        // Get the possible candidate for a celebrity
        int potential_celeb = get_potential_celebrity(n);

        // Check if he is a celebrity
        if(is_celebrity(potential_celeb, n)) {
            return potential_celeb;
        }

        return -1;
    }

    int get_potential_celebrity(int n) {

        int potential_celeb = 0;

        for(int i=1; i<n; i++) {
            // In every comparision we can conclusively eliminate one person
            if(knows(potential_celeb, i)) {
                potential_celeb = i;
            }
        }

        return potential_celeb;
    }

    bool is_celebrity(int c, int n) {

        for(int i=0; i<n; i++) {

            if(i == c) continue; // celeb knows him!! no check

            // Celebrity doesn't know anyone
            if(knows(c,i)) {
                return false;
            }

            // Every one knows celebrity
            if(!knows(i,c)) {
                return false;
            }
        }

        return true;
    }
};
