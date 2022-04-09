//
//  main.cpp
//  ArrayAdjacentValues
//
//  Created by Lukasz Bednarz on 21/09/2017.
//  Copyright © 2017 Lukasz Bednarz. All rights reserved.
//

#include <iostream>
#include <algorithm>

bool is_adjacent(int A[], int i, int j){
    bool ret;
    
    
    
    
    return ret;
}

int solution(int A[], int N){
    int max_d = -1;
    
    // sort indices
    int y[N];

    std::size_t n(0);
    
    // create array of indices
    std::generate(y, y + N, [&]{ return n++; });
   
    // sort indices
    std::sort( y,
               y + N,
               [&](int i1, int i2) {
//                   if (abs(i1  -i2) > max_d){
//                       max_d = abs(i1 - i2);
//                   }
                   return A[i1] < A[i2];
               } );
    
    for (int i = 0; i < N - 1; ++i){
//        for (int j = i +1 ; j < N; ++j){
//            if (is_adjacent(A, i, j) && j - i > max_d){
        
        int diff = abs(y[i+1] - y[i]);
        if ( A[y[i]]< A[y[i+1]] &&  diff > max_d && diff > 0a){
                max_d = abs(diff);
            }
//        }
    }
    
    return max_d;
}

int main(int argc, const char * argv[]) {
    // test 1
    int T1[] = {0,3,3,7,5,3,11,1};
    int N = sizeof(T1)/sizeof(int);
    std::cout << "Test 1 result : " << solution(T1, N) << std::endl;
    
    int T2[] = {0,3,3,7,5,3,11,3};
    std::cout << "Test 1 result : " << solution(T2, N) << std::endl;
    
    
    return 0;
}
