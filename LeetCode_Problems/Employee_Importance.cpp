/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int imp = 0;
        
        Employee* employee;
        map<int, pair<int,vector<int>> > emp_imp_map;
        
        for(int i=0; i<employees.size(); i++) {
            if(employees[i]->id == id) {
                employee = employees[i];
            }
            
            emp_imp_map[employees[i]->id] = pair<int,vector<int>> {employees[i]->importance, employees[i]->subordinates};
        }
        
        imp += employee->importance;
        
        queue<int> subord_q;
        
        for(int s : employee->subordinates) {
            subord_q.push(s);
        }
        
        while(!subord_q.empty()) {
            
            imp += emp_imp_map[subord_q.front()].first;
                
            for(int s : emp_imp_map[subord_q.front()].second) {
                subord_q.push(s);
            }
            
            subord_q.pop();            
        }
        
        return imp;
        
    }
};
