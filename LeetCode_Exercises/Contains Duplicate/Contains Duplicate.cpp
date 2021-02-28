// Remove Duplicates from Sorted Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
using std::sort;


class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        set<int> set;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end()) return true;
            set.emplace(nums[i]);
        }

        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

int main()
{
    // test vector 
    vector<int> nums{ 1,2,3,1 };


    Solution sol = Solution();

    bool result = sol.containsDuplicate2(nums);

    cout << "Result: " << result << endl;
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
