class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int start_index = 0;
        map<int, int> tree_fruit_type_count;
        int max_fruits = 0;
        
        for(int end_index = 0; end_index < tree.size(); end_index++) {
            
            tree_fruit_type_count[tree[end_index]] += 1;
            
            while(tree_fruit_type_count.size() > 2) {
                tree_fruit_type_count[tree[start_index]] -= 1;
                if(tree_fruit_type_count[tree[start_index]] == 0) tree_fruit_type_count.erase(tree[start_index]);
                start_index++;
            }
            
            
            if(tree_fruit_type_count.size() <= 2) {
                max_fruits = max(max_fruits,  end_index - start_index + 1);
            }
            
        }
        
        return max_fruits;
    }
};
