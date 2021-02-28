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
    void moveZeroes(vector<int>& nums) {

        int n = 0;
        int last_zero_pos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) {
                last_zero_pos = i;
                n++;
                continue;
            }
            if (n) {
                nums[i - n] = nums[i];
            }
        }

        for (int i = 1; i <= n; i ++)
        {
            nums[nums.size() - i] = 0;
        }


    }
};


int main()
{
    // test vector 
    vector<int> nums{ 0, 1,0 };



    Solution sol = Solution();

    sol.moveZeroes(nums);

    cout << "Result: " << nums[nums.size()] << endl;
}

