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

void solve()
{ 
  int n;
  cin >> n;
  int p[n+1],pos[n+1];
  fp(i,1,n)
    {cin >> p[i];pos[p[i]]=i;}
  int cnt[n+1];
  fp(i,0,n)
    cnt[i]=1;
   int maxm=1;
   if(pos[1]!=n)
    {
        cnt[pos[1]+1]+=cnt[pos[1]];
        maxm=2;
    }
        cnt[pos[1]]=-1;

    fp(i,2,n)
    {
        if(cnt[pos[i]]==maxm)
        {
           if(pos[i]!=n && cnt[pos[i]+1]!=-1)
            {
              
                cnt[pos[i]+1]+=cnt[pos[i]];
                cnt[pos[i]]=-1;
                maxm= cnt[pos[i]+1];
            }
            else
            {
                cnt[pos[i]]=-1;
                maxm=1;
            } 
        }
        else
        {
            cout << "No\n";return;
        }
    }
    cout << "Yes\n";
  return;
}

signed main()
{
  FAST
  int T=1;
   cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
