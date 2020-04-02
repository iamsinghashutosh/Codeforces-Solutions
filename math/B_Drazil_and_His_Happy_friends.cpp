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
  map<int,int> hb,hg;
  int n,m;
  cin >> n >> m;
  int b,g;
  cin >> b ;
  f(i,b)
  {
      int x;
      cin >> x;
      hb[x]=1;
  }
  cin >> g;
  f(i,g)
    {
        int x;
        cin >> x;
        hg[x]=1;
    }
//   int l=2;
//   while(l--)
//   {
  f(i,10000*max(n,m))
  {
      if(hb[i%n]==1 || hg[i%m]==1)
      {
          hb[i%n]=1;
          hg[i%m]=1;
      }
  }
//   }
  f(i,n)
  {
      if(hb[i]==0)
      {cout << "No\n";return;}
  }
  f(i,m)
  {
      if(hg[i]==0)
        {
            cout << "No\n";return;
        }
  }
  cout << "Yes\n";
  return ;
} 
 
signed main()
{
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
