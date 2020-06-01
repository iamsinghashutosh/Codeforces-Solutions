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
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve()
{
  int n,x;
  cin >> n >> x;
  int a[n];
  f(i,n)
    cin >> a[i];
  sort(a,a+n);
  int sum=0,cnt=0;
  f(i,n)
  {
      if(a[i]&1)
      {
          cnt++;
      }
  }
  if(x<cnt)
  {
      if(x&1 || (x%2==0 && (cnt!=n)))
        {cout << "Yes\n";return;}
      else
        {cout << "No\n";return;}
  }
  else if(x>=cnt && (cnt&1 || (cnt>0 && cnt%2==0 && (n-x)>=1)))
  {
      cout << "Yes\n";return;
  }
  cout << "No\n";
  return;
} 

signed main()
{
  FAST
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}