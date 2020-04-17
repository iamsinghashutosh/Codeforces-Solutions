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

const int MXM=500005;
int sz[MXM],pa[MXM];

void begin_dsu(int n)
{
    f(i,n+1)
    {
        sz[i]=1;
        pa[i]=i;
    }
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
    int root_x=root(x),root_y=root(y);
    if(root_x==root_y)
        return;
    if(sz[root_x]<sz[root_y])
    {
        pa[root_x]=root_y;
        sz[root_y]+=sz[root_x];
    }
    else
    {
        pa[root_y]=root_x;
        sz[root_x]+=sz[root_y];
    }
}


void solve()
{ 
  int n,m;
  cin >> n >> m;
  begin_dsu(n);
  while(m--)
  {
      int k;
      cin >> k;
      if(k==0)
        continue;
      int prev;
      cin >> prev;
      fp(i,1,k-1)
      {
          int x;
          cin >> x;
         Union(prev,x);
         prev=x;
      }
  }
  fp(i,1,n)
   cout << sz[root(i)] << " \n"[i==n];
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