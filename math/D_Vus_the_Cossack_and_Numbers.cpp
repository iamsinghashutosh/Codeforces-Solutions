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

void solve()
{ 
  int n;
  cin >> n;
  int a[n];
  int sum=0;
  vector<int> l,r;
  f(i,n)
  {
      double x;
      cin >> x;
      a[i]=(int)x;
      sum+=a[i];
      if(x>0 && x!=1.0*a[i])
        r.pb(i);
      if(x<0 && x!=1.0*a[i])
        l.pb(i);
  }
  sum=-sum;
  if(sum>0)
  {
      int x=sum;
     f(i,sum)
     {
         a[r[i]]++;
         x--;
     }
     if(x!=0)
     f(i,x)
     {
         a[l[i]]++;
     }
  }
  else if(sum<0)
  {
      int x=sum;
      f(i,-sum)
        {a[l[i]]--;x++;}
      if(x!=0)
      f(i,-x)
        a[r[i]]--;
  }
  f(i,n)
    cout << a[i] << '\n';
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