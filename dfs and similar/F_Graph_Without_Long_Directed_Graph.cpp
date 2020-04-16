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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve()
{ 
  int n,m;
  cin >> n >> m;
  vector<int> v[n+1];
  map<int,pair<int,int>> mp;
  f(i,m)
  {
    int x,y;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
    mp[i]={x,y};
  }
  int col[n+1];
  int is_Bipartite=1;
  memset(col,-1,sizeof(col));

  queue<int> q;
  fp(i,1,n)
  {
    if(col[i]==-1)
      {
        col[i]=0;
        q.push(i);
      }
        while(!q.empty())
        {
         
          int f=q.front();
          q.pop();
          f(j,v[f].size())
          {
            if(col[v[f][j]]==-1)
            {
              col[v[f][j]]=col[f]^1;
              q.push(v[f][j]);
            }
            else
              is_Bipartite &=(col[v[f][j]]!=col[f]);
          }
        }
  }
  if(is_Bipartite==0)
    cout << "NO\n";
  else  
    {
      cout << "YES\n";
      f(i,m)
      {
        if(col[mp[i].F]==0 && col[mp[i].S]==1)
          cout << 1;
        else
          cout << 0;
      }
      cout << '\n';
    }
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
