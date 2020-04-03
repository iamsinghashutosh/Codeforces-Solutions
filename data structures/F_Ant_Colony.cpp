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

int t1[4*100001],a[100005];
pair<int,int> t2[4*100001];

pair<int,int> combine(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.F>p2.F)
        return p2;
    if(p2.F>p1.F)
        return p1;
    return {p1.F,p1.S+p2.S};
}

void build(int t,int tl,int tr)
{
    if(tl==tr)
    {
        t1[t]=a[tl];
        t2[t]={a[tl],1};
        return;
    }
    int mid=(tl+tr)/2;
    build(2*t,tl,mid);
    build(2*t+1,mid+1,tr);
    t1[t]=__gcd(t1[2*t],t1[2*t+1]);
    t2[t]=combine(t2[2*t],t2[2*t+1]);
}

int getGCD(int t,int l,int r,int tl,int tr)
{
    if(l>r ||l>tr || r<tl )
        return 0;
    if(l<=tl && r>=tr)
        return t1[t];
    int mid=(tl+tr)/2;
    int x1=getGCD(2*t,l,r,tl,mid);
    int x2=getGCD(2*t+1,l,r,mid+1,tr);
    return __gcd(x1,x2);
}

pair<int,int> getMin(int t,int l,int r,int tl,int tr)
{
    if(l>r ||l>tr || r<tl )
        return {INT_MAX,0};
    if(l<=tl && r>=tr)
        return t2[t];
    int mid=(tl+tr)/2;
    pair<int,int> x1=getMin(2*t,l,r,tl,mid);
    pair<int,int> x2=getMin(2*t+1,l,r,mid+1,tr);
    return combine(x1,x2);
}

void solve()
{
  int n;
  cin >> n;
  f(i,n)
    cin >> a[i];
  build(1,0,n-1);
  int q;
  cin >> q;
  while(q--)
  {
      int l,r;
      cin >> l >> r;
      l--,r--;
      int x=getGCD(1,l,r,0,n-1);
    //   cout << x << '\n';

      pair<int,int> y=getMin(1,l,r,0,n-1);
    //   cout << y.F << " " << y.S << '\n';
      if(x==y.F)
        cout << r-l+1-y.S << '\n';
      else
       cout << r-l+1 << '\n';
  }
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
