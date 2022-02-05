class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        map<int,int> num_count;
        set<int> nums_in_window;
        priority_queue<int> pq;
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++) {
            
            if(i < k) {
                nums_in_window.insert(nums[i]);
                num_count[nums[i]] += 1;
                pq.push(nums[i]);
                
            } else {
              
                result.push_back(pq.top());
                
                if(num_count[nums[i - k]] == 1) {
                    num_count[nums[i - k]] = 0;
                    nums_in_window.erase(nums[i - k]);
                    
                    while(nums_in_window.find(pq.top()) == nums_in_window.end()) {
                        pq.pop();
                        if(pq.size() == 0) break;
                    }
                    
                } else {
                    num_count[nums[i - k]] -= 1;
                }

                nums_in_window.insert(nums[i]);
                num_count[nums[i]] += 1;
                pq.push(nums[i]);
                
            }
        }
        
        // The last window wont be considered in the loop
        // So we add the max number in the last window outside the loop
        result.push_back(pq.top());
        
        
        return result;
        
    }
};
