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
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int a[200005],b[200005],c[200005];
vector<int> v[200005]; 
int ans=0;

pii dfs(int x,int pa,int minm)
{
    minm=min(minm,a[x]);
    pii cnt={0,0};
    if(b[x]-c[x])
     if(b[x]>c[x])
        cnt.F++;
     else
        cnt.S++;
    for(auto u:v[x])
    {
        if(u!=pa)
        {
            pii pr=dfs(u,x,minm);
            cnt.F+=pr.F;
            cnt.S+=pr.S;
        }
    }
    int val=min(cnt.F,cnt.S);
    ans+=2*val*minm;
    cnt.F-=val;
    cnt.S-=val;
    return cnt;
}

void solve()
{
  int n;
  cin >> n ;
  fp(i,1,n)
  {
      cin >> a[i] >> b[i] >> c[i];
  }
  f(i,n-1)
  {
      int x,y;
      cin >> x>>y;
      v[x].pb(y);
      v[y].pb(x);
  }
  pii pr=dfs(1,-1,mod);
  if(pr.F!=0 || pr.S!=0)
    cout << "-1\n";
  else
    cout << ans << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
