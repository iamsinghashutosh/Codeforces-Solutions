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
  int n,m;
  cin >> n >> m;
  int w[n+1];
  fp(i,1,n)
    cin >> w[i];
  int b[m];
  f(i,m)
    cin >> b[i];
  map<int,int> mp;
  stack<int> s;
  vector<int> v;
  f(i,m)
    {
     if(mp[b[i]]==0)
     {
         v.pb(b[i]);
         mp[b[i]]=1;
     }        
    }
    reverse(all(v));
    f(i,v.size())
    {
        s.push(v[i]);
    }
    int ans=0;
    f(i,m)
    {
        vector<int> tmp;
        while(s.top()!=b[i])
        {
            ans+=w[s.top()];
            tmp.pb(s.top());
            s.pop();
        }
        s.pop();
        if(!tmp.empty())
        {
            fr(j,tmp.size()-1,0)
            {
                s.push(tmp[j]);
            }
        }
        s.push(b[i]);
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