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

vector<int> divisors(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i == i)
                v.pb(i);
            else
            {
                v.pb(i);v.pb(n/i);
            }
        }
    }
    return v;
} 
 
void solve()
{
  int n,k;
  cin >> n >>k ;
  vector<int> a=divisors(n);
  sort(all(a));
  int ans=(a.size()<k)?-1:a[k-1];
  cout << ans << '\n';
  return ;
}

signed main()
{
   FAST;
	int T=1;
	// cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
