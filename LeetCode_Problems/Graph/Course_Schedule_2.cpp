class Solution {
public:
    
        
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> outlinks;
        priority_queue<int> pq;
        vector<int> indegree_count(numCourses, 0);
        int visited_count = 0;
        
        for(vector<int> preq : prerequisites) {
           outlinks[preq[1]].push_back(preq[0]);
            indegree_count[preq[0]] += 1;
        }
        
        for(int i=0; i<numCourses; i++) {
            if( indegree_count[i] == 0 ) {
                pq.push( i );
            }
        }
        
        while(!pq.empty()) {
            int current_course = pq.top();
            pq.pop();
            
            indegree_count[current_course] -= 1;
            visited_count += 1;
            
            for(int next_course : outlinks[current_course]) {
                indegree_count[next_course] -= 1;
                if(indegree_count[next_course] == 0) {
                    pq.push(next_course);
                }
            }
            
        }
        
        if(visited_count == numCourses) return true;
        
        return false;
    }
};
