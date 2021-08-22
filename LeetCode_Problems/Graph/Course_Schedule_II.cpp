class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> inDegrees(numCourses, 0);
        map<int, vector<int>> graph;
        vector<int> result;
        
        for(vector<int> course_preqs : prerequisites) {
            inDegrees[course_preqs[0]] += 1;
            graph[course_preqs[0]].push_back(course_preqs[1]);
        }
        
        queue<int> q;
        
        while(1) {
            for(int i=0; i<inDegrees.size(); i++) {
                if(inDegrees[i] == 0) {
                    inDegrees[i] = -1;
                    q.push(i);
                }
            }

            if(q.empty()) {
                
                if(result.size() < numCourses) {
                    result.clear();
                }
                
                return result;
            }

            while(!q.empty()) {
                
                for(int i=0; i<inDegrees.size(); i++) {
                    if(inDegrees[i] > 0) {
                        if( find(graph[i].begin(), graph[i].end(), q.front()) != graph[i].end() ) {
                            inDegrees[i] = inDegrees[i] - 1;
                        }
                    }
                }
                
                result.push_back(q.front());
                q.pop();
            }
        }
        
        return result;
        
    }
};
