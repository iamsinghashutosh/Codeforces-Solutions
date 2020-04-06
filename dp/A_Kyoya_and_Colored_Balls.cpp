/*
 Ashutosh Singh
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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{ 
 int nCr[1001][1001];
 fp(i,0,1000)
 {
   fp(j,0,i)
    {
      if(j==0 || i==j || i==0)
        nCr[i][j]=1;
      else
        nCr[i][j]=(nCr[i-1][j-1] + nCr[i-1][j])%mod;
    }
 }
 int k;
 cin >> k;
  int col[k];
  f(i,k)
    cin >> col[i];
  int sum=0,ans=1;
  f(i,k)
  {
    ans= ((ans%mod) *  (nCr[sum+col[i]-1][col[i]-1]%mod))%mod;
    sum+=col[i];
  }
  cout << ans << '\n';
 return;
}

signed main()
{
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
