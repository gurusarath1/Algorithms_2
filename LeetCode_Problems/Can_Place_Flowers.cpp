class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(n == 0) return true;

        bool prev_planted = false;
        bool next_planted;

        for(int i=0; i<flowerbed.size(); i++) {

            if(i == flowerbed.size() - 1) {
                next_planted = false;
            } else {
                next_planted = flowerbed[i+1];
            }

            if(flowerbed[i] == 0 && next_planted == false && prev_planted == false) {
                n--;
                flowerbed[i] = 1;
                if(n == 0) return true;
            }

            prev_planted = flowerbed[i];

        }

        return false;
        
    }
};
