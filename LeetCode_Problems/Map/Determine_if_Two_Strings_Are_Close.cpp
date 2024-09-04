class Solution {
public:
    bool closeStrings(string word1, string word2) {

        map<int,int> w1_map;
        multiset<int> w1_set;
        map<int,int> w2_map;

        if(word1.size() != word2.size()) return false;
        if(word1 == word2) return true;

        for(char c : word1) {
            w1_map[c] = w1_map[c] + 1;
        }

        for(const auto &p : w1_map) {
            w1_set.insert(p.second);
        }

        for(char c : word2) {
            if(w1_map.find(c) == w1_map.end()) return false; // If new char exist return false
            w2_map[c] = w2_map[c] + 1;
        }

        for( const auto &p : w2_map) {
            if(w1_set.find(p.second) == w1_set.end()) {
                return false;
            } else {
                w1_set.erase(w1_set.find(p.second)); // Erase only one occurance
            }
        }

        return true;
    }
};
