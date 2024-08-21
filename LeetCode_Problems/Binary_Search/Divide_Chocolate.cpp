class Solution {
public:

    int get_num_cuts(vector<int>& sweetness, int min_sweetness_in_a_chunk) {

        int current_chuck_sweetness = 0;
        int num_cuts = 0;
        for(int s : sweetness) {
            current_chuck_sweetness += s;
            if(current_chuck_sweetness > min_sweetness_in_a_chunk) {
                current_chuck_sweetness = 0;
                num_cuts++;
            }
        }

        return num_cuts;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {

        int min_sweet = INT_MAX;
        int max_sweet = 0;
        for(int s : sweetness) {
            max_sweet += s;
            if(min_sweet > s) min_sweet = s;
        }
        
        int low = min_sweet;
        int high = max_sweet;

        while(low <= high) {

            int min_sweetness_req = low + (high - low) / 2;
            int num_cuts = get_num_cuts(sweetness, min_sweetness_req);

            if(num_cuts > k) {
                low = min_sweetness_req + 1; // increase sweetness
            } else {
                high = min_sweetness_req - 1; // decrease sweetness
            } 

        }

        if(low == max_sweet + 1) return max_sweet;
    
        return low;
    }
};
