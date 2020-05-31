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
  int n,k;
  cin >> n >> k;
  set<int> pos,res;
  int a[n];
  f(i,n)
    cin >> a[i];
  f(i,min(n,k))
    pos.insert(i);
  int cnt[n]={0};
  int nxt=min(n,k);
  double c=0,tst=0;
  while(sz(pos)>0)
  {
    set<int> tmp;
    for(auto x:pos)
    {
      if(cnt[x]==tst && cnt[x]!=0)
        res.insert(x);
      if(cnt[x]==a[x])
      {
        c++;
        tmp.insert(x);
        if(nxt<n)
         {
           pos.insert(nxt);
          nxt++;
         }
        // continue;
      }
      cnt[x]++;
    }
    for(auto x:tmp)
    {
      pos.erase(pos.find(x));
    }
    tst=round(100.0*c/(double)n);
  }
  cout << sz(res) << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}