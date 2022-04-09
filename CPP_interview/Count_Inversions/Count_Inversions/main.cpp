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

void merge_halves(vector<int>& a, vector<int>& temp, int leftStart, int rightEnd, long long *count){
    
    int middle = (leftStart + rightEnd)/2;
    
    //cout << "In merge_halves(), leftStart = " << leftStart << ", rightEnd = " << rightEnd << ", middle = " << middle << ", a.size() = " << a.size() << ", temp.size() = " << temp.size() << endl;
    
    int left = leftStart;
    int right = middle + 1;
    int size = rightEnd - leftStart +1;
    int idx = leftStart;
    
    while (left <= middle && right <= rightEnd ){
        //cout << "at entry : left = " << left << ", right = " << right << ", idx = " << idx << ", (*count) = " << (*count) << endl;
        if(a[left] > a[right]){
            //cout << "swapping : temp[idx] = " << temp[idx] << " to a[right] = " << a[right] << endl;
            temp[idx] = a[right];
            //if(idx < right){
                (*count) += abs(right - idx);
                //cout << "count is " << (*count) << endl;
            //}
            ++ right;
            ++ idx;
        } else if (a[left] <= a[right]) {
            //cout << "swapping : temp[idx] = " << temp[idx] << " to a[left] = " << a[left] << endl;
            temp[idx] = a[left];
            if(idx < left){
                //(*count) += abs(left - idx);
                //cout << "count is " << (*count) << endl;
            }
            ++ left;
            ++ idx;
        }
        //cout << "at exit : left = " << left << ", right = " << right << ", idx = " << idx << ", (*count) = " << (*count) << endl;
    }
    
    copy(a.begin() + left, a.begin() + middle+1, temp.begin() + idx);
    //if(a.begin() + left < a.begin() + middle+1 && left < idx){
        //++ (*count);
        //cout << "count is " << (*count) << endl;
    //}
    
    copy(a.begin() + right, a.begin() + rightEnd+1, temp.begin() + idx);
    //if(a.begin() + right < a.begin() + rightEnd+1 && right > idx){
        //++ (*count);
        //cout << "count is " << (*count) << endl;
    //}
    
    copy(temp.begin() + leftStart, temp.begin() + leftStart + size, a.begin() + leftStart);
    
}

void merge_sort(vector<int>& a, vector<int>& temp, int leftStart,  int rightEnd, long long*
                count){
    
    if (leftStart >= rightEnd){
        return;
    }
    
    int middle = (leftStart + rightEnd)/2;
    
    //cout << "In merge_sort(), leftStart = " << leftStart << ", rightEnd = " << rightEnd << ", middle = " << middle << ", a.size() = " << a.size() << ", temp.size() = " << temp.size() << endl;
    
    merge_sort(a, temp, leftStart, middle, count);
    merge_sort(a, temp, middle + 1, rightEnd, count);
    merge_halves(a, temp, leftStart, rightEnd, count);
    
}

long long count_inversions(vector<int>& a) {
    long long count = 0;
    vector<int> temp(a.size());
    
    merge_sort(a, temp, 0, a.size() - 1, &count);
    
    /*for(int i = 0; i < a.size(); i++ ){
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    
    for(int i = 0; i < a.size(); i++ ){
        cout << "temp[" << i << "] = " << temp[i] << endl;
    }*/
    
    return (count);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
            cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}


