class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        map<int, set<int>> prereqs;
        map<int, set<int>> children;
        // init graph
        for(int i=1; i<=n; i++) {
            prereqs[i];
            children[i];
        }
        
        // Create two graphs 1) pre reqs 2) dependents
        for(vector<int> edge : relations) {
            prereqs[edge[1]].insert(edge[0]);
            children[edge[0]].insert(edge[1]);
        }
        
        queue<int> courses_that_can_be_taken_now;
        for(int i=1; i<=n; i++) {
            if(prereqs[i].size() == 0) {
                courses_that_can_be_taken_now.push(i);
            }
        }
        
        int sem = 0;
        int num_courses_left = n;
        while(!courses_that_can_be_taken_now.empty()) {
            sem++;
            int num_courses_in_q = courses_that_can_be_taken_now.size();
            
            for(int i=0; i<num_courses_in_q; i++) {
                int current_course = courses_that_can_be_taken_now.front();
                courses_that_can_be_taken_now.pop();
                
                for(set<int>::iterator it = children[current_course].begin(); it != children[current_course].end(); it++) {
                    int child = *it;
                    prereqs[child].erase(current_course);
                    
                    if(prereqs[child].size() == 0) {
                        courses_that_can_be_taken_now.push(child);
                    }
                }
            }
            
            num_courses_left -= num_courses_in_q;
            
        }
        
        if(num_courses_left > 0) return -1;
        
        return sem;
        
    }
};
