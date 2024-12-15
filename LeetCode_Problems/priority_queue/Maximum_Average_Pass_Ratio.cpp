class Solution {
public:

    typedef pair<double, vector<int>> PQElement;

    static bool cmpr(PQElement& a, PQElement& b) {
        return a.first < b.first;
    }

    static double get_gain(PQElement& elem) {
        double ratio1 = (double)elem.second[1] / (double)elem.second[2];
        double ratio2 = (double)(elem.second[1] + 1) / (double)(elem.second[2] + 1);
        return ratio2 - ratio1;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue< PQElement, vector<PQElement>, function<bool(PQElement&, PQElement&)> > pq(cmpr);

        for(int i=0; i<classes.size(); i++) {
            PQElement elem;
            elem.second.push_back(i);
            elem.second.push_back(classes[i][0]);
            elem.second.push_back(classes[i][1]);
            elem.first = get_gain(elem);
            pq.push(elem);
        }

        for(int i=0; i<extraStudents; i++) {

            PQElement elem = pq.top();
            pq.pop();

            elem.second[1] += 1;
            elem.second[2] += 1;
            elem.first = get_gain(elem);

            pq.push(elem);
        }

        double result = 0;
        while(!pq.empty()) {
            result += (double)(pq.top().second[1]) / (double)(pq.top().second[2]);
            pq.pop();
        }

        return result / classes.size();
    }

};
