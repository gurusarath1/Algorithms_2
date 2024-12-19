class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int start=0;
        int end=0;

        set<int> in_chunk;
        int num_chunks = 0;
        while(end < arr.size()) {
            in_chunk.insert(arr[end]);

            int max_in_chunk = *prev(in_chunk.end());
            int min_in_chunk = *in_chunk.begin();

            if(max_in_chunk <= end && min_in_chunk >= start) {
                start = end+1;
                end = start;
                num_chunks++;
                in_chunk.clear();
            } else {
                end++;
            }
        }

        return num_chunks;
    }
};
