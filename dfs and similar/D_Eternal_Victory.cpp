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

void solve()
{ 
  int n,s=0;
  cin >> n;
  vector<pii> v[n+1];
  f(i,n-1)
  {
      int x,y,w;
      cin >> x >> y >> w;
      v[x].pb({y,w});
      v[y].pb({x,w});
      s+=2*w;
  }
  int ans[n+1]={0};
  
  queue<int> q;
  q.push(1);
  int vis[n+1]={0};
  vis[1]=1;
  while(!q.empty())
  {
      int p=q.front();
      q.pop();
      for(auto x:v[p])
      {
          if(!vis[x.F])
          {
              vis[x.F]=1;
              q.push(x.F);
              ans[x.F]=ans[p]+x.S;
          }
      }
  }
  int dif=*max_element(ans,ans+n+1);
  cout << s-dif << '\n';
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