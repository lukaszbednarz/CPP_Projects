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

using namespace std;

vector<vector<long long>>mem_change;

long long make_change(vector<int> coins, int money) {
    
    int coins_i = coins.size() -1;
    long long r = mem_change[coins_i][money];
    
    
    if (money == 0){
        mem_change[coins_i][money] = 0;
    }
    
    if (r != -1){
        return r;
    } else{
        r = 0;
        for(int i = coins.size() -1; i >= 0 ; --i){
            vector<int> new_coins(coins.begin(), coins.begin() + i +1);
            int coin = coins[i];
            if (coin > money){
                continue;
            } else if ( money == coin || (i == 0 && money % coin == 0) ) {
                r ++;
            }
            else {
                
                r += make_change(new_coins, money - coin);
                
            }
            
        }
        mem_change[coins_i][money] = r;
    }
    return  r;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    mem_change.resize(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
        mem_change[coins_i].resize(n +1,-1);
        cin >> coins[coins_i];
    }
    sort(coins.begin(), coins.end());
    cout << make_change(coins, n) << endl;
    return 0;
}

