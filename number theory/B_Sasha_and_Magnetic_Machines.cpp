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

vector<int> divisors(int x)
{
    vector<int> v;
    fp(i,1,sqrt(x))
    {
        if(x%i==0)
        {
            if(x/i == i)
                v.pb(i);
            else
                v.pb(i),v.pb(x/i);
        }
    }
    return v;
}

void solve()
{ 
  int n;
  cin >> n;
  int a[n];
  int sum=0;
  f(i,n)
  {
      cin >> a[i];
      sum+=a[i];
  }
  sort(a,a+n);
  int y=sum;
  fp(i,1,n-1)
  {
    int s2=y-a[0]-a[i];
    vector<int> v=divisors(a[i]);
    f(j,v.size())
    {
        int x=s2;
        x+=(a[0]*v[j]);
        x+=(a[i]/v[j]);
        sum=min(sum,x);
    }
  }
  cout << sum << '\n';
  return;
}

signed main()
{
  FAST
  int T=1;
  //  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}