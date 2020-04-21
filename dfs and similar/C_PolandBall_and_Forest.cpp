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

int pa[10005],sz[10005];
void begin_dsu(int n)
{
    fp(i,1,n)
        {pa[i]=i;sz[i]=1;}
}

int root(int n)
{
    while(pa[n]!=n)
    {
        pa[n]=pa[pa[n]];
        n=pa[n];
    }
    return n;
}

void Union(int x,int y)
{
    int r_x=root(x);
    int r_y=root(y);
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

bool find(int x,int y)
{
    return root(x)==root(y);
}
void solve()
{ 
  int n;
  cin >> n;
  begin_dsu(n);
  int p[n+1];
  fp(i,1,n)
    {
        cin >> p[i];
        Union(p[i],i);
    }
   map<int,int> mp;
   int ans=0;
   fp(i,1,n)
   {
       if(mp[root(i)]==0)
       {
           ans++;
           mp[root(i)]=1;
       }
   }
 cout << ans << '\n';
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