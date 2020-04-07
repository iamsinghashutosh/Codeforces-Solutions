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


void solve()
{ 
  int d,sum;
  cin >> d >> sum;
  vector<pair<int,pair<int,int>>> v;
  f(i,d)
    {
        int x,y;
        cin >> x >> y;
        v.pb({x,{y,i}});
    }
    sort(all(v));
    int max[d+1]={0};
    fp(i,1,d)
        max[i]=max[i-1]+v[i-1].S.F;
    int ans[d],flg=0;
    f(i,d)
    {
        if(flg==0)
           {
            sum-=v[i].F;
            ans[v[i].S.S]=v[i].F;
           }
        else
            sum-=(v[i].S.F);
        if(sum<0)
        {
            cout << "NO\n";return;
        }
        if(flg==1)
        {
            // sum-=v[i].S.F;
            ans[v[i].S.S]=v[i].S.F;continue;
        }
        if((max[d]-max[i+1])<=sum)
        {
            ans[v[i].S.S]=v[i].F + sum-(max[d]-max[i+1]);
            if(ans[v[i].S.S]<v[i].F || ans[v[i].S.S]>v[i].S.F)
            {
                cout << "NO\n";return;
            }
            sum+=v[i].F;
            sum-=ans[v[i].S.S];
            flg=1;
        }
    }
    cout << "YES\n";
    f(i,d)
        cout << ans[i] << " \n"[i==d-1];
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
