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
  int n;
  cin >> n;
  int dp[n+1][n+1];
  fp(i,1,n)
  {
      fp(j,1,n)
        {
            cin >> dp[i][j];
        }
  }

  vector<int> v;
 
  f(i,n)
  {
      int x;
      cin >> x;
      v.pb(x);
  }

  reverse(all(v));
   
   int flg[n+1];
   memset(flg,0,sizeof(flg));

   vector<int> ans;

    f(k,v.size())
        {
            flg[v[k]]=1;
            fp(i,1,n)
            {
                fp(j,1,n)
                {
                    dp[i][j]=min(dp[i][j],dp[i][v[k]]+dp[v[k]][j]);
                }
            }
            int sum=0;
            fp(i,1,n)
                {
                    fp(j,1,n)
                        {
                            if(flg[i] && flg[j] )
                                sum+=dp[i][j];
                        }
                }
            ans.pb(sum);
        }
        reverse(all(ans));
      f(i,ans.size())
        cout << ans[i] <<  " \n"[i==ans.size()-1];
     return;
}

signed main()
{
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
