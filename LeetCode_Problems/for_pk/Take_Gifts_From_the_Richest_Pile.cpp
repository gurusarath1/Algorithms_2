class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        long long total_gifts = 0;
        for(int g : gifts) {
            total_gifts += g;
            pq.push(g);
        }

        for(int i=0; i<k; i++) {
            int top_pile = pq.top();
            pq.pop();
            int gifts_to_leave = (int)sqrt(top_pile);
            pq.push(gifts_to_leave);
            total_gifts -= (top_pile - gifts_to_leave);
        }

        return total_gifts;
    }
};
