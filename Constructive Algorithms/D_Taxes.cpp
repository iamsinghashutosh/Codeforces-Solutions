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

bool isPrime(int x)
{
    if(x<=1)
        return false;
    if(x<=3)
        return true;
    fp(i,2,sqrt(x))
    {
        if(x%i==0)
            return false;
    }
    return true;
}

void solve()
{ 
  int n;
  cin >> n;
  if(isPrime(n))
    cout << 1 << '\n';
  else if(n%2==0)
    cout << 2 << '\n';
  else{
      if(isPrime(n-2))
        cout << 2 << '\n';
      else 
       cout << 3 << '\n';
  }
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
