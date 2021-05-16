#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000000 + 7;

ll modexp(ll x, ll y)
{
    ll res = 1;
    y = y % (MOD - 1);
    x %= MOD;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % MOD;
        }
        y /= 2;
        x = (x * x) % MOD;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}