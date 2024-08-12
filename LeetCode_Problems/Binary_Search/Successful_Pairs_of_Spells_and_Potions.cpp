class Solution {
public:

    int binary_search(vector<int>& potions, double target) {
        int low = 0;
        int high = potions.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(potions[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<int> ret;
        sort(potions.begin(), potions.end());

        for(int i=0; i<spells.size(); i++) {

            int spell_strength = spells[i];
            double min_potion_stength = (double)success / (double)spell_strength;

            int index = binary_search(potions, min_potion_stength);

            ret.push_back(potions.size() - index);
        }

        return ret;
        
    }
};
