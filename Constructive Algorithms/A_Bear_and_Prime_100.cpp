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
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

bool isPrime(int a)
{
    if(a<=3)
        return true;
    fp(i,2,sqrt(a))
    {
        if(a%i==0)
            return false;
    }
    return true;
}

void solve()
{ 
    vector<int> v;
    fp(i,2,100)
    {
        if(isPrime(i))
            v.pb(i);
    }
    // cout << v.size();
  int cnt=0,t=0,j=0;
  while(1)
  {
      printf("%d\n",v[j]);
      fflush(stdout);
      char s[4];
      scanf("%s",s);
      if(s[0]=='y')
        cnt++;
      t++;
      if(cnt>=2)
      {
          printf("composite\n");fflush(stdout);
          return;
      }
      if(t==20)
        break;
    if(s[0]=='y' && v[j]*v[j]<=100)
      {
          printf("%d\n",v[j]*v[j]);
          t++;
            fflush(stdout);
            scanf("%s",s);
            if(s[0]=='y')
                cnt++;
      }
      if(cnt>=2)
      {
          printf("composite\n");fflush(stdout);
          return;
      }
      j++;
      if(t==20)
        break;
  }
  printf("prime\n");
  fflush(stdout);
 return;
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
