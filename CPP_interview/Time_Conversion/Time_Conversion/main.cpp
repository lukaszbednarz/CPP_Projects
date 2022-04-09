#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <locale>


using namespace std;

int main(){
    string time;
    cin >> time;
    
    
    std::tm t = {};
//    std::istringstream ss("2011-Februar-18 23:12:34");
    std::istringstream ss(time);
    //ss.imbue(std::locale("de_DE.utf-8"));
    //std::locale x = std::locale("");
    //cout << x.name()  << endl;
//    ss >> std::get_time(&t, "%I:%M:%S%p");
    
    bool is_pm;
    
    is_pm = time.compare(time.length() - 2, 2, "PM") == 0;
    
    ss >> std::get_time(&t, "%I:%M:%S");

    if (ss.fail()) {
        std::cout << "Parse failed\n";
    } else {
        if (is_pm)
        {
            t.tm_hour = t.tm_hour + 12;
        }
        
        std::cout << std::put_time(&t, "%H:%M:%S") << '\n';
        
    }
    
    return 0;
}

