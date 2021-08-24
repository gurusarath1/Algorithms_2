#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePowerSet_support(vector<int> &input_set, vector<int> &current_set, vector<vector<int>> &power_set, int current_index);
    

void generatePowerSet(vector<int> &input_set) {
    
    vector<int> current_set;
    vector<vector<int>> power_set;
    
    generatePowerSet_support(input_set, current_set, power_set, 0);
    
    // Pint the power set
    for(vector<int> set : power_set) {
        
        cout << "[ ";
        for(int x : set) {
            cout << x << " ";
        }
        cout << "]\n";
    }
    
}


void generatePowerSet_support(vector<int> &input_set, vector<int> &current_set, vector<vector<int>> &power_set, int current_index) {
    
    if(current_index == input_set.size()) {
        power_set.push_back(current_set);
        return;
    }
    
    // Take the current element into the set
    generatePowerSet_support(input_set, current_set, power_set, current_index + 1);
    
    // Don't take the current element into the set
    current_set.push_back(input_set[current_index]);
    generatePowerSet_support(input_set, current_set, power_set, current_index + 1);
    current_set.pop_back();
    
}

int main()
{

    vector<int> testVec = {1,2,3};

    generatePowerSet(testVec);

    return 0;
}


