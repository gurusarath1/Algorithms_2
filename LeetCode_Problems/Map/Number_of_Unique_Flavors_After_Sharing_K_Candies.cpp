class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {

        map<int,int> elements_outside_window;
        set<int> unique_elements_outside_window; // Number of unique flavors that you have at a given time
        int max_falvors = 0;

        // Add all elements outside the window
        for(int i=k; i<candies.size(); i++) {
            elements_outside_window[candies[i]] += 1;
            unique_elements_outside_window.insert(candies[i]);
        }

        // Slide the window[0 to (k-1)] and keep track of elements outside the window
        for(int i=k+1, j=0; i<=candies.size(); i++, j++) {

            // Check the number of unique flavors that you have
            if(unique_elements_outside_window.size() > max_falvors) {
                max_falvors = unique_elements_outside_window.size();
            }

            elements_outside_window[candies[i-1]] -= 1; // remove the last element (now inside the window)
            elements_outside_window[candies[j]] += 1; // add the current element (now outside the window)
            if(elements_outside_window[candies[i-1]] == 0) { // If element does not exist outside the window
                unique_elements_outside_window.erase(candies[i-1]); // delete from unique set
            }
            unique_elements_outside_window.insert(candies[j]);// add the current element (now outside the window)
        }

        // Check the number of unique flavors that you have
        if(unique_elements_outside_window.size() > max_falvors) {
            max_falvors = unique_elements_outside_window.size();
        }

        return max_falvors;
    }
};
