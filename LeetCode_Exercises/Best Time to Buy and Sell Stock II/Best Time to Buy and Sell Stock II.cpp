// Best Time to Buy and Sell Stock II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2) return 0;

        int last_min = 0, last_max = 0, profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main()
{
    

    // test vector 
    vector<int> nums{ 7,6,4,3,1 };


    Solution sol = Solution();

    int result = sol.maxProfit(nums);

    cout << "Result: " << result << endl;
}

