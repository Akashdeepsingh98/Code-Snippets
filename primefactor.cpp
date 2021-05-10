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

vector<int> SieveOfEras(int n)
{
    vector<int> sieve(n+1, 0);
    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= n; u += x) {
            sieve[u] = x;
        }
    }
    return sieve;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    return 0;
}