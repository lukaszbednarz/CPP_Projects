#include <vector>
#include <map>
#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <thread>


typedef long long int T_LONG_LONG;

const static std::vector<int> COINS { 240, 24, 12, 6, 3, 1 };
const static int COINS_LEN = 6;

class Solution {


public :
    
    // memoisations store.
    std::vector<std::map<int, T_LONG_LONG>> dp;


public:

    Solution()
    {
        for (size_t i = 0; i < COINS_LEN; i++)
        {
            dp.push_back(std::map<int, T_LONG_LONG>());
        }
    }

    T_LONG_LONG getCombinations(int n, int subset) {

        if (n == 0) return 1;
        
        // check if already calclated
        if ( dp[subset].size() && dp[subset].find(n) != dp[subset].end()) {
            return dp[subset][n];
        }

        T_LONG_LONG ans = 0;
       /* for (int j = subset; j < COINS_LEN; j++)
        {*/
            /*int tmp = 1;int tmp = 1/*/
            for(int i = subset; i < COINS_LEN; i++)
            {
                if (n < COINS[i]) continue;

                ans += getCombinations(n - COINS[i], i);

            }

           /* ans += tmp;*/

        //}
        
        dp[subset][n] = ans;

        return ans;
    }

    T_LONG_LONG getCombinations(int n) {

        
        return getCombinations(n, 0);
    }


};

class Test {
private:
    int n_;

    int set_;

    T_LONG_LONG  exp_;
    
public:

    void setSet(int n) {

        if (n < 0) n = 0;

        if (n >= 6) n = COINS_LEN - 1;

        set_ = n;
    };

    int getSet() {
        return set_;
    }

    void setN(int n) {
        n_ = n;
    };

    void setExpectation(T_LONG_LONG exp) {
        exp_ = exp;
    };

    int getN() {
        return n_;
    }

    T_LONG_LONG getExpectation() {
        return exp_;
    };

    Test(int n, int exp)
    {
        setN(n);
        setExpectation(exp);
        setSet(0);
    }

    Test(int n, int exp, int set)
    {
        setN(n);
        setExpectation(exp);
        setSet(set);
    }


    bool runTest() {
        
        Solution sol = Solution();

        bool result = false;
        time_t start, end;
        
        try {
            time(&start);

            T_LONG_LONG resp = sol.getCombinations(getN(), getSet());

            time(&end);
            double time_taken = double(end - start);
            
            result = resp == getExpectation();
            
            std::string status = "failed";
            if(result ) status = "passed";
         

            std::cout << "###################" << std::endl;
            std::cout << "Test : " << typeid(this).name() << " " << status << std::endl;
            std::cout << "Input: " << getN() << std::endl;
            std::cout << "Expected: " << getExpectation() << std::endl;
            std::cout << "Result: " << resp << std::endl;
            std::cout << "Time Taken: " << std::fixed << time_taken <<  "sec" << std::endl << std::endl;

        }
        catch (std::exception& e) {
            std::cout << "Exception occured for test: " << typeid(this).name() << std::endl;
            std::cout << "Message: " << e.what() << std::endl;
            return false;
        }

        return result;
    };

};



int main()
{
    
    ////// TASK 1 ///////////////

    //// test vector example
    //Test test1(7, 1, 6);
    //auto result1 = test1.runTest();
    //
    //// test vector example
    //Test test2(7, 4);
    //auto result2 = test2.runTest();

    //// test vector
    //Test test3(240 + 12, 46430);
    //auto result3 = test3.runTest();

    //Test test4(3 * 240 + 5 * 12 + 5, 4328404);
    //auto result4 = test4.runTest();

    Test test5(10 * 240, 708369211);
    auto result5 = test5.runTest();
}

