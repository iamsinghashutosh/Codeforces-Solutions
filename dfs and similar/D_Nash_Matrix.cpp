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
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n;
int x[1005][1005],y[1005][1005],vis[1005][1005];
char mat[1005][1005];

bool isValid(int xx,int yy)
{
  if(xx<1 || xx>n || yy<1 || yy>n)
    return false;
  return true;
}

void dfs(int x1,int y1)
{
  vis[x1][y1]=1;
   f(i,4)
   {
     int xx=x1+dx[i];
     int yy=y1+dy[i];
     if(isValid(xx,yy) && !vis[xx][yy] && x[xx][yy]==x[x1][y1] && y[xx][yy]==y[x1][y1])
     {
       if(i==0)
          mat[xx][yy]='L';
       if(i==1)
        mat[xx][yy]='U';
       if(i==2)
        mat[xx][yy]='D';
       if(i==3)
        mat[xx][yy]='R';
       dfs(xx,yy);
     }
   }
}

void dfs1(int x1,int y1)
{
  f(i,4)
  {
    int xx=x1+dx[i];
    int yy=y1+dy[i];
    if(isValid(xx,yy) && x[xx][yy]==x[x1][y1] && y[xx][yy]==y[x1][y1] )
    {
      if(i==0)
      {
        mat[xx][yy]='L';
        mat[x1][y1]='R';
      }
      else if(i==1)
      {
        mat[xx][yy]='U';
        mat[x1][y1]='D';
      }
      else if(i==2)
      {
        mat[xx][yy]='D';
        mat[x1][y1]='U';
      }
      else
      {
        mat[xx][yy]='R';
        mat[x1][y1]='L';
      }
    }
  }
}

void solve()
{
   cin >> n;
   fp(i,1,n)
   {
     fp(j,1,n)
     {
       cin >> x[i][j] >> y[i][j];
     }
   }
   fp(i,1,n)
   {
     fp(j,1,n)
     {
       if(x[i][j]!=-1 && x[i][j]==i && y[i][j]==j)
       {
         mat[i][j]='X';
         dfs(i,j);
       }
     }
   }
   fp(i,1,n)
   {
     fp(j,1,n)
     {
       if(x[i][j]!=-1 && (mat[i][j]=='\0'))
       {
         cout << "INVALID\n";return;
       }
     }
   }
   fp(i,1,n)
   {
     fp(j,1,n)
     {
       if(x[i][j]==-1 && (mat[i][j]=='\0'))
       {
         dfs1(i,j);
       }
     }
   }
   fp(i,1,n)
   {
     fp(j,1,n)
     {
       if(mat[i][j]=='\0')
       {
         cout << "INVALID\n";return;
       }
     }
   }
   cout << "VALID\n";
   fp(i,1,n)
    {
      fp(j,1,n)
      cout << mat[i][j];
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
