class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xors = 0;
        for(int n : derived) {
            xors ^= n;
        }

        if(xors  == 0) return true;

        return false;
    }
};
