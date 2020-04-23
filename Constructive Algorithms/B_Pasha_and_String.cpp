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
  int m;
  string s;
  cin >>s>>m;
  int n=(int)s.length();
  int pre[n+2];
  memset(pre,0,sizeof pre);
  fp(i,1,m)
  {
      int x;
      cin >> x;
      pre[x-1]++;
      pre[n-x+1]--;
  }
  fp(i,1,n-1)
  {
      pre[i]+=pre[i-1];
    //   cout << pre[i];
  }
  f(i,(n+1)/2)
  {
      if(pre[i]==pre[n-i-1] && pre[i]%2==1)
      {
          swap(s[i],s[n-i-1]);
      }
  }
  cout << s << '\n';
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