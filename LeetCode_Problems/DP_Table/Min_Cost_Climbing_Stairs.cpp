class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> min_costs(cost.size(), 0);

        min_costs[0] = cost[0];
        min_costs[1] = cost[1];

        for(int i=2; i<cost.size(); i++) {
            min_costs[i] = min(min_costs[i-1], min_costs[i-2]) + cost[i];
        }

        return min(min_costs[cost.size() -1], min_costs[cost.size() -2]);
    }
};
