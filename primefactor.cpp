#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x*x <= n; x++) {
        if (n%x == 0) return false;
    }
    return true;
}

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    return 0;
}