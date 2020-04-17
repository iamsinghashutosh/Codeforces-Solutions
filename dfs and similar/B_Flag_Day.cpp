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
  int col[n+1]={0};
  f(i,m)
  {
      map<int,int> mp;
      int a[3];
      cin >> a[0] >>a[1]>>a[2];
      f(i,3)
        mp[col[a[i]]]=1;
      f(k,3)
      {
          if(col[a[k]]!=0)
            continue;
          fp(j,1,3)
          {
              if(mp[j]==0)
              {
                  col[a[k]]=j;
                  mp[j]=1;break;
              }
          }
      }
  }
  fp(i,1,n)
    cout << col[i] << " \n"[i==n];
  return;
}

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
	}
  return 0;
}
