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
  int n;
  cin >> n;
  int a[n],cnt=0,g;
  f(i,n)
    {
        cin >> a[i];
        if(i==0)
            g=a[0];
        else
        g=__gcd(g,a[i]);
        if(a[i]==1)
            cnt++;
    }
    if(g!=1)
        {
            cout << -1 << '\n';return;
        }
  int ans;
  if(cnt)
    ans=n-cnt;
  else
    ans=mod;
  f(i,n)
  {   
      int x=a[i];
      fp(j,i+1,n-1)
      {
          x=__gcd(x,a[j]);
          if(x==1)
          {
              int len=j-i+(n-1);
              ans=min(len,ans);
          }
      }
  }      
  cout << ans << '\n';
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
