#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{

	vector<int> v;

	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	v.push_back(9);
	v.push_back(1);

	int target = 12;
	
	vector<int> out = twoSum(v, target);

	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << "   ";
	}

	cout << "\n";

	for(int i=0; i<out.size(); i++)
	{
		cout << out[i] << "   ";
	}

	return 0;
}


vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> x;

	map<int , int> m;

	int numToSearch = 0;
	m.insert( pair<int,int>(nums[0], nums[0]) );
	for(int i=1 ; i<nums.size(); i++)
	{
		numToSearch = target - nums[i];

		if(m.find(numToSearch) != m.end())
		{
			x.push_back(numToSearch);
			x.push_back(nums[i]);
			return x;
		}

		m.insert( pair<int,int>(nums[i], nums[i]) );
	}

	return x;
}