#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt1=0,cnt2=0;
  int flg=0;
  f(i,s.length())
  {
     while(i+1<s.length() && s[i]=='(' && s[i+1]==')')
     {
         s.erase(s.begin()+i);
         s.erase(s.begin()+i);
         i--;
     }
  }
  n=s.length();
  fr(i,n-1,0)
  {
      if(s[i]=='(')
        {flg=1;continue;}
      if(flg)
        cnt1++;
  }
  flg=0;
  f(i,n)
  {
      if(s[i]==')')
        {flg=1;continue;}
      if(flg)
        cnt2++;
  }
  cnt1=min(cnt1,cnt2);
  cout << cnt1 << '\n';
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
