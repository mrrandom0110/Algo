#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1000;
 
int32_t main(){
    int n;
    cin >> n;
    if(n == 2){
        cout << 2 << " " << 1 << "\n";
        return 0;
    }
    int m = n % 3;
    if(m == 0){
        cout << 3 << " " << n/3 << "\n";
    } else if(m == 1){
        int c_3 = n/3 - 1;
        int c_2 = (n - c_3*3)/2;
        if(!c_3){
            cout << 2 << " " << c_2 << "\n";
        } else if(!c_2){
            cout << 3 << " " << c_3 << "\n";
        } else {
            cout << 2 << " " << c_2 << " " << 3 << " " << c_3 << "\n";
        }
    } else {
        cout << 2 << " " << 1 << " " << 3 << " " << n/3 << "\n";
    }
    return 0;
}