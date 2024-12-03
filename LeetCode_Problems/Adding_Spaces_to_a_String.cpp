class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        set<int> spaces_set;

        for(int s : spaces) spaces_set.insert(s);

        string out = "";
        for(int i=0; i<s.size(); i++) {

            if(spaces_set.find(i) != spaces_set.end()) {
                out += ' ';
            }

            out += s[i];
        }
        
        return out;
    }
};
