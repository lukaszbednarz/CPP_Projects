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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        if (nums2.size() > nums1.size()) {
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }

        vector<int> out;

        for (size_t i = 0; i < nums1.size(); i++)
        {
            int pos = 0;

            while (pos < nums2.size())
            {
                if (nums1[i] == nums2[pos]) {
                    out.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + pos);
                    break;
                }
                pos++;
            }
        }

        return out;
    }

    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> ans;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ++i; ++j;
            }
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        return ans;
    }


};


int main()
{
    // test vector 
    vector<int> nums{ 4,9,5 };
    vector<int> nums2{ 9,4,9,8,4 };


    Solution sol = Solution();

    vector<int> result = sol.intersect(nums, nums2);

    cout << "Result: " << result.size() << endl;
}

