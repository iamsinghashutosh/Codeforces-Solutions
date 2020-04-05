/*
 Ashutosh Singh
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

bool comp(const pair<int,int> l1,const pair<int,int> l2)
{
    if(l1.F==l2.F)
        return l1.S<l2.S;
    return l1.F>l2.F;

}

void solve()
{
  int n,m;
	cin>>n>>m;
	int ans[m],sum[m];
	vector<pair<int,int>> v(m);
	f(i,m)
	{
		cin>>v[i].first;
		v[i].second=i;
	}
	sum[0]=v[0].first;
	fp(i,1,m-1)
	{
		sum[i]=v[i].first+sum[i-1];
	}
	if (sum[m-1]<n)
	{
		cout<<-1;
		return;
	}
	ans[v[0].second]=0;
	int prev=0;
	fp(i,1,m-1)
	{
		prev=max(prev+1,n-sum[m-1]+sum[i-1]);
		if (prev+v[i].first>n)
		{
			cout<<-1;
			return ;
		}
		ans[v[i].second]=prev;
	}
f(i,m)
		cout<<ans[i]+1<<" ";
  return;
}

signed main()
{
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
