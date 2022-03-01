#include <bits/stdc++.h>
#define int int64_t
using namespace std;
 
int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
 
int n,k;
int32_t main(){
    cin >> n >> k;
    vector<int>divisors;
    for(long long i = 1; i * i <= n; ++i){
        if(n % i == 0){
            divisors.push_back(i);
        }
    }
    for(int i = (int)divisors.size() - 1; i >= 0; --i){
        if(divisors[i] * divisors[i] != n){
            divisors.push_back(n / divisors[i]);
        }
    }
    divisors.resize(divisors.size());
    int nD = divisors.size();
    std::vector<std::vector<bool>>coPrime(nD, vector<bool>(nD,true));
    std::vector<std::vector<int>>next(nD);
    for(int i = 0; i < nD; ++i){
        for(int j = i; j < nD; ++j){
            bool ok = gcd(divisors[i],divisors[j]) == 1;
            coPrime[i][j] = coPrime[j][i] = ok;
            if(ok && i != j){
                next[i].push_back(j);
            }
        }
    }
    int total = 0;
    std::function<void(int,int,int)> count = [&](int lastDivIndex, int currMult, int remind){
        if (remind == 0){
            ++total;
            return;
        }
        for (auto NextIndex : next[lastDivIndex]){
            int j = NextIndex;
            if (currMult * divisors[j] <= n){
                count(NextIndex, currMult * divisors[j], remind - 1);
            } else
                break;
        }
    };
    for(int i = 0; i < nD; ++i){
        count(i, divisors[i], k - 1);
    }
    cout << total << "\n";
    return 0;
}