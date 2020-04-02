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
 
void solve()
{
  int n,k,x;
  cin >> n >> k >> x;
  int a[n];
  f(i,n)
  {
      cin >> a[i];
  }
  sort(a,a+n);
  int pre[n],suf[n];
  pre[0]=a[0];
  suf[n-1]=a[n-1];

  fp(i,1,n-1)
    pre[i]=a[i]|pre[i-1];

   fr(i,n-2,0)
    suf[i]=a[i]|suf[i+1];
  
  int ans=pre[n-1];
  if(n==1)
  {
      cout << ans*(int)pow(x,k) << '\n';return;
  }
  f(i,n)
  {
      int val=a[i];
      fp(j,1,k)
        val*=x;
      if(i==0)
        ans=max(ans,suf[i+1] | val);
      else if(i==n-1)
        ans=max(ans,pre[i-1] | val);
      else
      ans=max(ans,(suf[i+1] | pre[i-1])| val );
  }
  cout << ans << '\n';
  return ;
} 
 
signed main()
{
    FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
