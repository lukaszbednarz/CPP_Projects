// Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;


class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> arr(26, 0);

        auto len_s = s.length(), len_t = t.length();
        if (len_s != len_t) return false;

        int sum = 0;

        for (int i = 0, j = 0; i < len_s && j < len_t; i++, j++)
        {
            arr [s[i] - 'a']++;
            arr[t[j] - 'a']--;
        }

        for (int el: arr)
        {
            if (el != 0) return false;
        }
        return true;
    }
};

int main()
{
    string s = "", t = "";

    Solution sol;

    bool res = sol.isAnagram(s, t);

    cout << "Result: " << res << endl;

}

