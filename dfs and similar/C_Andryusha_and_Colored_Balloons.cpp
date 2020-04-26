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
  int n;
  cin >> n;
  int mx=0;
  vector<int> v[n+1];
  f(i,n)
  {
      int x,y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
  } 
  int col[n+1],prev[n+1],vis[n+1]={0};
  queue<int> q;
  q.push(1);
  col[1]=1;
  vis[1]=1;
  prev[1]=1;
  while(!q.empty())
  {
      int p=q.front();
      q.pop();
      int c=1;
      for(auto u:v[p])
      {
          if(!vis[u])
          {
              vis[u]=1;
              q.push(u);
              while(c==col[p] || c==prev[p])
                c++;
              col[u]=c;
              mx=max(mx,c);
              prev[u]=col[p];
              c++;
          }
      }
  }
  cout << mx << '\n';
  fp(i,1,n)
    cout << col[i] << " \n"[i==n];
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