class Solution {
public:
    
    set<int> visited;
    map<int,bool> memo;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, set<int>> graph;
        
        for(vector<int> &c_p : prerequisites) {
            graph[c_p[0]].insert(c_p[1]);
        }
        
        
        set<int> temp_visited;
        for(int course=0; course<numCourses; course++) {
            
            if(visited.find(course) == visited.end()) {
                
                temp_visited.clear();
                bool is_DAG = is_DAG_check(graph, course, temp_visited);
                
                if(is_DAG == false) return false;
                
            }
            
        }
        
        return true;
        
        
    }
    
    
    bool is_DAG_check(map<int, set<int>> &graph, int current_course, set<int> &current_tree_visited) {
        
        visited.insert(current_course);
        
        if(memo.find(current_course) != memo.end()) {
            return memo[current_course];
        }
        
        if(current_tree_visited.find(current_course) != current_tree_visited.end()) {
            memo[current_course] = false;
            return false;
        }
        
        current_tree_visited.insert(current_course);
        

        
        if(graph.find(current_course) == graph.end()) {
            return true;
        } 
        
        set<int>::iterator it = graph[current_course].begin();
        
        while(it != graph[current_course].end()) {
            
            bool is_DAG = is_DAG_check(graph, *it, current_tree_visited);
            if(is_DAG == false) {
                memo[current_course] = false;
                return false;
            }
            
            current_tree_visited.erase(*it);
            it++;
        }
        
        memo[current_course] = true;
        return true;
    }
};
