/*
  Author:-Ashutosh Singh
  Problem Link:-https://codeforces.com/problemset/problem/546/D
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

int v[5000001];
int isPrime[5000001];
void solve()
{
  int a,b;
  cin >> a >> b;
  cout << (v[a]-v[b]) << '\n';
  
  return ;
} 
 
signed main()
{
  FAST
  int T=1;
  cin >> T;
  fp(i,2,5000000)
  {
    if(isPrime[i]==0)
    {
      v[i]++;
      for(int j=2*i;j<=5000000;j+=i)
      {
        int x=j;
          while(x%i==0)
          {
                v[j]++;
                  x/=i;
          }
          isPrime[j]=1;
      }
    }
  }
  fp(i,1,5000000)
   v[i]+=v[i-1];
  while(T--)
  {
    solve();
  }
  return 0;
}
