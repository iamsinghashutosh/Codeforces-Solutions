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
#define mod 5000000
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

int vis[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int flg=0,r,c,n,m;

bool in_range(int x,int y)
{
     if(x>n || y>m || x<=0 || y<=0)
        return false;
    return true;
}

void dfs(int x,int y)
{
    if(x>n || y>m || x<=0 || y<=0)
        return;
    if(x==r && y==c && vis[x][y]==0)
    {
        f(i,4)
        {
        //  if(x==2 && y==2)
        //   {
        //       cout << x+dx[i] << " " << y+dy[i] << '\n';
        //       cout << vis[x+dx[i]][y+dy[i]] << '\n';
        //   }
            if(in_range(x+dx[i],y+dy[i]) && !vis[x+dx[i]][y+dy[i]])
            {
                flg=1;return;
            }
        }
    }
    vis[x][y]=1;
    f(i,4)
    {
        if(in_range(x+dx[i],y+dy[i]))
        {
            if(!vis[x+dx[i]][y+dy[i]])
            {
                dfs(x+dx[i],y+dy[i]);
            }
            else
            {
                if(x+dx[i]==r && y+dy[i]==c)
                {
                    flg=1;return ;
                }
            }
            cout << '\n';
        }
    }
}

void solve()
{
  cin >> n>>m;
  fp(i,1,n)
  {
     string x;
     cin >> x;
     fp(j,1,m)
     {
         vis[i][j]=(x[j-1]=='X')?1:0;
     }
  }
  int x1,y1;
  cin >> x1 >> y1 >> r >> c;
  dfs(x1,y1);
  if(flg)
    cout << "YES\n";
  else  
    cout << "NO\n";
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