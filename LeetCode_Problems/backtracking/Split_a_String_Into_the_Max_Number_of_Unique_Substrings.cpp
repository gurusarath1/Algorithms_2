class Solution {
public:

    int max_strs = 0;

    int maxUniqueSplit(string s) {

        set<string> str_set;
        back_tracking(0, s, str_set);
        return max_strs;
    }

    void back_tracking(int start, string &s, set<string> sub_strs) {

        if(start == s.size()) {
            if(sub_strs.size() > max_strs) {
                max_strs = sub_strs.size();
            }
            return;
        }

        for(int end=start+1; end<=s.size(); end++) {

            string sub_str = s.substr(start, end-start);

            if(sub_strs.find(sub_str) == sub_strs.end()) {
                sub_strs.insert(sub_str);
                back_tracking(end, s, sub_strs);
                sub_strs.erase(sub_str);
            }

        }

    }
};
