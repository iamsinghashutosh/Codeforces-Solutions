#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,c=0,f=1,j;
        char a;
        cin>>n>>a;
        string s;
        cin>>s;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            if(s[i]!=a)
            f=0;
        }
        if(!f)
        {
            for(i=1;i<=n;i++)
            {    f=1;
                for(j=i;j<=n;j+=i)
                f&=(s[j-1]==a);
                
            if(f)
            {
              v.push_back(i);
              break;
            }
            }
        }
        if(!f)
        {
            v.push_back(n);
            v.push_back(n-1);

        }
        cout<<v.size()<<"\n";
        if(v.size()>0)
        {
        for(auto&i:v)
        cout<<i<<" ";
        cout<<"\n";
        }
        

    }

}