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

const int sz=1000005;
int ans[sz][15];

int fn(int x)
{
    int ans=1;
    while(x)
    {
        if(x%10)
            ans*=(x%10);
        x/=10;
    }
    return ans;
}

int g(int x)
{
    if(x<10)
        return x;
    return g(fn(x));
}

void solve()
{ 
 fp(i,1,1000000)
 {
     f(j,10)
      ans[i][j]=ans[i-1][j];
     ans[i][g(i)]++;
 }
//  fp(i,1,50)
//  {
//      cout << g(i) << " ";
//  }
 int q;
 cin >> q;
 while(q--)
 {
     int l,r,k;
     cin >> l >> r >> k;
     cout << ans[r][k]-ans[l-1][k] << '\n';
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