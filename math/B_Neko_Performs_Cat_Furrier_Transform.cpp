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
 int x;
 cin >> x;
 if((x&(x+1))==0)
     {
        cout << 0 << '\n';
        cout << '\n';return;
     }
 vector<int> v;
 int cnt=0;
 while(1)
 {
     int ans=0,n;
     fr(i,29,0)
     {
         if((1ll<<i)&(x))
            {
                ans=(1ll<<(i+1));
                n=i+1;
                break;
            }
     }
     x=x^(ans-1);
    //  cout << ans << '\n';
     v.pb(n);
     cnt++;
     if((x&(x+1))==0)
     {
         cout << cnt << '\n';
         f(i,v.size())
            cout << v[i] << " ";
        cout << '\n';return;
     }
     x++;
     cnt++;
       if(((x+1)&(x))==0)
     {
         cout << cnt << '\n';
         f(i,v.size())
            cout << v[i] << " ";
        cout << '\n';return;
     }
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