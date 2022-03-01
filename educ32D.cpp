#include <bits/stdc++.h>
using namespace std;
#define INF 1011111111
using ll = long long;
const int N = 1001;
 
unsigned long long C[N][N];
int d[5] = {1,0,1,2,9};
int n,k;
int main() {
    cin >> n >> k;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    unsigned long long ans = 0;
    if (k == 1) {
        ans = 1;
    }
    if (k == 2) {
        ans = C[n][2] + 1;
    }
    if (k == 3) {
        ans = C[n][2] + C[n][3]*2 + 1;
    }
    if (k == 4) {
        ans = C[n][2] + C[n][3]*2 + C[n][4]*9 + 1;
    }
    cout << ans << '\n';
    return 0;
}