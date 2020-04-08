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
 int n;
 cin >> n;
 int a[n];
 f(i,n)
    cin >> a[i];
 int res=0;
 f(k,27)
    {
      int b[n];
      f(i,n)
        b[i]=a[i]%(1<<(k+1));
      sort(b,b+n);
      int ans=0;
      f(i,n)
      {
          int l=lower_bound(b+i+1,b+n,(1<<k)-b[i])-b;
          int r=lower_bound(b+i+1,b+n,(1<<(k+1))-b[i])-b;
          ans+=(r-l);
          l=lower_bound(b+i+1,b+n,(1<<k)+(1<<(k+1))-b[i])-b;
          ans+=(n-l);
      }
      res+=(int)(ans%2)*(int)(1<<k);
    }
    cout << res << '\n';
 return;
}

signed main()
{
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
