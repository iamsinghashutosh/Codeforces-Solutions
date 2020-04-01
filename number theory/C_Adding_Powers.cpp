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

int vis[1000]; 
 
bool chk(int num,int stp,int k)
{
    if(num==0)return 0;
    if(num%k==0) return chk(num/k,stp+1,k);
    if(num%k==1)
    {
        if(vis[stp])return 1;
        vis[stp]=1;
        return chk((num-1)/k,stp+1,k);
    }
    return 1;
}

void solve()
{
  memset(vis,0,sizeof(vis));
  int n,k;
  cin >> n >> k;
  vector<int> v;
  f(i,n)
   {
       int x;
       cin >> x;
       v.pb(x);
   }
   int flg=1;
   f(i,n)
   {
       if(chk(v[i],0,k))
        flg=0;
   }
   if(flg)
    cout << "YES\n";
   else 
    cout << "NO\n";
  return ;
}

signed main()
{
   FAST;
	int T=1;
	cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
