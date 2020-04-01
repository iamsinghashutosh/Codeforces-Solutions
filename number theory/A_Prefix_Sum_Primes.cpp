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
  int n;
  cin >> n;
  int cnt[3]={0};
  f(i,n)
   {
       int x;
       cin >> x;
       cnt[x]++;
   }
   if(cnt[2]==0)
   {
       while(cnt[1]>0)
        cout << "1 ",cnt[1]--;
     cout << '\n';
   }
   else if(cnt[1]==0)
   {
       while(cnt[2]>0)
        cout << "2 ",cnt[2]--;
     cout << '\n';
   }
   else{
   cout << "2 ";
   cnt[2]--;
    cout << "1 ";
    cnt[1]--;
    while(cnt[2]>0)
     cout <<"2 ",cnt[2]--;
    while(cnt[1]>0)
     cout << "1 ",cnt[1]--;
     cout << '\n';
   }
  return ;
}

signed main()
{
   FAST;
	int T=1;
	// cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
