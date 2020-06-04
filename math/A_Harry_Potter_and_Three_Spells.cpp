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
  int a,b,c,d,e,f;
  cin >> a >>b >> c >> d >>e >> f;
  if(d==0)
    {cout << "Hermione\n";return;}
  if(c==0)	
    {cout << "Ron\n" ;return ;}
  if(b==0)
    {cout << "Hermione\n";return;}
  if(a==0)
  	{cout << "Ron\n" ;return ;}
  if(f==0)
  	{cout << "Hermione\n";return;}
  if(e==0)
  	{cout << "Ron\n" ;return ;}
  int x=(b*d*f);
  int y=(a*c*e);
  if(((x%y) && (x/y)>=1) || (x/y)>1)
  cout << "Ron\n";
  else
  cout << "Hermione\n"; 
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
