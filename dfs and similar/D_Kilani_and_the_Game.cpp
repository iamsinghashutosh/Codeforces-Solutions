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

int n,m,p;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool isValid(int x,int y)
{
  if(x<1 || x>n || y<1 || y>m)
    return false;
  return true;
}
void solve()
{
  cin >> n>> m>> p;
  int mat[n+1][m+1];
  int sp[p+1];
  fp(i,1,p)
    cin >> sp[i];
  int cnt[p+1]={0};
  queue<pii> q[p+1];
  fp(i,1,n)
  {
    string s;cin >> s;
    f(j,m)
      {
        if(s[j]>='1' && s[j]<='9') 
         {
           q[s[j]-'0'].push({i,j+1});
           mat[i][j+1]=(s[j]-'0');
         }
        else
        {
          mat[i][j+1]=(s[j]=='.')?0:-1;
        }
      }
  }
  while(1)
  {
    int flg=0;
    fp(k,1,p)
    {
      f(i,sp[k])
      {
          int fx=sz(q[k]);
        if(fx==0) 
          break;
        f(j,fx)
        {
          pii pr=q[k].front();
          int x=pr.F,y=pr.S;
          q[k].pop();
          f(r,4)
          {
            int xx=x+dx[r];
            int yy=y+dy[r];
            if(isValid(xx,yy) && mat[xx][yy]==0)
            {
              flg=1;
              mat[xx][yy]=k;
              q[k].push({xx,yy});
            }
          }
        }
      }
    }
    // fp(i,1,n)
    // {
    //   fp(j,1,m)
    //     cout << mat[i][j] << " \n"[j==m];
    // }
    if(!flg)
      break;
  }
    fp(i,1,n)
    {
      fp(j,1,m)
        if(mat[i][j]<=9 && mat[i][j]>=1)
          cnt[mat[i][j]]++;
    }
    fp(i,1,p)
      cout << cnt[i] << " \n"[i==p];
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
