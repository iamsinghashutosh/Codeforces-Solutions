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
  set<string> s;
  map<char,vector<string>> m;
  int n,q;
  cin >> n >> q;
  f(i,q)
  {
      string x;
      char c;
      cin >> x >> c;
      m[c].pb(x);
  }
  vector<string> v;
  fp(len,2,n)
  {
      if(len==2)
        f(i,m['a'].size())
        {
            v.pb(m['a'][i]);
        }
      else
        {
            int sz=(int)v.size();
            f(i,sz)
            {
                string x;
                f(j,m[v[i][0]].size())
                {
                    x=m[v[i][0]][j];
                    fp(k,1,v[i].length()-1)
                    {
                        x.pb(v[i][k]);
                    }
                    v.pb(x);
                }
            }
            v.erase(v.begin(),v.begin()+sz);
        }
  }
  f(i,v.size())
  {
      s.insert(v[i]);
  }
  cout << (int)s.size() << '\n';
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