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

int pos[200005];

bool cmp(const int a,const int b)
{
    return pos[a]<pos[b];
}

void solve()
{ 
  int n;
  cin >> n;
  vector<int> v[n+1];
  f(i,n-1)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
   int a[n];
   f(i,n)
    {cin >> a[i];pos[a[i]]=i;}
   if(a[0]!=1)
   {
       cout << "No\n";return;
   }
   fp(i,1,n)
   {
       sort(all(v[i]),cmp);
   }
  int vis[n+1]={0};
  vis[1]=1;
  queue<int> q;
  vector<int> ans;
  q.push(1);
  while(!q.empty())
  {
      int p=q.front();
      q.pop();
      ans.pb(p);
      for(auto x:v[p])
      {
          if(!vis[x])
          {
              vis[x]=1;
              q.push(x);
          }
      }
  }
  fp(i,1,n)
    if(!vis[i] || ans[i-1]!=a[i-1])
    {
            cout << "No\n";return;
    }
  cout << "Yes\n";
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