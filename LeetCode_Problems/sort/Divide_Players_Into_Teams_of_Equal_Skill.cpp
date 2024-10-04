class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(), skill.end());

        int team_skill = 0;
        long long chem = 0;
        for(int i=0,j=skill.size()-1; i<j; i++,j--) {

            if(i == 0) {
                team_skill = skill[i] + skill[j];
            } else {
                if(skill[i] + skill[j] != team_skill) {
                    return -1;
                }
            }

            chem += (long long)skill[i] * (long long)skill[j];
        }

        return chem;
        
    }
};
