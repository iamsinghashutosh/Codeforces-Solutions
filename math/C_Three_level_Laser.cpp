/*
 * 	How to be brave
 * 	How can I love when I am afraid to fall...
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
  double n,u;
  vector<double> v;
  cin >> n >> u;
  f(i,n)
  {
    double x;
    cin >> x;
    v.pb(x);
  }
  double ans=-1;
  f(i,n-2)
  {
    int pos;
    if(upper_bound(all(v),u+v[i])==v.end())
        pos=n;
    else
    pos=upper_bound(all(v),u+v[i])-v.begin();
    pos--;
    if(pos<=(i+1))
        continue;
    if((v[pos]-v[i])==0)
    {
       continue;
    }
    double x=((double)(v[pos]-v[i+1]))/((double)(v[pos]-v[i]));
//    if(x>1.0)
//         cout << pos << " " << v[i] << " " << v[i+1] << '\n';
    ans=max(ans,x);
  }
  cout << fixed << setprecision(10) << ans  << '\n';
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
