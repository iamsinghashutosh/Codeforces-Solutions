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
// const int MX=5e5+5;
int seg[2000005];
int a[500005],n,res;

void build(int node,int l,int r)
{
    if(l==r)
    {
        seg[node]=a[l];return;
    }
    int mid=(l+r)>>1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    seg[node]=__gcd(seg[node<<1|1],seg[node<<1]);
}


void query(int node,int l,int r,int ql,int qr,int x)
{
    if(ql>qr || l>qr || r<ql || seg[node]%x==0)
        return;
    if(res>1)
        return;
    if(ql<=l && qr>=r && l==r)
    {
        res++;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=ql)
        query(node<<1,l,mid,ql,qr,x);
    if(mid<=qr)
        query(node<<1|1,mid+1,r,ql,qr,x);
}

void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        seg[node]=val;
      return;
    }
    else
    {
        int mid=(l+r)>>1;
        if(mid>=pos)
            update(node<<1,l,mid,pos,val);
        else
            update(node<<1|1,mid+1,r,pos,val);
        seg[node]=__gcd(seg[node<<1|1],seg[node<<1]);
    }
}

void solve()
{
  cin >> n;
  fp(i,1,n)
    cin >> a[i];
  build(1,1,n);
  int q;
  cin >> q;
  while(q--)
  {
      int num;
      cin >> num;
      if(num==1)
      {
          res=0;
          int l,r,x;
          cin >> l >> r >> x;
          query(1,1,n,l,r,x);
          if(res<=1)
            cout << "YES\n";
          else  
            cout << "NO\n";
      }
      else{
          int pos,val;
          cin >> pos >> val;
          update(1,1,n,pos,val);
      }
  }
  return;
} 

signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
