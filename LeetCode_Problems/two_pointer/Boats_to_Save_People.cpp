class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());

        int l=0, r=people.size() - 1;
        int num_boats = 0;
        while(l <= r) {
            if(people[l] + people[r] <= limit) {
                // Two people can sit in this boat
                l++; r--;
            } else {
                // Only one person can sit in this boat
                r--; // pick the heavy one
            }
            num_boats += 1;
        }
        return num_boats;
    }
};
