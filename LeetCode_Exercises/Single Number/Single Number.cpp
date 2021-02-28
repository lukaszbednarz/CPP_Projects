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
    int singleNumber(vector<int>& nums) {

        
        sort(nums.begin(), nums.end());
        int prev = 0;


        while(prev < nums.size() -1 && nums[prev]  == nums[prev +1]) {
            prev += 2;
        }
        return nums[prev];
    }

    int singleNumber2(vector<int>& nums) {

        int a = 0;

        for(int n: nums) a^=n;

        return a;
    }
};


int main()
{
    // test vector 
    vector<int> nums{ 4,1,2,1,2 };


    Solution sol = Solution();

    int result = sol.singleNumber2(nums);

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
