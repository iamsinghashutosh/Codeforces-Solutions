#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int m,t,r;
  cin >> m >> t >> r;
  int a[m];
  map<int,int> mp;
  f(i,m)
    cin >> a[i];
  int val=a[0]-r+t;
  if(val<a[0])
  {
      cout << -1 << '\n';
  }
  else
  {
      int ans=r;
      fp(j,0,r-1)
      {
        val=a[0]-r+t+j;
      fp(i,1,m-1)
      {
          if(val<a[i])
            {
             fr(k,max(a[i]-r+t+j,val+t),1)
             {
                 if(mp[k]==0)
                 {
                     val=k;
                     mp[val]=1;break;
                 }
             }
            if(val<a[i])
                {cout << -1 << '\n';return;}
            ans++;}
      }
      }
      cout << ans << '\n';
  }
  return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
