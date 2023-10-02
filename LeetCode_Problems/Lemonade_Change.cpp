class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int my_money = 0;

        map<int, int> change_bills;
        change_bills[5] = 0;
        change_bills[10] = 0;
        change_bills[20] = 0;
        
        for(int bill : bills) {
            int change = bill - 5;
            my_money += 5;
            if(change > my_money) return false;
            change_bills[bill] += 1;

            if(change == 0) {
                ;
            } else if(change == 5) {

                if(change_bills[5] <= 0) return false;
                change_bills[5] -= 1;

            } else if (change == 10) {

                 if(change_bills[10] > 0) {
                     change_bills[10] -= 1;
                 } else {
                     if(change_bills[5] <= 1) return false;
                     change_bills[5] -= 2;
                 }

            } else if (change == 15) {

                if(change_bills[10] >= 1 && change_bills[5] >= 1) {
                    change_bills[10] -= 1;
                    change_bills[5] -= 1;
                } else {
                    if(change_bills[5] <= 2) return false;
                    change_bills[5] -= 3;
                }                    

            }

            my_money -= change;
        }
        
        return true;
    }
};
