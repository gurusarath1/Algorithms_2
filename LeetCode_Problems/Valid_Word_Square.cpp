class Solution {
public:
    bool validWordSquare(vector<string>& words) {

        int max_row = words.size();

        int max_col = 0;
        for(string &w : words) {
            if(max_col < w.size()) max_col = w.size();
        }

        if(max_row != max_col) return false; // Not a square

        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<i; j++) {

                if(words[i].size() <= j && words[j].size() <= i) continue; // Char missing in both strings

                if(words[i].size() > j && words[j].size() > i ) {
                    if(words[i][j] != words[j][i]) return false;
                } else {
                    return false; // Char missing in one of the string
                }
            }
        }

        return true;
    }
};
