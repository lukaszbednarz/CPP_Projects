#include <vector>
#include <iostream>
#include <ostream>
#include <map>
#include <set>
#include <algorithm>
#include <array>

using std::cout;
using std::vector;
using std::endl;
using std::map;
using std::set;
using std::begin;
using std::end;
using std::sort;
using std::array;

class Solution {

   

public:
    void rotate(vector<vector<int>>& matrix) {

        int size = matrix.size();


        for (size_t x = 0; x < size / 2; x = x++)
        {

            for (size_t y = x; y < size - x - 1; y++)
            {

                int temp = matrix[x][y];
                int next = 0;

                matrix[x][y]                       = matrix[size - y -1][x];
                matrix[size - y - 1][x]            = matrix[size - y - 1][size - x - 1];
                matrix[size - y - 1][size - x - 1] = matrix[y][size - x - 1];
                matrix[y][size - x -1]             = temp;

            }

            
            

        }

    }
};

int main()
{
    // test vector 
    //vector<vector<int>> matrix {{5, 1, 9, 11},
    //                            { 2, 4, 8, 10 },
    //                            { 13, 3, 6, 7 },
    //                            { 15, 14, 12, 16 }};

        vector<vector<int>> matrix { {1,2,3} ,{4,5,6},{7,8,9} };
    int target = 9;

    Solution sol = Solution();

    sol.rotate(matrix);

    cout << "Result: " << matrix[0][0] << endl;
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
