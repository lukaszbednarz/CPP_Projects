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
    vector<int> plusOne(vector<int>& digits) {


        int carry = 1;
        int pos = digits.size() - 1;
        int tmp = 0;
        while (carry && pos >= 0)
        {
            tmp = digits[pos] + 1;
            digits[pos] = tmp % 10;
            carry = tmp / 10;
 
            pos--;
        }

        if (carry) {
            digits.insert(digits.begin(), carry);
        }

        return digits;

    }
};


int main()
{
    // test vector 
    vector<int> nums{ 9 };



    Solution sol = Solution();

    vector<int> result = sol.plusOne(nums);

    cout << "Result: " << result[result.size() -1] << endl;
}

