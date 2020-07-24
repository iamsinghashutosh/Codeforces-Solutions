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
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

void solve()
{
  int n,q;
  cin >> n>> q;
  int a[n];
  f(i,n)
    cin >> a[i];
  sort(a,a+n);
  while(q--)
  {
      int x;
      cin >> x;
      if(x==0)
        cout << "0\n";
      else if(lb(a,a+n,x)==a+n)
        cout << "-1\n";
      else
        cout << a[lb(a,a+n,x)-a]<<'\n';
  }
  return;
} 

signed main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
