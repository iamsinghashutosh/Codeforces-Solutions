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

map<pii,pii> pa;
map<pii,int> sz;
void begin_dsu(int n)
{
    fp(i,1,n)
      fp(j,1,n)
        {pa[{i,j}]={i,j};sz[{i,j}]=1;
        }
}

pii root(pii n)
{
    while(pa[n].F!=n.F || pa[n].S!=n.S)
    {
        pa[n]=pa[pa[n]];
        n=pa[n];
    }
    return n;
}

void Union(pii x,pii y)
{
    pii r_x=root(x);
    pii r_y=root(y);
    if(r_x==r_y)
        return ;
    if(sz[r_x]>sz[r_y])
    {
        pa[r_y]=r_x;
        sz[r_x]+=sz[r_y];
    }
    else
    {
        pa[r_x]=r_y;
        sz[r_y]+=sz[r_x];
    }
}

bool find(pii x,pii y)
{
    return (root(x).F==root(y).F && root(x).S==root(y).S);
}
void solve()
{ 
  int n;
  cin >> n;
  pii r1,r2;
  cin >> r1.F >> r1.S >> r2.F >> r2.S;
  int a[n+1][n+1];
  begin_dsu(n);
  fp(i,1,n)
  {
      string x;
      cin >> x;
      f(j,n)
      {
            a[i][j+1]=x[j]-'0';
      }
  }
  map<pii,set<pii>> val;
  fp(i,1,n)
  {
      fp(j,1,n)
      {
            if(a[i][j]==0) 
                {
                    if(i!=n && a[i+1][j]==0)
                     {  
                         Union({i,j},{i+1,j});                       
                     }
                     if(j!=n && a[i][j+1]==0)
                     {
                         Union({i,j},{i,j+1});
                     }
                     if(i!=1 && a[i-1][j]==0 )
                     {
                        Union({i,j},{i-1,j});
                     }
                     if(j!=1 && a[i][j-1]==0)
                     {
                         Union({i,j},{i,j-1});
                     }
                }
      }
  }
  fp(i,1,n)
  {
      fp(j,1,n)
        val[root({i,j})].insert({i,j});
  }
//   cout << root(r2).F << " " << root(r2).S << '\n'; 
  if(find(r1,r2))
  {
      cout << 0 << '\n';return;
  }
  else
  {
      pii rt1=root(r1);

      pii rt2=root(r2);

      int ans=mod;
      for(auto x:val[rt1])
      {
          for(auto y:val[rt2])
          {
              int dist=(x.F - y.F)*(x.F - y.F) + (x.S - y.S)*(x.S - y.S);
              ans=min(dist,ans);
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
  //  cin >> T;
  fp(i,1,T)
  {
    solve();
  }
  return 0;
}