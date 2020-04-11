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
  int a[n],b[n];
  f(i,n)
  {
    cin >> a[i] >> b[i];
  }
  int ans[n],sum=0;
  memset(ans,0,sizeof(ans));
  f(i,n)
  {
      if(i==0)
        ans[i]=max((int)0,a[i]-b[n-1]);
      else
      ans[i]=max((int)0,a[i]-b[i-1]);
  }
  f(i,n)
  {
      if(i==0)
        sum=a[i];
      else
        sum+=ans[i];
  }
  int res=sum;
  fp(i,1,n-1)
  {
      sum-=ans[i];
      sum+=a[i];
      sum-=a[i-1];
      sum+=ans[i-1];
      res=min(sum,res);
  }
  cout << res << '\n';
 return;
}

signed main()
{
    FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
