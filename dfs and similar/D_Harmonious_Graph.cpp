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

const int MAXM=200005;
int size[MAXM],pa[MAXM],mx[MAXM];

void begin_dsu(int n)
{
    f(i,n+1)
    {
        mx[i]=i;
        pa[i]=i;
        size[i]=1;
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
    int root_x=root(x);
    int root_y=root(y);
    if(root_x==root_y)
        return;
    if(size[root_x]<=size[root_y])
    {
        pa[root_x]=root_y;
        size[root_y]+=size[root_x];
        mx[root_y]=max(mx[root_x],mx[root_y]);
    }
    else
    {
        pa[root_y]=root_x;
        size[root_x]+=size[root_y];
        mx[root_x]=max(mx[root_x],mx[root_y]);
    }
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  begin_dsu(n);
  while(m--)
  {
      int x,y;
      cin >> x >> y;
      Union(x,y);
  }
  int ans=0;
  fp(i,1,n-1)
  {
      int y=i+1;
      while(mx[root(i)]>=y)
      {
          if(root(i)!=root(y))
          {
              ans++;
              Union(i,y);
          }
        y++;
      }
      i=mx[root(i)];
  }
  cout << ans << '\n';
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