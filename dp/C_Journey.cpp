/*
 Author:-Ashutosh Singh
 Problem Link:-https://codeforces.com/problemset/problem/839/C
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

vector<int> v[100005];

double dfs(int x,int p)
{
    double sum=0;
    for(auto i:v[x])
    {
        if(i!=p)
            sum+=dfs(i,x)+1;
    }
    if(sum==0)
        return sum;
    else
     return sum/(v[x].size()-(p!=-1));
}

void solve()
{
    int n;
    cin >> n;
    f(i,n-1)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cout << fixed << setprecision(15) << dfs(1,-1) << '\n';
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
