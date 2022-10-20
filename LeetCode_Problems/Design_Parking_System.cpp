class ParkingSystem {
public:
    
    map<int,int> parking;
    
    ParkingSystem(int big, int medium, int small) {
        
        parking[1] = big;
        parking[2] = medium;
        parking[3] = small;
        
    }
    
    bool addCar(int carType) {
        
        if(parking[carType] == 0) return false;
        
        parking[carType]--;
        
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
