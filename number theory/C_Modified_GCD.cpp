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
  int a,b;
  cin >> a >> b;
  if(b<a)
    swap(a,b);
  vector<int> d;
  map<int,int> m;
  fp(i,1,sqrt(a))
  {
      if(a%i==0)
      {
          if(a/i==i)
            m[i]=1;
          else
          {
             m[i]=1;
             m[a/i]=1;
          }
      }
  }
  fp(i,1,sqrt(b))
  {
      if(b%i==0)
      {
          if(b/i==i)
            {
                if(m[i]==1)
                    d.pb(i);
            }
          else
          {
             if(m[i]==1)
                d.pb(i);
             if(m[b/i]==1)
                d.pb(b/i);
          }
      }
  }
  sort(all(d));
//   f(i,d.size())
//     cout << d[i] << " ";
  int n;
  cin >> n;
  int x=d.size();
  while(n--)
  {
      int l,h,pos;
      cin >> l >> h;
      if(upper_bound(all(d),h)==d.end())
        pos=x;
      else  
        pos=upper_bound(all(d),h)-d.begin();
      pos--;
      if(d[pos]>=l)
        cout << d[pos] << '\n';
      else
        cout << -1 << '\n';
  }


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