/* The knows API is defined for you.
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
