class Solution {
public:

    int max_area = 0;

    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        support(l, r, height);

        return max_area;
        
    }

    void support(int l, int r, vector<int>& height) {

        if(l < r) {
            int area = min(height[l], height[r]) * (r - l);

            if(area > max_area) {
                max_area = area;
            }

            if(height[l] > height[r]) {
                support(l, r-1, height);
            } else if (height[l] < height[r]) {
                support(l+1, r, height);
            } else {
                support(l+1, r-1, height);
            }

        } else {
            return;
        }

    }
};
