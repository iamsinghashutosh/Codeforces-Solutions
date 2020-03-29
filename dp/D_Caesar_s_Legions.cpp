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
#define mod 100000000
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
int n1,n2,k1,k2;
int memo[101][101][11][11];
int func(int n1,int n2,int f,int h)
{
    if(n1+n2==0)
        return 1;
    int ans=0;
    if(memo[n1][n2][f][h]==-1)
    {
        if(n1>0 && f>0) ans = (ans + func(n1-1,n2,f-1,k2))%mod;
        if(n2>0 && h>0) ans =(ans + func(n1,n2-1,k1,h-1))%mod;
        memo[n1][n2][f][h]=ans;
    }
    return memo[n1][n2][f][h];
} 
 
void solve()
{
  memset(memo, -1, sizeof memo);
  cin >> n1 >> n2 >> k1 >> k2;
  cout << func(n1,n2,k1,k2) << '\n';
  return ;
}

signed main()
{
   FAST;
	int T=1;
	// cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
