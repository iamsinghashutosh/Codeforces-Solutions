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
#define FAST ios: :sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{ 
  int n,m;
  cin >> n >> m;
  vector<int> v[n+1];
  f(i,m)
  {
      int x,y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
  }
  queue<int> q;
  int is_Bipartite=1;
  int col[n+1];
  fp(i,0,n)
    col[i]=-1;
  fp(i,1,n)
  {
      if(col[i]==-1)
      {
          col[i]=0;
          q.push(i);
          while(!q.empty())
          {
              int p=q.front();
              q.pop();
              f(j,v[p].size())
              {
                  if(col[v[p][j]]==-1)
                  {
                      col[v[p][j]]=col[p]^1;
                      q.push(v[p][j]);
                  }
                  else
                    is_Bipartite &=(col[v[p][j]]!=col[p]);
              }
          }
      }
  }
  if(!is_Bipartite)
    cout << -1 << '\n';
  else
  {
      vector<int> l,r;
      fp(i,1,n)
      {
          if(col[i]==0)
            l.pb(i);
          else
            r.pb(i);
      }
      cout << l.size() << '\n';
      f(i,l.size())
        cout << l[i] << " \n"[i==l.size()-1];
      cout << r.size() << '\n';
      f(i,r.size())
        cout << r[i] << " \n"[i==r.size()-1];
  }
 return;
}

signed main()
{
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
	}
  return 0;
}