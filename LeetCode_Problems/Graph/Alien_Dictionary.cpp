class Solution {
public:
    
    string alienOrder(vector<string>& words) {
        
        map<char, vector<char>> graphX;
        vector<int> indegree(26,-1);
        string result = "";
        
        for(string s : words) {
            for(char c : s) {
                graphX[c];
                indegree[c - 'a'] = 0;
            }
        }
        
        // Build the graph
        for(int i=0; i<words.size()-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            
            int min_word_size = min(word1.size(), word2.size());
            
            int idx;
            for(idx=0; idx<min_word_size; idx++) {
                if(word1[idx] != word2[idx]) break;
            }
            
            // edge case : shorted string comes first
            if(idx == min_word_size && word1.size() > word2.size()) {
                return "";
            }
            
            // Word 1 is prefix of word 2
            if(idx == min_word_size) {
                // Nothing can of inferred
                continue;
            }
            
            graphX[word1[idx]].push_back(word2[idx]);
            indegree[word2[idx] - 'a'] += 1;
        }
        
        
        // DO top sort
        int visited = 0;
        queue<int> q;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            char c = q.front() + 'a';
            q.pop();
            visited++;
            
            result += c;
            
            for(char next_node : graphX[c]) {
                indegree[next_node - 'a']--;
                
                if(indegree[next_node - 'a'] == 0) {
                    q.push(next_node - 'a');
                }
            }
        }
        
        // Cycle detected ?
        if(visited != graphX.size()) {
            return "";
        }
        
        return result;
    }
    
};
