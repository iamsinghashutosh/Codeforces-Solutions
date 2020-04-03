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

int node[4*100005],a[100005];
int marked[4*100005];
void push(int v,int tl,int tr) {
    if (marked[v]) {
        if(tl<tr)
        {
            marked[2*v]=marked[v];
            marked[2*v+1]=marked[v];
        }
        node[v]=marked[v];
        marked[v]=0;
    }
}

void build(int t,int tl,int tr)
{
    if(tr<tl)
        return;
    if(tl==tr)
    {
        node[t]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(2*t,tl,mid);
    build(2*t+1,mid+1,tr);
    node[t]=max(node[2*t],node[2*t+1]);
}

int get(int t,int l,int r,int tl, int tr)
{
    push(t,tl,tr);
    if(tr<tl || l>r || l>tr || r<tl)
        return -1e9;
    if(tl>=l && tr<=r)
            return node[t];
    int mid=(tl+tr)/2;
    return max(get(2*t,l,r,tl,mid),get(2*t+1,l,r,mid+1,tr));
    
}   

void update(int v, int tl, int tr, int l, int r, int new_val) {
    push(v,tl,tr);
    if (r<tl || tr<l) 
        return;
    if (l <= tl && tr <= r) {
        marked[v] = new_val;
        push(v,tl,tr);
        return;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        node[v]=max(node[2*v],node[2*v+1]);
    }
}
void solve()
{
  int n;
  cin >> n;
  f(i,n)
    cin >> a[i];
   build(1,0,n-1);
   int m;
   cin >> m;
   while(m--)
   {
       int w,h;
       cin >> w>> h;
       int maxm=get(1,0,w-1,0,n-1);
       cout << maxm << '\n';
       update(1,0,n-1,0,w-1,maxm+h);
   }
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
