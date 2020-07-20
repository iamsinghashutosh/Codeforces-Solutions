#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

/*---------------------------------------------------------------------------------------------------*/

int res=mod;
int n,k,p;
int a[2005];
int b[2005];

bool chk(int mid)
{
  int j=0;
  f(i,n)
  {
    if(j>=k)
      return false;
    int dis=0;
    while(1)
    { 
      if(j>=k)
      return false;
     if(b[j]>=a[i] && b[j]<=p || (b[j]<=a[i] && b[j]>=p))
      dis=abs(p-a[i]);
     else
      dis=abs(a[i]-b[j])+abs(b[j]-p);
      if(dis<=mid)
        break;
      j++;
    }
    j++;
  }
  return true;
}

void solve()
{
 cin >> n >> k >> p;
 f(i,n)
  cin >> a[i];
 sort(a,a+n);
 f(i,k)
  cin >> b[i];
 sort(b,b+k);
 int l=0,h=1e18;
 while(h-l>1)
 {
   int mid=(l+h)/2;
   if(chk(mid))
     h=mid;
   else
     l=mid;
 }
 if(chk(0))
  h=0;
 cout << h << '\n';
 return;
} 

signed main()
{
  // freopen("leapfrog_ch__input.txt","r",stdin);
  // freopen("fb1.txt","w",stdout);
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
