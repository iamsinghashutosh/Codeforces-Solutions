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
int n,m;
int a[2005];

bool chk(int p)
{
    int ans=0;
    f(i,n)
    {
        int val=(a[i]+p-1)/p;
        ans+=val;
    }
    return ans<=m;
}

void solve()
{
    int q;
  cin >> n >> q;
  f(i,n)
    cin >> a[i];
  while(q--)
  {
      cin >> m;
      int l=0,h=(int)1e9+1;
      while(h-l>1)
      {
          int mid=(l+h)/2;
          if(chk(mid))
              h=mid;
          else
            l=mid;
      }
      if(h==(int)(1e9+1))
        cout << "-1\n";
      else
        cout << h << '\n';
  }
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
