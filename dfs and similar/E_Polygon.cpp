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
int mat[55][55],done[55][55];
int dx[2]={0,-1};
int dy[2]={-1,0};
int n;
bool isValid(int x,int y)
{
    if(x<1 ||x>n ||y<1 || y>n)
        return false;
    return true;
}

void dfs(int x,int y)
{
    done[x][y]=1;
   f(i,2)
   {
       int xx=x+dx[i];
       int yy=y+dy[i];
       if(isValid(xx,yy) && mat[xx][yy]==1 && done[xx][yy]==0)
            dfs(xx,yy);
          
   }
}

void solve()
{
    cin >> n;
 
    fp(i,1,n)
      {
          string s;
        cin >> s;
        fp(j,1,n)
            {
                done[i][j]=0;
                mat[i][j]=s[j-1]-'0';
            }
      }
    fp(i,1,n)
    {
        if(mat[n][i]==1 && done[n][i]==0)
            dfs(n,i);
    }
    fp(i,1,n)
    {
         if(mat[i][n]==1 && done[i][n]==0)
            dfs(i,n);
    }
    fp(i,1,n)
    {
        fp(j,1,n)
        {
            if(mat[i][j]==1 && done[i][j]==0)
            {
                cout << "NO\n";return;
            }
        }
    }
    cout << "YES\n";
  return;
} 

signed main()
{
  FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}