class Solution {
public:
    class Compare
    {
    public:
        bool operator() (vector<int> &a, vector<int> &b)
        {
            return a[1] >= b[1]; // based on end time (highest end time first)
        }
    };
    

    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        priority_queue<int> available_seats;
        for(int i=0; i<times.size(); i++) {
            times[i].push_back(i);
            available_seats.push(-i); // Change max heap to min heap by adding a minus sign
        }

        // Sort based on start time (lowest start time first)
        sort(times.begin(), times.end(), [](vector<int> &a, vector<int> &b)
            {
                if(a[0] < b[0]) return true;
                return false;
            }
        );

        // Priority queue sorted based on end time (highest end time first)
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for(int i=0; i<times.size(); i++) {

            int start_time = times[i][0];
            int end_time = times[i][1];
            int person = times[i][2]; // current person
            int x = 0;
            
            // remove all people that completed sitting
            while(!pq.empty() && pq.top()[1] <= start_time) {
                int seat_of_this_person = pq.top()[3]; // get the room of the person
                available_seats.push(-seat_of_this_person); // make the room available
                pq.pop(); // remove the person
            }


            int seat = -available_seats.top(); // min available room number

            if(person == targetFriend) {
                return seat;
            }

            /*
                vector format in pq -----
                times[0] = start time
                times[1] = end time
                times[2] = person index
                times[3] = seat of person
            */

            available_seats.pop();
            times[i].push_back(seat);
            pq.push(times[i]);
        }

        return 0; // wont reach        
    }
};
