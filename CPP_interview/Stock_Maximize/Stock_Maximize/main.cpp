#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
//#include <priority_queue>

using namespace std;


int main(){
    unsigned int t;
    cin >> t;
    for(unsigned int a0 = 0; a0 < t; a0++){
        unsigned int N;
        unsigned int n = 0;
        unsigned int pl = 0;
        unsigned int pd = 0;
        cin >> N;
        vector<unsigned int> prices(N,0);
        vector<unsigned int> max_pd(N,0);
        //memset(max_pd, 0, N*sizeof(int));
        
        //vector<priority_queue<int>> max_pd(N);
        for(unsigned int prices_i = 0; prices_i < N; prices_i++){
            unsigned int price;
            cin >>  price;
            prices[prices_i] = price;
            //max_pd[prices_i].push(0);
            /*for (unsigned int days_i = 0; days_i <= prices_i; days_i ++){
             //max_pd[days_i].push(price);
             if (price > max_pd[days_i]){
             max_pd[days_i] = price;
             
             }
             }*/
        }
        
        unsigned int max_price = 0;
        for ( int days_i = (N-1); days_i >= 0; days_i --){
            if (prices[days_i] > max_price){
                max_price = prices[days_i];
            }
            max_pd[days_i] = max_price;
        }
        // treat each day as separate opportunity to buy
        // and where we can only buy once and sell somewhere in the future
        
        for(unsigned int prices_i = 0; prices_i < N -1; prices_i++){
            pd = max_pd[prices_i] - prices[prices_i];
            
            //if (pd > 0){
            pl += pd;
            //}
            
        }
        
        cout <<  pl << endl;
    }
    return 0;
}

