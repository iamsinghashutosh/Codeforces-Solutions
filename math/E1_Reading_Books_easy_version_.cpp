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
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n,k;
  cin >> n >> k;
  vector<pii> a,b,v;
  map<int,int> m;
  f(i,n)
  {
      int x,y,z;
      cin >> x >> y >> z;
      if(y==1 && z==1)
        v.pb({x,i});
      else if(y==1 && z==0)
        a.pb({x,i});
      else if(z==1 && y==0)
        b.pb({x,i});
  }
  sort(all(v));
  sort(all(a));
  sort(all(b));
  if((sz(a)+sz(v))<k || (sz(v)+sz(b))<k)
    cout << -1 << '\n';
  else
  {
      int minm=min(sz(a),sz(b));
      int ans=0;
      if(minm<k)
      {
          if(sz(a)==minm)
          {
              f(i,sz(a))
               {
                   ans+=a[i].F;
                   m[a[i].S]=1;
               }
               f(i,k-sz(a))
               {
                   ans+=v[i].F;
                   m[a[i].S]=1;
               }
               f(i,sz(a))
               {
                   ans+=b[i].F;
                   m[b[i].S]=1;
               }
                int posb=sz(a)-1,posa=sz(a)-1;
               fp(i,k-sz(a),sz(v)-1)
               {
                   if(posa>=0 && b[posb].F+a[posa].F>v[i].F)
                   {
                       ans+=v[i].F;
                       ans-=(b[posb].F+a[posa].F);
                       m[b[posb].S]=0;
                       m[a[posa].S]=0;
                       m[v[i].S]=1;
                       posa--;
                       posb--;
                   }
               }
          }
          else
          {
               f(i,sz(b))
               {
                   ans+=b[i].F;
                   m[b[i].S]=1;
               }
               f(i,k-sz(b))
               {
                   ans+=v[i].F;
                   m[v[i].S]=1;
               }
               f(i,sz(b))
               {
                   ans+=a[i].F;
                   m[a[i].S]=1;
               }
                int posb=sz(b)-1,posa=sz(b)-1;
               fp(i,k-sz(b),sz(v)-1)
               {
                   if(posb>=0 && a[posb].F+b[posa].F>v[i].F)
                   {
                       ans+=v[i].F;
                       ans-=(a[posb].F+b[posa].F);
                       m[b[posa].S]=0;
                       m[a[posb].S]=0;
                       m[v[i].S]=1;
                       posa--;
                       posb--;
                   }
               }
          }
      }
      else
      {
          f(i,k)
          {
              ans+=a[i].F;
              ans+=b[i].F;
              m[a[i].S]=1;
              m[b[i].S]=1;
          }
          int pos=k-1;
          f(i,sz(v))
          {
              if(pos>=0 && v[i].F<(a[pos].F+b[pos].F))
              {
                  ans+=v[i].F;
                  ans-=(a[pos].F+b[pos].F);
                  m[a[pos].S]=0;
                  m[b[pos].S]=0;
                  m[v[i].S]=1;
                  pos--;
              }
              else
                break;
          }
      }
        cout << ans << '\n';
      for(auto x:m)
      {
          cout << x.F+1 << " ";
      }
      cout << '\n';
  } 
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
