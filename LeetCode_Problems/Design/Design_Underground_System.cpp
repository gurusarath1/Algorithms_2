class UndergroundSystem {
public:
    
    map< int , pair<string, double> > check_in_times;
    map< pair<string, string>, pair<int,int>> avg_times;

    UndergroundSystem() {
        ;
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in_times[id] = {stationName, (double)t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        string start_station = check_in_times[id].first;
        double start_time = check_in_times[id].second;
        
        pair<string, string> p = {start_station, stationName};
        
        if(avg_times[p].second == 0){
            avg_times[p].first = t - start_time;
            avg_times[p].second = 1;
        } else {
            avg_times[p].first = avg_times[p].first + (double)t - start_time;
            avg_times[p].second++;
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> p = {startStation, endStation};
        return (double)avg_times[p].first / (double)avg_times[p].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
