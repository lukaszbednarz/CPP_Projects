// Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using std::string;



class Solution {

public:
    bool isAlphaNum(char& c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') {
            c += 32;
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {

        int i = 0, j = s.length() - 1;
        while (j > i) {

            char a = s[i], b = s[j];

            if (!isAlphaNum(a)) {
                i++;
                continue;
            }
            if (!isAlphaNum(b)) {
                j--;
                continue;
            }

            if (a != b) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";

    Solution sol;

    bool res = sol.isPalindrome(s);

    std::cout << "Result: " << res << std::endl;

}

