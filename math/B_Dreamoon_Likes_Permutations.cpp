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
  int a[n+1];
  fp(i,1,n)
    cin >> a[i];
  vector<int> bg,ed;
  set<int> s1,s2;
  int sum=0;
  fp(i,1,n)
  { 
    s1.insert(a[i]);
    sum+=a[i];
    if(s1.size()==i && sum==(i*(i+1))/2)
        bg.pb(i);
  }
  sum=0;
  fr(i,n,1)
  {
      s2.insert(a[i]);
      sum+=a[i];
      if(s2.size()==(n-i+1) && sum==((n-i+1)*(n-i+1+1))/2)
        ed.pb(i);
  }
  sort(all(ed));
  vector<pair<int,int>> v;
  f(i,bg.size())
  {
      if(binary_search(ed.begin(),ed.end(),bg[i]+1))
        {
            v.pb({bg[i],n-bg[i]});
        }
  }
  cout << v.size() << '\n';
  f(i,v.size())
    cout << v[i].F <<" " << v[i].S << '\n';
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
