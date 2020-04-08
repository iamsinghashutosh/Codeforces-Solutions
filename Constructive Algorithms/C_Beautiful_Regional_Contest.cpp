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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{ 
 int n;
 cin >> n;
 map<int,int> m;
 vector<int> v;
 f(i,n)
  {
      int x;
      cin >> x;
      m[x]++;
  }
  for(auto x:m)
  {
      v.pb(x.F);
  }
  reverse(all(v));
//   cout << v[2] << '\n';
  if(v.size()<=3)
  {
      cout << "0 0 0\n";return;
  }
  int g=m[v[0]];
  int s=0,i=1;
  while(s<=g && i<v.size())
  {
      s+=m[v[i++]];
  }
  int b=0;
  int g1,b1,s1,flg=0;
  while(i<v.size() && (g+b+s)<=n/2)
  {
      b+=m[v[i++]];
      if(b>g && (g+b+s)<=n/2)
      {
          flg=1;
          g1=g;s1=s,b1=b;
      }
  }
  if(flg==1)
  {
       cout << g1 << " " <<s1 << " " <<b1 << '\n';  
  }
  else
   cout << "0 0 0\n";
 return;
}

signed main()
{
  int T=1;
  cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
