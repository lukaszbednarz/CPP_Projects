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

private:
    vector<vector<int>> toInt(vector<vector<char>>& board) {
        
        vector<vector<int>> int_board;

        for (vector<char> row: board)
        {
            vector<int> int_row;

            
            for (char cell: row)
            {
                int tmp = cell - '0';
                
                if (tmp < 0) {
                    int_row.push_back(0);
                } 
                else
                {
                   int_row.push_back(tmp);
                }
                

            }
            int_board.push_back(int_row);

        }

        return int_board;
    }

    bool isRowValid(vector<vector<int>>& board, int row) {

        vector<bool> exist(10,false);
        for (int i = 0; i < board[row].size(); i++)
        {
            int val = board[row][i];
            if (exist[val] && val) return false;
            exist[val] = true;

        }

        return true;
    }

    bool isColumnValid(vector<vector<int>>& board, int col) {

        vector<bool> exist(10, false);
        for (int i = 0; i < board.size(); i++)
        {
            int val = board[i][col];
            if (exist[val] && val) return false;
            exist[val] = true;

        }

        return true;
    }

    bool isBoxValid(vector<vector<int>>& board, int n) {

        int col = n % 3;
        int row = n / 3;

        vector<bool> exist(10, false);
        for (int i = row * 3; i < (row + 1) * 3; i++)
        {
            for (int j = col * 3; j < (col + 1) * 3; j++)
            {
                int val = board[i][j];
                if (exist[val] && val) return false;
                exist[val] = true;
            }


        }

        return true;
    }


public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> int_board = toInt(board);

        for (int i = 0; i < board.size(); i++)
        {
            if (!isRowValid(int_board, i)) return false;
            if (!isColumnValid(int_board, i)) return false;
            if (!isBoxValid(int_board, i)) return false;
        }

        return true;

    }

    bool isValidSudoku2(vector<vector<char>>& board) {

        const array<int, 9> nine_primes{ 2, 3, 5, 7, 11, 13, 17, 19, 23 };

        const auto get_box = [](int r, int c) {
            return (r / 3) * 3 + (c / 3);
        };

        const auto get_val = [](char c) {
            return c - '1';
        };

        array<int, 9> rows{ 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        array<int, 9> cols{ 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        array<int, 9> boxes{ 1, 1, 1, 1, 1, 1, 1, 1, 1 };

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {

                auto e = board[r][c];
                if (e == '.') continue;

                auto n = nine_primes[get_val(e)];

                if ((rows[r] % n == 0)
                    || (cols[c] % n == 0)
                    || (boxes[get_box(r, c)] % n == 0)
                    ) {
                    return false;
                }

                rows[r] *= n;
                cols[c] *= n;
                boxes[get_box(r, c)] *= n;

            }
        }

        return true;
    }
};


int main()
{
    // test vector 
    vector<vector<char>> board { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
                                ,{'6', '.', '.', '1', '9', '5', '.', '.', '.'}
                                ,{'.', '9', '8', '.', '.', '.', '.', '6', '.'}
                                ,{'8', '.', '.', '.', '6', '.', '.', '.', '3'}
                                ,{'4', '.', '.', '8', '.', '3', '.', '.', '1'}
                                ,{'7', '.', '.', '.', '2', '.', '.', '.', '6'}
                                ,{'.', '6', '.', '.', '.', '.', '2', '8', '.'}
                                ,{'.', '.', '.', '4', '1', '9', '.', '.', '5'}
                                ,{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    int target = 9;

    Solution sol = Solution();

    bool result = sol.isValidSudoku2(board);

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
