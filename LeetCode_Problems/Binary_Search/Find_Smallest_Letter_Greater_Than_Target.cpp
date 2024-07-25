class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low = 0;
        int high = letters.size() - 1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);
            while(letters[mid] == target) {
                mid++;
                if(mid >= letters.size()) return letters[0]; // no characters in letters that is lexicographically greater
                if(letters[mid] != target) return letters[mid];
            }

            if(letters[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(low >= letters.size()) return letters[0]; // no characters in letters that is lexicographically greater

        return letters[low];
    }
};
