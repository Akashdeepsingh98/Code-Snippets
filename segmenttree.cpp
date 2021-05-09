#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull p2(ull n)
{
	ull result = 1;
	ull i = 0;
	while(n>result)
	{
		result = (1<<i);
		i++;
	}
	return result;
}

void prepsegtree(vector<ull>& segtree)
{
	ull i=segtree.size()-1;
	while(i>=2)
	{
		segtree[i/2] = segtree[i]+segtree[i-1];
		i-=2;
	}
}

void solve(vector<ull>& segtree, ull N2)
{
	ull a,b;
	cin>>a>>b;
	a+=N2-1;b+=N2-1;
	ull s=0;
	while(a<=b)
	{
		if(a%2==1)
		{
			s+=segtree[a];
			a++;
		}
		if(b%2==0)
		{
			s+=segtree[b];
			b--;
		}
		a/=2;b/=2;
	}
	cout<<s<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ull N,Q;
	cin>>N>>Q;
	vector<ull> v(N);
	for(ull i=0;i<N;i++)
	{
		cin>>v[i];
	}
	ull N2 = p2(N);
	vector<ull> segtree(2*N2, 0);
	for(ull i=0;i<N;i++)
	{
		segtree[N2+i] = v[i];
	}
	prepsegtree(segtree);

	for(ull i=0;i<Q;i++)
	{
		solve(segtree, N2);
	}
}