/*
  GOOD is not Enough
  You've got to be GREAT.
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


void solve()
{ 
  int l,r;
  cin >> l >> r;
  int ans=0;
  fr(i,63,0)
  {
	  if((r&(1LL<<i)) && (l&(1LL<<i))==0)
	  {
		  if((r%(1LL<<i))==((1LL<<i)-1))
			{
				ans=ans+(int)(1LL<<(i+1))-1;
				cout << ans << '\n';
			}
		  else
		  {
			  ans=ans+(int)(1LL<<i)-1;
			  cout << ans << '\n';
		  }
		  return;
	  }
	  if((r&(1LL<<i)) && (l&(1LL<<i)))
	  {
		  ans+=(int)(1LL<<i);
	  }
		
  }
  cout << ans << '\n';
 return;
}

signed main()
{
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
