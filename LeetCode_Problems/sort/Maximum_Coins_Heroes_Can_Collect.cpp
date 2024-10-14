class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {

        vector<vector<int>> monsters_coins;
        vector<vector<int>> heroes_index;

        for(int i=0; i<monsters.size(); i++) {
            monsters_coins.push_back( vector<int> {monsters[i], coins[i]} );
        }

        for(int i=0; i<heroes.size(); i++) {
            heroes_index.push_back( vector<int> {heroes[i], i} );
        }

        sort(monsters_coins.begin(), monsters_coins.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        } );

        sort(heroes_index.begin(), heroes_index.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        } );


        long long coins_collected = 0;
        int h = 0;
        int mc = 0;
        vector<long long> result(heroes.size());
        while(mc<monsters_coins.size() && h<heroes_index.size()) {

            int hero_strength = heroes_index[h][0];

            while(mc<monsters_coins.size() && hero_strength >= monsters_coins[mc][0]) {
                long long score = monsters_coins[mc][1];
                coins_collected += score;
                mc++;
            }

            result[heroes_index[h][1]] = coins_collected;
            h++;
        }

        while(h < heroes.size()) {
            result[heroes_index[h][1]] = coins_collected;
            h++;
        }

        return result;
        
    }
};
