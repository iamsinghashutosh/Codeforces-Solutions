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

int pa[50],sz[50];

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
  int n,m;
  cin >> n >> m;
  begin_dsu(n);
  int chk[n+1]={0};
  while(m--)
  {
      int a,b;
      cin >> a >> b;
      chk[a]=chk[b]=1;
      Union(a,b);
  }
  map<int,vector<int>> mp;
  vector<int> any;
    fp(i,1,n)
    {
        if(!chk[i])
            any.pb(i);
    }
  fp(i,1,n)
  {
      if(chk[i]==1)
        mp[root(i)].pb(i);
  }

  for(auto x:mp)
      {
          vector<int> v=x.S;
          if(((int)v.size())!=3)
           {
               if(((int)v.size())>3)
               {
                   cout << "-1\n";return;
               }
               int c=3-((int)v.size());
               while(c--)
               {
                if((int)any.size()!=0)
                {
                    
                    Union(any.back(),v[v.size()-1]);
                    mp[x.F].pb(any.back());
                    any.pop_back();
                }
                else
                {
                    cout << "-1\n";return;
                }
               }
           } 
      }
  if(((int)any.size())%3!=0)
  {
      cout << -1 << '\n';
      return;
  }
  else{
      if(((int)any.size())>=3)
      {
          int p=n+1;
          f(i,(int)any.size()-3+1)
          {
              mp[p].pb(any[i]);
              mp[p].pb(any[i+1]);
              mp[p++].pb(any[i+2]);
              i+=2;
          }
      }
  }
  if(((int)mp.size())!=(n/3))
  {
      cout << "-1\n";
  }
  else
  {
      for(auto x:mp)
      {
          vector<int> v=x.S;
          if(((int)v.size())!=3)
           {cout <<-1 << '\n';return;}
         
      }
      for(auto x:mp)
      {
          vector<int> v=x.S;
           cout << v[0] << " " << v[1] << " " << v[2] << '\n';
         
      }
  }
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