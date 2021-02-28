#include <vector>
#include <iostream>
#include <ostream>
#include <map>
#include <set>
#include <algorithm>

using std::cout;
using std::vector;
using std::endl;
using std::map;
using std::set;
using std::begin;
using std::end;
using std::sort;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;

        int len = nums.size();

        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(j);
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};


int main()
{
    // test vector 
    vector<int> nums{ 2,7,11,15 };
    int target = 9;

    Solution sol = Solution();

    vector<int> result = sol.twoSum(nums, target);

    cout << "Result: " << result.size() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
