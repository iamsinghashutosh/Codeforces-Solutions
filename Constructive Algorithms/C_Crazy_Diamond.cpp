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
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n;
  cin >> n;
  int a[n+1],pos[n+1]={0};
  fp(i,1,n)
    cin >> a[i],pos[a[i]]=i;
  vii v;
  fp(i,1,n)
  {
      if(pos[i]==i)
        continue;
      if(i<=n/2)
      {
          if(pos[i]<=n/2)
          {
              int val=a[i];
              int p=pos[i];
             swap(a[pos[i]],a[pos[i]+n/2]);
             swap(a[i],a[pos[i]+n/2]);
             swap(a[pos[i]],a[pos[i]+n/2]);
             v.pb({pos[i],pos[i]+n/2});
             v.pb({i,pos[i]+n/2});
             v.pb({pos[i],pos[i]+n/2});
             pos[i]=i;
             pos[val]=p;
          }
          else
          {
              int val2=a[i];
              int val1=pos[i];
              if(pos[i]-i>=(n/2))
              {
                  swap(a[i],a[pos[i]]);
                  v.pb({i,pos[i]});
                  pos[i]=i;
                  pos[val2]=val1;
                  continue;
              }
              swap(a[i],a[i+n/2]);
              swap(a[pos[i]],a[pos[i]-n/2]);
              swap(a[pos[i]-n/2],a[i+n/2]);
              swap(a[i+n/2],a[i]);
              swap(a[pos[i]],a[pos[i]-n/2]);
              v.pb({i,i+n/2});
              v.pb({pos[i],pos[i]-n/2});
              v.pb({pos[i]-n/2,i+n/2});
              v.pb({i+n/2,i});
              v.pb({pos[i],pos[i]-n/2});
              pos[i]=i;
              pos[val2]=val1;
          }
      }
      else
      {
            int val1=pos[i];
              int val2=a[i];
              swap(a[i],a[i-n/2]);
              v.pb({i,i-n/2});
            //   swap(a[pos[i]],a[pos[i]-n/2]);
              swap(a[pos[i]],a[i-n/2]);
              v.pb({pos[i],i-n/2});
              swap(a[i-n/2],a[i]);
              v.pb({i-n/2,i});
            //   swap(a[pos[i]],a[pos[i]-n/2]);
              pos[i]=i;
              pos[val2]=val1;
      }
  }
  cout << sz(v) << '\n'; 
  for(auto x:v)
    cout << x.F << " " << x.S << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
