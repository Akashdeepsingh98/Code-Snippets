
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll factorial(int n)
{
    ll res = 1;
    for (ll i = 1; i <= n; i++)
    {
        res = (res * (i % MOD)) % MOD;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}