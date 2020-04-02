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
  int a[n];
  int sum=0,maxm=0;
  f(i,n)
    {
        cin >> a[i];
        sum+=a[i];
        if(a[i]>maxm)
            maxm=a[i];
    }
   if(sum&1)
   {
       cout << "NO\n";return;
   }
   sum-=maxm;
   if(sum<maxm)
    {
        cout << "NO\n";return;
    }
   if((sum%2)==(maxm%2))
   {
       cout << "YES\n";
   }
   else
   cout << "NO\n";
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
