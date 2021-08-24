
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateCombinations_support(vector<int>& candidates, vector<int> &selections, vector<vector<int>> &all_selections, int number_of_selections_required, int selection_index, int start_index);

void generateCombinations(vector<int>& candidates, int number_of_selections_required) {
    
    
    vector<int> selections(number_of_selections_required,-1);
    vector<vector<int>> all_selections;
    
    generateCombinations_support(candidates, selections, all_selections, number_of_selections_required, 0, 0);
    
    // Print Output
    for(vector<int> s : all_selections) {
        cout << "[ ";
        for(int i : s) {
            cout << i << " ";
        }
        cout << "]\n";
    }
    
}


void generateCombinations_support(vector<int>& candidates, vector<int> &selections, vector<vector<int>> &all_selections, int number_of_selections_required, int selection_index, int start_index) {
    
    if(selection_index > number_of_selections_required - 1) {
        all_selections.push_back(selections);
        return;
    }
    
    
    for(int i=start_index; i<candidates.size(); i++) {
        
        // Skip duplicates
        if(i > start_index && candidates[i] == candidates[i-1]) continue;
        // Pick the current item
        selections[selection_index] = candidates[i];
        // Goto to choose the next item
        generateCombinations_support(candidates, selections, all_selections, number_of_selections_required, selection_index+1, i+1);
    }

    return;
    
}

int main()
{

    vector<int> testVec = {1,1,2,2,3,4};
    
    
    // Sort the input array
    sort(testVec.begin(), testVec.end());
    generateCombinations(testVec, 4);

    return 0;
}
