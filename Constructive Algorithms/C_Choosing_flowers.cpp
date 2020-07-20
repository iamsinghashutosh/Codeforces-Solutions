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
#define all(a)      (a).begin(),(a).end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n,m;
  cin >> n >> m;
  vii v;
  f(i,m)
  {
      int x,y;
      cin >> x >> y;
      v.pb({x,y});
  }
  sort(all(v));
  int suff[m+1]={0};
  fr(i,m-1,0)
    suff[i]=suff[i+1]+v[i].F;
  int ans=suff[max(0LL,m-n)];
  f(i,m)
  {
    int dis=distance(v.begin(),ub(all(v),make_pair(v[i].S,(int)mod)));
    if(m<=dis+n)
    {
       if(dis>i)
       {
         if((n-1-(m-dis))<0)
          continue;
         int len=v[i].F+suff[dis]+(n-1-(m-dis))*v[i].S;
         ans=max(len,ans);
       }
       else
        {
          int len=suff[dis]+(n-(m-dis))*v[i].S;
          ans=max(len,ans);
        }
    }
  }
  cout << ans << '\n';
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
