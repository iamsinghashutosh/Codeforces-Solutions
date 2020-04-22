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
  int n,h,d;
  cin >> n >> d >> h;
  if(d<h || d>2*h)
    cout << -1 << '\n';
  else
  {
    vector<pii> v;
    fp(i,1,h)
    {
        v.pb({i,i+1});
    }
    int x=h+2;
    int cnt=d-h;
    int flg=0;
    if(cnt>=1)
        {
            v.pb({1,h+2}),cnt--;
            flg=1;
        }
    f(i,cnt)
    {
        v.pb({x,x+1});
        x++;
        flg=1;
    }
    if(x>n && flg==1)
    {
        cout << -1 << '\n';return ;
    }
    if(flg==0)
        x=h+1;
    fp(i,x+1,n)
    {
      if(h==1 && (d-h)==0)
       {cout << -1 << '\n';return;}
      else
        {
             v.pb({h,i});
            
        }
    }
    f(i,v.size())
        cout << v[i].F << " " << v[i].S << '\n';
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