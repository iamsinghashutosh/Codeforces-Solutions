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
    string s;
    cin >> s;
    int a[1000005];
    int j=0;
    f(i,n)
    {
        if(s[i]=='0' || s[i]=='1')continue;
        else if(s[i]=='2' || s[i]=='3' || s[i]=='5' || s[i]=='7')
            a[j++]=s[i]-'0';
        else if(s[i]=='4')
            a[j++]=2,a[j++]=2,a[j++]=3;
        else if(s[i]=='6')
            a[j++]=3,a[j++]=5;
        else if(s[i]=='8')
            a[j++]=7,a[j++]=2,a[j++]=2,a[j++]=2;
        else 
            a[j++]=7,a[j++]=2,a[j++]=3,a[j++]=3;
    }
    sort(a,a+j,greater<>());
    f(i,j)
        cout << a[i];
    cout << '\n';
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
