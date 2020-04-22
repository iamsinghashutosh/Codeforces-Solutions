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

int pa[100005],sz[100005];
int a[100005];

void build_dsu(int n)
{
    fp(i,1,n)
        pa[i]=i,sz[i]=a[i];
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
    int rx=root(x),ry=root(y);
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
  int n;
  cin >> n;
  fp(i,1,n)
    cin >> a[i];
  build_dsu(n);
   int d[n],b[n+1];
   f(i,n)
   {
       cin >> d[i];
       b[d[i]]=-1;
   }
   int maxm=0;
   vector<int> v;
   v.pb(0);
   fr(i,n-1,1)
   {
       if(b[d[i]]==-1)
         {maxm=max(sz[root(d[i])],maxm),b[d[i]]=a[d[i]];}
       if(d[i]!=1 && b[d[i]-1]!=-1)
       {
           Union(d[i],d[i]-1);
           maxm=max(sz[root(d[i])],maxm);
       }
       if(d[i]!=n && b[d[i]+1]!=-1)
       {
           Union(d[i],d[i]+1);
           maxm=max(sz[root(d[i])],maxm);
       }
       v.pb(maxm);
   }
  reverse(all(v));
  f(i,v.size())
    cout <<v[i] << '\n';
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