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
 string s;
 cin >> s;
 int pos1=0;
 f(i,s.length())
 {
     if(s[i]=='@')
     {
         pos1=i;break;
     }
 }
 if(pos1==0)
 {
     cout << "No solution\n";return;
 }
 int pos2;
 fr(i,s.length()-1,0)
 {
     if(s[i]=='@')
     {
         pos2=i;break;
     }
 }
 if(pos2==(int)s.length()-1)
 {
     cout << "No solution\n";return;
 }
 vector<string> res;
    string str;

 f(i,s.length())
 {
     if(i>0 && s[i-1]=='@')
     {
         str+=s[i];
         res.pb(str);
         str="";continue;
     }
     str+=s[i];
 }
 if(str!="")
    res[res.size()-1]+=str;
 int flg=1;
 f(i,res.size())
 {
     string x=res[i];
     if(x[0]=='@' || x[x.length()-1]=='@')
     {
         flg=0;break;
     }
 }
 if(flg)
 {
     f(i,res.size())
       {
           if(i!=res.size()-1)
                cout << res[i] <<',' ;
            else
                cout << res[i];
       }
     cout << '\n';
 }
 else
 {
     cout << "No solution\n"; 
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