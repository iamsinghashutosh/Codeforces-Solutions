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
 int a[n+1];
 int len[n+1]={0};
 fp(i,1,n)
  cin >> a[i];
 int st=1;
 set<int> start;
 set<pii,greater<pii>> s;
 fp(i,2,n)
 {
   if(a[i]!=a[i-1])
   {
     len[st]=i-st;
     start.insert(st);
     s.insert({len[st],-st});
     st=i;
   }
 }
 len[st]=n+1-st;
 start.insert(st);
 s.insert({len[st],-st});
 int ans=0;
 while(!s.empty())
 {
   st=-((*s.begin()).second);
   s.erase(s.begin());
   if(start.find(st)==start.end())
    continue;
   ans++;
   start.erase(st);
   if(!start.empty())
   {
     auto itr=start.lower_bound(st);
     if(itr==start.begin() || itr==start.end())
      continue;
     int rt=*itr;
     itr--;
     int lt=*itr;
     if(a[lt]==a[rt])
     {
       len[lt]+=len[rt];
       s.insert({len[lt],-lt});
       start.erase(rt);
     }
   }
 }
 cout << ans << '\n';
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
