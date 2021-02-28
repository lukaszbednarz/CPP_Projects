#include <vector>
#include <iostream>
#include <ostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

using std::cout;
using std::vector;
using std::endl;
using std::map;
using std::set;
using std::begin;
using std::end;
using std::sort;
using std::stack;
using std::queue;

class Solution {

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = 0, j = 0, next = 0, tmp = 0;
        
        queue<int> queue;

        next = nums1[i];

        while (i < m + n && j < n) {

            tmp = nums2[j];

            if (queue.front() > tmp){
 
                nums1[i] = tmp;
                j++;
            }
            else {
            }

            i++;

        }


    }

};


int main()
{
    // test vector 
    vector<int> nums1{ 4,5,6,0,0,0};
    vector<int> nums2{ 1,2,3 };
    int m = 3;
    int n = 3;


    Solution sol = Solution();

    sol.merge(nums1, m, nums2, n);

    cout << "Result: " << nums1.size() << endl;
}

