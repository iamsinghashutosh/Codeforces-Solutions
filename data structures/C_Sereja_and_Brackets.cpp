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

int tot[4000005],open[4000005],close[4000005];
string s;

void build(int t,int tl,int tr)
{
    if(tr==tl)
    {
        if(s[tl]=='(')
            open[t]=1;
        else
            close[t]=1;
        return;
    }
    int mid=(tl+tr)/2;
    build(2*t,tl,mid);
    build(2*t +1,mid+1,tr);
    int x=min(open[2*t],close[2*t+1]);
    tot[t]=tot[2*t]+tot[2*t + 1]+2*x;
    open[t]=open[2*t]+open[2*t+1]-x;
    close[t]=close[2*t]+close[2*t+1]-x;
}

pair<int,pair<int,int>> query(int t,int l,int r,int tl,int tr)
{
    pair<int,pair<int,int>> p1,p2,ans;
    if(l>tr || r<tl)
    {
        ans={0,{0,0}};
        return ans;
    }
    if(tl>=l && tr<=r)
       {
           ans={tot[t],{open[t],close[t]}};
            return ans;
       }
    int mid=(tl+tr)/2;
    p1=query(2*t,l,r,tl,mid);
    p2=query(2*t+1,l,r,mid+1,tr);
    int x=min(p1.S.F,p2.S.S);
    ans.F=p1.F + p2.F + 2*x;
    ans.S.F=p1.S.F + p2.S.F -x;
    ans.S.S=p1.S.S + p2.S.S -x;
    return ans;
}

void solve()
{
  cin >> s;
  build(1,0,s.length()-1);
  int q;
  cin >> q;
  while(q--)
  {
      int l,r;
      cin >> l >> r;
      l--,r--;
      cout << query(1,l,r,0,s.length()-1).F << '\n';

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
