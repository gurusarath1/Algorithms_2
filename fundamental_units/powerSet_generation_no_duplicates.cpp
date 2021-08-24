
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePowerSet_support(vector<int> &input_set, vector<int> &current_set, vector<vector<int>> &power_set, int current_index);
    

void generatePowerSet(vector<int> &input_set) {
    
    vector<int> current_set;
    vector<vector<int>> power_set;
    
    generatePowerSet_support(input_set, current_set, power_set, input_set.size() - 1);
    
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
    
    if(current_index == -1) {
        power_set.push_back(current_set);
        return;
    }
 
    // Take the current element into the set
    current_set.push_back(input_set[current_index]);
    generatePowerSet_support(input_set, current_set, power_set, current_index - 1);
    current_set.pop_back();
    
    while (input_set[current_index] == input_set[current_index - 1]) {
        current_index--;
    }
    
    // Don't take the current element into the set
    generatePowerSet_support(input_set, current_set, power_set, current_index - 1);
    
}

int main()
{

    vector<int> testVec = {1,1,2,2};
    
    sort(testVec.begin(), testVec.end());

    generatePowerSet(testVec);

    return 0;
}


