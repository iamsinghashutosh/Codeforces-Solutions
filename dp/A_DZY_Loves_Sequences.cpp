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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
 
void solve()
{
  int n;
  cin >> n;
  int a[n+1]={0};
  fp(i,1,n)
  {
      cin >> a[i];
  }
  int l[n+2]={0};
  int r[n+2]={0};
  fp(i,1,n)
  {
      if(a[i]>a[i-1])
        l[i]=l[i-1]+1;
      else
        l[i]=1;
  }
  fr(i,n,1)
  {
      if(a[i]<a[i+1])
        r[i]=r[i+1]+1;
      else
        r[i]=1;
  }
  int ans=0;
  fp(i,1,n)
  {
    if(a[i-1]+1<a[i+1])
      ans=max(ans,l[i-1]+r[i+1]+1);
      else
      ans=max(ans,max(l[i-1]+1,r[i+1]+1));
  }
  cout << ans << '\n';
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
