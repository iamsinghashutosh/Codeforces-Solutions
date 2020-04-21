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

int pa[105],sz[105];

void begin_dsu(int n)
{
    f(i,n+1)
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
    int r_x=root(x);
    int r_y=root(y);
    if(r_x==r_y)
        return;
    if(sz[r_x]<sz[r_y])
    {
        pa[r_x]=r_y;
        sz[r_y]+=sz[r_x];
    }
    else
    {
        pa[r_y]=r_x;
        sz[r_x]+=sz[r_y];
    }   
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  if(m!=n)
    {cout << "NO\n";return;}
  begin_dsu(n);
  f(i,m)
  {
      int x,y;
      cin >> x>> y;
      Union(x,y);
  }
  fp(i,1,n-1)
  {
      if(root(i)!=root(i+1))
        {
            cout << "NO\n";return;
        }
  }
  cout << "FHTAGN!\n";
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