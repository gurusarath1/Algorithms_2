class Solution {
public:
    int countPalindromicSubsequence(string s) {

        unordered_map<char, pair<int,int> > unique_start_end;

        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(unique_start_end.find(c) != unique_start_end.end()) {
                unique_start_end[c].second = i;
            } else {
                unique_start_end[c].first = i;
                unique_start_end[c].second = i;
            }
        }

        int ans = 0;
        for(auto &p : unique_start_end) {

            unordered_set<char> unique_inbetween;
            if(p.second.first == p.second.second) continue;
            unique_inbetween.insert( next(s.begin(),p.second.first+1), next(s.begin(),p.second.second));

            ans += unique_inbetween.size();
        }
        
        return ans;
    }
};
