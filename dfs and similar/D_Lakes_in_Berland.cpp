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
void begin_dsu(int n,int m)
{
   fp(i,1,n)
    fp(j,1,m)
        pa[{i,j}]={i,j},sz[{i,j}]=1;
}

pii root(pii x)
{
    while(pa[x].F!=x.F || pa[x].S!=x.S)
    {
        pa[x]=pa[pa[x]];
        x=pa[x];
    }
    return x;
}

void Union(pii x,pii y)
{
    pii rx=root(x);
    pii ry=root(y);
    if(rx.F==ry.F && rx.S==ry.S)
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
  cin >> n >> m >> k;
  begin_dsu(n,m);
  string a[n+1];
  int b[n+1][m];
  memset(b,0,sizeof b);
  fp(i,1,n)
  {
       cin >> a[i];
  }
  int x=n+m;
  while(x--)
  {
  fp(i,1,n)
  {
      fp(j,0,m-1)
      {
          if(i==1 || j==0 ||i==n || j==m-1)
          {
              if(a[i][j]=='.')
                b[i][j]=1;
          }
        if(a[i][j]=='.')
        {
            if(j!=0 && b[i][j-1]==1)
                b[i][j]=1;
            if(j!=m-1 && b[i][j+1]==1)
                b[i][j]=1;
            if(i!=n && b[i+1][j]==1)
                b[i][j]=1;
            if(i!=1 && b[i-1][j]==1)
            b[i][j]=1;
        }
        if(b[i][j]==1)
        {
             if(j!=0 && a[i][j-1]=='.')
                b[i][j-1]=1;
            if(j!=m-1 && a[i][j+1]=='.')
                b[i][j+1]=1;
            if(i!=n && a[i+1][j]=='.')
                b[i+1][j]=1;
            if(i!=1 && a[i-1][j]=='.')
               b[i-1][j]=1;
        }
      }
  }
  }

  fp(i,2,n-1)
  {
      fp(j,2,m-1)
      {
        if(a[i][j-1]=='.' && b[i][j-1]==0)
        {
              Union({i,j},{i,j});
            if(j!=m-1 && a[i][j]=='.' && b[i][j]==0)
                Union({i,j},{i,j+1});
            if(j!=2 && a[i][j-2]=='.' && b[i][j-2]==0)
                Union({i,j},{i,j-1});
            if(i!=2 && a[i-1][j-1]=='.' && b[i-1][j-1]==0)
                Union({i,j},{i-1,j});
            if(i!=n-1 && a[i+1][j-1]=='.' && b[i+1][j-1]==0)
                Union({i,j},{i+1,j});
        }
      }
  }
  map<pii,vector<pii>>mp;
  fp(i,2,n-1)
  {
      fp(j,2,m-1)
      {
          if(a[i][j-1]=='.' && b[i][j-1]==0)
            mp[root({i,j})].pb({i,j});
      }
  }
  vector<pair<int,pii>> str;
  k=(int)mp.size()-k;
  for(auto x:mp)
  {
     vector<pii> p;
     p=x.S;
      str.pb({p.size(),x.F});
  }

  sort(all(str));
  int ans=0;
  f(i,k)
  {
      pii x=str[i].S;
       vector<pii> p=mp[x];
       ans+=p.size();
       f(j,p.size())
       {
           a[p[j].F][p[j].S-1]='*';
       }
  }
  cout << ans << '\n';
    fp(i,1,n)
      cout << a[i] << '\n';
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