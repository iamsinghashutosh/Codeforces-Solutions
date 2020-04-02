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
    int x,y,n;
    cin >> x>>y>>n;
    x=(x+mod)%mod;
    y=(y+mod)%mod;
    int fn[6]={x,y,(y-x+mod)%mod,(-x+mod)%mod,(-y+mod)%mod,(x-y+mod)%mod};
    int v=n%6;
    if(v==0)
        v=6;
    v--;
    cout << fn[v] << '\n';

  return ;
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
