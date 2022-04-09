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

bool visited_node(set<pair<int,int>>& visited, int i, int j){
    bool res = visited.find(make_pair(i,j)) != visited.end();
    return(res);
}

int get_region_size(vector< vector<int>> grid, set<pair<int, int>>& visited, int i, int j){
    
    int size = 0;
    
    if(! visited_node(visited, i,j)){
        
        //cout << "visiting i = " << i << " and  j = " << j << endl;
        visited.insert(make_pair(i, j));
        size ++;
    }
    for (int di = -1; di < 2; ++di){
        if (i + di >=0 && i +di < grid.size()){
            for (int dj = -1; dj < 2; ++dj){
                if ((j + dj >=0 && j +dj < grid[i].size()) && !(di == 0 && dj == 0) ){
                    if (!visited_node(visited,i + di, j + dj)){
                        //cout << "getting reg size for  i = " << i << " and  j = " << j << endl;
                        
                        if (grid[i + di][j + dj] == 1){
                            size += get_region_size(grid, visited, i + di, j + dj);
                        } else {
                            visited.insert(make_pair(i + di,j + dj));
                            
                        }
                    }
                }
            }
        }
    }
    
    return(size);
    
}

int get_biggest_region(vector< vector<int> > grid) {
    set<pair<int, int>> visited;
    priority_queue<int, vector<int>, less<int>> rg_sizes;
    int size = 0;
    
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); j++){
            if(! visited_node(visited, i,j)){
                
                if (grid[i][j] == 1){
                    size = get_region_size(grid,visited, i, j);
                    rg_sizes.push(size);
                } else {
                    visited.insert(make_pair(i,j));
                    
                }
            }
        }
    }
    
    return(rg_sizes.top());
    
}

int main(){
    int n;
    cin >> n;
    int m;
    int val;
    cin >> m;
    set<pair<int,int>> to_visit;
    
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
        for(int grid_j = 0;grid_j < m;grid_j++){
            cin >> val;
            if (val == 1){
                to_visit.insert({grid_i,grid_j});
                grid[grid_i][grid_j] = val;
            }
        }
    }
    
    int size = get_biggest_region(grid) ;
    cout << size << endl;
    return 0;
}

