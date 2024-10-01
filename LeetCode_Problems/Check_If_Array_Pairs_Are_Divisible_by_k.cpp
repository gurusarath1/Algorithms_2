class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        vector<int> rems(k);

        for(int num : arr) {
            int rem = ((num % k) + k) %k;
            rems[rem] += 1;
        }

        if( (rems[0] & 1) != 0) return false;

        for(int rem=1; rem <= k/2; rem++) {
            int other_rem = k - rem;
            cout << rem << " -- " << other_rem << endl;
            if(rems[rem] != rems[other_rem]) return false;
        }
   
        return true;
    }
};
