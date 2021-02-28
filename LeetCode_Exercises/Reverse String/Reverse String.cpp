// Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;


class Solution {
public:
    int reverse_old(int x) {
        int exp = 1;
        int out = 0;
        int tmp;
        while (x) {

            tmp = x % 10;
            x /= 10;
            out += (10 - tmp) * exp;
            exp *= 10;
        }

        return out;
    }
    int reverse(int x) {
        int exp = 1;
        int out = 0;
        int digit;
        int ceil = ~(1 << 31) - 1;
        int floor = (1 << 31);
        int ceil_tens = ~(1 << 31) / 10;
        int floor_tens = (1 << 31) / 10;

        //if (sign) {
        //    tmp = ~ x + 1;
        //}
        while (x) {

            // check for overflow
            if (out > ceil_tens || out < floor_tens) {
                return 0;
            }


            digit = (x % 10);
            x /= 10;

            out *= 10;

            // check for overflow
            if (out > ceil - abs(digit) || out < floor + abs(digit)) {
                return 0;
            }

            out += digit;

        }
   /*     
        if (sign) {
            out = ~(out - 1);
        }*/

        return out;
    }


};

int main()
{
    int x = -2147483412;

    Solution sol;

    int res  = sol.reverse(x);

    cout << "Result: " << res << endl;

}

