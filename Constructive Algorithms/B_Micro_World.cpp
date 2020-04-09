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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{ 
 int n,k;
 cin >> n>>k;
 int a[n];
 f(i,n)
 {
     cin >> a[i];
 }
 sort(a,a+n);
 int ans=1,prev=0;
 fp(i,1,n-1)
 {
     int cnt=0;
     if(a[i]>a[i-1]){
        cnt=lower_bound(a,a+i,a[i]-k)-a;
        ans-=(i-max(prev,cnt));
        prev=i;
    }
    //  prev=max(prev,cnt);
     ans++;
    //  cout << i << " " << ans << '\n';
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
