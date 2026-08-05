class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last_occ;
        for(int i=0; i<s.size(); i++) {
            last_occ[s[i]] = i;
        }
        
        int l=0, r=l;
        vector<int> chunk_sizes;

        // l represents the start of a chunk
        while(l<s.size())
        {
            // chunk end point to include all of this char
            int chunk_end = last_occ[s[l]];

            // Build the chunk
            while(r < chunk_end) {
                if(last_occ[s[r]] > chunk_end) {
                    chunk_end = last_occ[s[r]]; // Expand chunk
                }
                r++;
            }

            // if while loop exits - chunk end reached
            chunk_sizes.push_back(r - l + 1);

            // Start new chunk
            l=r+1;
            r=l;
        }

        return chunk_sizes;
    }
};
