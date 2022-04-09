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

bool is_prime(int n){
//    bool ret;
    
    if (n <= 1){
        return false;
    } else if (n <= 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0){
        return false;
    } else {
        int i = 5;
        while (i*i <= n){
            if (n % i == 0 || n % ( i +2) == 0){
                return false;
            }
            i += 6;
        }
        
        return true;
    }
//    function is_prime(n)
//    if n ≤ 1
//        return false
//        else if n ≤ 3
//            return true
//            else if n mod 2 = 0 or n mod 3 = 0
//                return false
//                let i ← 5
//                while i * i ≤ n
//                    if n mod i = 0 or n mod (i + 2) = 0
//                        return false
//                        i ← i + 6
//                        return true
//    
//    return ret;
    
}

int main(){
    int p;
    cin >> p;
    for(int a = 0; a < p; ++a){
        int n;
        cin >> n;
        
        if (is_prime(n)){
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }
        return 0;
}

