class Solution {
public:
    int hIndex(vector<int>& citations) {

        int low = 0;
        int high = citations.size() - 1;
        int num_papers = citations.size();
        int h_index = 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(citations[mid] == (num_papers - mid) ) {
                return citations[mid];
            } else if(citations[mid] < (num_papers - mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        return num_papers - low;

    }
};
