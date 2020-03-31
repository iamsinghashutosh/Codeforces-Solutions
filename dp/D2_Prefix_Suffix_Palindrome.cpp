/*
  Ashutosh Singh
  Problem Link:-https://codeforces.com/contest/1326/problem/D2
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
#define all(b) b.begin(),b.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int isPalindrome(string s)
{
    int n=s.length();
    int pf[n];
    pf[0]=0;
    fp(i,1,n-1)
    {
        int j=pf[i-1];
        while(j>0 && s[i]!=s[j])
          j=pf[j-1];
        if(s[i]==s[j])
            j++;
        pf[i]=j;
    }
    return pf[n-1];
} 
 
void solve()
{
  string s;
  cin >> s;
  int n=s.length();
  int pos1=0,pos2;
  if(n==1)
   {
       cout << s << '\n';return;
   }
  for(int i=0,j=n-1;i<n,j>i;i++,j--)
  {
      if(s[i]==s[j])
        pos1++;
      else
       break;
  } 
  pos2=n-pos1-1;
  string a=s.substr(pos1,n-(2*pos1));
  string b;
  b=a;
  reverse(all(b));
  string x=a+"#"+b;
  string y=b+"#"+a;
  int l1=isPalindrome(x);
  int l2=isPalindrome(y);
  string w;
  if(l1>l2)
    w=a.substr(0,l1); 
  else
    w=b.substr(0,l2);
//   cout << w ;
  cout << s.substr(0,pos1)+w+s.substr(pos2+1,pos1) << '\n';
  return ;
}

signed main()
{
   FAST;
	int T=1;
	cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
