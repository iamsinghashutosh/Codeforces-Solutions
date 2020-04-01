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
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
 
void solve()
{
  int primes[11]={2,3,5,7,11,13,17,19,23,29,31};
  int col[11];
  memset(col,0,sizeof(col));
  int n;
  cin >> n;
  int ans[n],c=1,mx=1;
  f(i,n)
  {
      int x;
      cin >> x;
      f(j,11)
      {
          if((x%primes[j])==0)
            {
                if(col[j]!=0)
                    ans[i]=col[j];
                else
                    ans[i]=c,col[j]=c++;
                mx=max(mx,ans[i]);
                break;
            }
      }
  }
  cout << mx << '\n';
  f(i,n)
    cout << ans[i] << " \n"[i==n-1];
  return ;
}

signed main()
{
   FAST;
	int T=1;
	cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
