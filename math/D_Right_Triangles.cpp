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
 int n,m;
 cin >> n >> m;
 int a[n+1][m+1];
 int ans=0;
 int r[n+1]={0},c[m+1]={0};
 fp(i,1,n)
 {
     fp(j,1,m)
        {
            char c;
            cin >> c;
            a[i][j]=(c=='*')?1:0;
        }
 }
 fp(i,1,n)
 {
     fp(j,1,m)
     {
         if(a[i][j]==1)
         {
            r[i]++;
            c[j]++;
         }
     }
 }
 fp(i,1,n)
 {
     fp(j,1,m)
     {
         if(a[i][j]==1)
            ans+=(r[i]-1)*(c[j]-1);
     }
 }
 cout << ans << '\n';

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