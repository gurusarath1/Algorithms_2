class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> max_left_height(height.size());
        vector<int> max_right_height(height.size());

        int max_left = 0;
        for(int i=0; i<height.size(); i++) {
            max_left_height[i] = max_left;
            max_left = max(max_left, height[i]);
        }

        int max_right = 0;
        for(int i=height.size()-1; i>=0; i--) {
            max_right_height[i] = max_right;
            max_right = max(max_right, height[i]);
        }

        int total_amount = 0;
        for(int i=0; i<height.size(); i++) {
            int amount = min(max_right_height[i], max_left_height[i]) - height[i];
            if(amount > 0) {
                total_amount += amount;
            }
        }

        return total_amount;
    }
};
