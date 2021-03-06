

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

vector<int> v[100005];
int vis[100005],col[100005];
int flg=1,child_col;
set<int> rt;
void dfs(int x)
{
    vis[x]=1;
    for(auto u:v[x])
    {
        if(!vis[u])
        {
            if(col[u]==col[x])
               {
                   dfs(u);
               }
            else
                {
                    rt.insert(u);
                    rt.insert(x);
                    return ;
                }
            
        }
    }
    return;
}

void dfs1(int x)
{
    vis[x]=1;
    if(col[x]!=child_col)
        flg=0;
    for(auto u:v[x])
    {
        if(!vis[u])
        {
          dfs1(u);
        }
    }
}

void solve()
{ 
  int n;
  cin >> n;
  f(i,n-1)
  {
      int x,y;
      cin >> x>>y;
      v[x].pb(y);
      v[y].pb(x);
  }
  fp(i,1,n)
    cin >> col[i];
  int r=1;
  while(v[r].size()!=1)
    r++;
  dfs(r);
  if(rt.size()==0)
  {
      cout << "YES\n1\n";return;
  }
  for(auto root:rt)
  {
      memset(vis,0,sizeof(vis));
        vis[root]=1;
        int ans=0;
        for(auto u:v[root])
        {
            if(!vis[u])
            {
                child_col=col[u];
                flg=1;
                dfs1(u);
                if(flg!=1)
                    {
                        ans=-1;break;
                    }
            }
        }
        if(ans==0)
            {cout << "YES\n" << root << '\n';return;}
  }

  cout << "NO\n";return;
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