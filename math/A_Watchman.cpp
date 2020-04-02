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
    int n;
    cin >> n;
    map<int,int> x,y;
    map<pair<int,int>,int>m;
    vector<pair<int,int>> v;
    f(i,n)
    {
        int a,b;
        cin >> a >> b;
        v.pb({a,b});
        m[{a,b}]++;
        x[a]++;
        y[b]++;
    }
    int ans=0;
    for(auto i:x)
        ans+=(((i.S)*(i.S-1))/2);
    for(auto i:y)
         ans+=(((i.S)*(i.S-1))/2);
    for(auto i:m)
        ans-=(((i.S)*(i.S-1))/2);
    cout << ans << '\n';
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
