#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n,k;
  cin >> n >> k;
  char mat[n+1][n+1];
  fp(i,1,n)
   fp(j,1,n)
   {
       if(k==0)
       {
           mat[i][j]='S';
       }
       else
       {
           if(i==1 && j==1)
                {
                    mat[i][j]='L',k--;
                    continue;
                }
            if(j>1  && i==1 && mat[i][j-1]=='S')
            {
                mat[i][j]='L',k--;
                continue;
            }
            if(i>1 && j==1 && mat[i-1][j]=='S')
            {
                mat[i][j]='L',k--;
                    continue;
            }
            if(i>1 && j>1 && mat[i-1][j]=='S' && mat[i][j-1]=='S')
            {
                mat[i][j]='L',k--;
                    continue;
            }
            mat[i][j]='S';
       }
   } 

   if(k)
    cout << "NO\n";
 else   
 {
     cout << "YES\n";
    fp(i,1,n)
     {
      fp(j,1,n)
        cout << mat[i][j] ;
       cout << '\n';
     }
    
 }
  return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
