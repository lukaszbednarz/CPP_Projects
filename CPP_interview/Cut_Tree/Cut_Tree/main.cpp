#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

class Node{
    public :
    int id = 0;
    set<int> adj;
};


vector<vector<int>> chld;

int count_st(int node){
    int ret = 1;
    int len = chld[node].size();
    
    if ( len > 0){
        ret += 2 * count_st(chld[node][1]);
        for(int i = 1; i < len; i++ ){
            ret *= (2 * count_st(chld[node][i]));
        }
    }
    cout << "ret for node : " << node << " = " << ret << endl;
    
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, K;
    
    cin >> n >> K;
    
    chld.resize(n);
    
    int a, b;
    //cin >> a >> b;
    //int top = a;
    
    //cout << "top : " << top << endl;
    
    //chld[a].push_back(b);
    
    for (int i = 0; i < n-1; i ++){
        cin >> a >> b;
        cout << "a = " << a << ", b = " << b << endl;
        chld[a-1].push_back(b-1);
    }
    
    int count = 0;
    for (int i = 0; i <= K; i ++){
        
        count += 2*pow(n-1,i);
    }
    // cout << count_st(top);
    cout << count << endl;
    
    return 0;
}

