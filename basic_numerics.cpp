#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    return 0;
}