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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnto=0,cnt1=0,flg=1;
    if(n==1)
    {
      if(s=="0")
        cout << "No\n";
      else
        cout << "Yes\n";
        return;
    }
    f(i,n)
    {
        if(s[i]=='0')
            {
              if(i==0)
                flg=0;
                if(cnt1>=2)
                {cout << "No\n";return;}
                cnt1=0;
                cnto++;
            }
        else
        {
            if(flg==1 && cnto>=3)
                {cout << "No\n";return;}
            if(flg==0 && cnto>=2)
              {cout << "No\n";return;}
            if(flg==0)
              flg=1;
            cnto=0;
            cnt1++;
        }
    }
     if(cnt1>=2 || cnto>=2)
                {cout << "No\n";return;}
            cout<<"Yes\n";
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
