// Rotate Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <ostream>
using std::cout;
using std::vector;
using std::endl;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (k == 0) return;

        for (int i = 0; i < k; i++) {

            int tmp = nums[nums.size() - 1];
            nums.pop_back();
            nums.insert(nums.begin(), tmp);

        }

    }

    void rotate2(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; cnt < nums.size(); i++) {
            int current = i;
            int prev = nums[i];
            do {
                int next = (current + k) % nums.size();
                // swap
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;

                current = next;
                cnt++;

            } while (i != current); // until it comes back to i.
        }
    }

};

int main()
{
    vector<int> nums{ 1,2,3,4,5,6,7 };

    

    Solution sol = Solution();

    sol.rotate2(nums, 3);

    cout << "Result: " << nums[0] << endl;
}

