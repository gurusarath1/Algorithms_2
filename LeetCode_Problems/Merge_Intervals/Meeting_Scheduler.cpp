class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {

        sort(slots1.begin(), slots1.end(), [](vector<int> &a,  vector<int> &b) {
            return a[0] < b[0];
        });

        sort(slots2.begin(), slots2.end(), [](vector<int> &a,  vector<int> &b) {
            return a[0] < b[0];
        });

        int p1 = 0;
        int p2 = 0;
        while(p1 < slots1.size() && p2 < slots2.size()) {

            vector<int> overlap = ov_duration(slots1[p1], slots2[p2]);

            if(overlap.size()) {
                int overlap_duration = overlap[1] - overlap[0];

                if(overlap_duration >= duration) {
                    overlap[1] = overlap[0] + duration;
                    return overlap;
                }
            }

            if(slots1[p1][1] == slots2[p2][1]) { // same end time
                p1++;
                p2++;
            } else if(slots1[p1][1] > slots2[p2][1]) {
                p2++; // slots2 is the one with lower end time
            } else {
                p1++; // slots1 is the one with lower end time
            }

        }

        return vector<int>{};
    }

    vector<int> ov_duration(vector<int> &s1, vector<int> &s2) {
        if(s1[0] > s2[0]) { // s2 start time on the left

            if(s2[1] <= s1[0]) {
                return vector<int>{};
            } else if(s2[1] <= s1[1]) {
                return vector<int>{s1[0], s2[1]};
            } else if(s2[1] > s1[1]) {
                return vector<int>{s1[0], s1[1]};
            }

        } else if(s1[0] <= s2[0] && s2[0] < s1[1]) { // s2 start time in middle

            if(s2[1] <= s1[1]) {
                return vector<int>{s2[0], s2[1]};
            } else if(s2[1] > s1[1]) {
                return vector<int>{s2[0], s1[1]};
            }

        } else if(s2[0] >= s1[1]) { // s2 start time to the right side
            return vector<int>{};
        }
    
        return vector<int>{};

    }

};
