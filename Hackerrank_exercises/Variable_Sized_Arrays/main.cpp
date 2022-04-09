#include <cmath>
#include <filesystem>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ifstream test;

    test.open("test_1.txt", ios::out | ios::in);

    //cout << std::filesystem::current_path() << endl;
    // 
    //string line;
    //while (getline(test, line)) {
    //    cout << line << endl;
    //}

    int n, q;

    test >> n >> q;

    int** a = new int*[n];

    for (int i = 0; i < n; i++) {
        int k;
        test >> k;

        int* arr = new int[k];

        for (int j = 0; j < k; j++) {
            test >> *(arr + j);
        }

        a[i] = arr;
    }

    for (int k = 0; k < q; k++) {
        int i, j;
        test >> i >> j;

        cout << *(a[i] + j) << endl;
    }

    test.close();

    for (int i = 0; i < n; i++) {
        int k;
        test >> k;

        int* arr = new int(k);

        for (int j = 0; j < k; j++) {
            test >> *(arr + j);
        }

        a[i] = arr;
    }



    return 0;
}
