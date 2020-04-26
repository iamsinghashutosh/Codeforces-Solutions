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

int modpw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=(res%mod * a%mod)%mod;
        a=(a%mod * a%mod)%mod;
        b>>=1;
    }
    return res;
}

void solve()
{ 
   int n,x;
    cin >> n >> x;
   map<int,int> m;
   int a[n],sum=0,maxm=0;
   f(i,n)
    {
        cin >> a[i];
        m[a[i]]++;
        sum+=a[i];
        maxm=max(a[i],maxm);   
    }
    int val=sum;
    fr(i,maxm,1)
    {
        m[i-1]+=(m[i]/x);
        m[i]%=x;
        if(m[i])
        {
            val=sum-i;break;
        }
    }
    cout << modpw(x,val) << '\n';
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