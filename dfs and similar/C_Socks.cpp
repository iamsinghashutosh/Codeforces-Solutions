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
#define pii pair<int,int>
#define dbg(x) cout << (#x) << " is " << (x) << '\n' 
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int pa[200005],sz[200005];

void begin_dsu(int n)
{
    fp(i,1,n)
     pa[i]=i,sz[i]=1;
}

int root(int x)
{
    while(pa[x]!=x)
    {
        pa[x]=pa[pa[x]];
        x=pa[x];
    }
    return x;
}

void Union(int x,int y)
{
    int rx=root(x);
    int ry=root(y);
    if(rx==ry)
        return;
    if(sz[rx]>sz[ry])
    {
        pa[ry]=rx;
        sz[rx]+=sz[ry];
    }
    else
    {
        pa[rx]=ry;
        sz[ry]+=sz[rx];
    }
}

void solve()
{ 
  int n,m,k;
  cin >> n>> m>>k;
  int c[n+1];
  begin_dsu(n);
  fp(i,1,n)
    cin >> c[i];
  while(m--)
  {
      int x,y;
      cin >> x >> y;
      Union(x,y);
  }
  map<int,vector<int>> mp;
  fp(i,1,n)
  {
      mp[root(i)].pb(c[i]);
  }
  int ans=0;
  for(auto x:mp)
  {
      vector<int> v=x.S;
      ans+=(int)v.size();
      map<int,int> freq;
      f(i,v.size())
      {
          freq[v[i]]++;
      }
      int maxm=0;
      for(auto y:freq)
      {
          maxm=max(maxm,y.S);
      }
      ans-=maxm;
  }
  cout << ans << '\n';
  return;
}

signed main()
{
  FAST
  int T=1;
  //  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}