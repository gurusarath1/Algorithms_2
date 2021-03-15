#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  vector<int> ary = { -1, 3, 5, 1, 4, 2, -9 };
  int target = 6;
  
  int prefix_sum = 0;
  int complement;
  map<int, int> prefixSum_map;

  for (int i = 0; i < ary.size (); i++) {
      prefix_sum += ary[i];
      complement = prefix_sum - target;
      prefixSum_map[prefix_sum] = i;

      if (prefixSum_map.find(complement) != prefixSum_map.end()) {
          // sub-array found
          cout << "[ " << prefixSum_map[complement] + 1 << " , " << i << " ]"; // Print the index of subarray
          
      }
	}
	
	return 0;
}
