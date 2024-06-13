class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int min_shifts = 0;
        for(int i=0; i<students.size(); i++) {
            min_shifts += abs(students[i] - seats[i]);
        }

        return min_shifts;
    }
};
