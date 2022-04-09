#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// rework oo way
class Solver {
    public:
    int _n;
    int _m;
    vector<vector<int>> _memo;
    vector<vector<int>> _queries;
    
    Solver(int m, int n, vector<vector<int>> queries)
    {
        _m = m;
        _n = n;
        _queries = queries;
    }

    int SolveCase()
    {
        _memo.resize(_n + 1);
        for (int i = 0; i < _n + 1; i++){
            _memo[i].resize(_n + 1, -1);
        }
        
        return DP(-1, -1);
    }


    int DP(int r1, int r2){
        if (r1 + 1 == _n || r2 + 1== _n){
            return 0;
        }
        
        if (_memo[r1 + 1][r2 + 1] != -1){
            return(_memo[r1 + 1][r2 + 1]);
        }
        
        int i = max(r1, r2) + 1;
        //r1 stays in place
        int r2Cover = 0;
        if (r2 != -1){
            r2Cover = abs(_queries[r2][1] - _queries[i][0]);
        }
        int d1 = DP(r1, i);
        //r2 stays in place
        int r1Cover = 0;
        if (r1 != -1){
            r1Cover = abs(_queries[r1][1] - _queries[i][0]);
        }
        int d2 = DP(i, r2);
        
        int queryCover = abs(_queries[i][0] - _queries[i][1]);
        int ret = min(r2Cover + d1 + queryCover, r1Cover + d2 + queryCover);
        _memo[r1 + 1][r2 + 1] = ret;
        return ret;
    }
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned int T;
    cin >> T;
    vector<int> dist(T);
    for(int a0 = 0; a0 < T; a0++){
        int M;
        int N = 0;
        int a,b;
        cin >> M;
        cin >> N;
        vector<vector<int>> queries(N);
        for (int query_i = 0; query_i < N; query_i++){
            cin >> a >> b;
            queries[query_i].push_back(a);
            queries[query_i].push_back(b);
        }
        
        Solver solver(M, N, queries);
        dist[a0] = solver.SolveCase();
        
        cout << "End" << endl;
        
    }
    
    for(int a0 = 0; a0 < T; a0++){
        
        cout << dist[a0] << endl;
    }
    return 0;
}

