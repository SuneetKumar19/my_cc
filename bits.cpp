#include <bits/stdc++.h>
using namespace std;
#define int  long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define gcd __gcd
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define all(i) i.begin(),i.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define set_bit __builtin_popcount //gives number of set_bits
#define ff first
#define ss second
#define cases(t) int t;cin>>t; rep(casn,1,t+1)
#define el cout<<"\n";
#define deci(n) int n; scanf("%lld",&n);
#define decs(n) string n; cin>>n;
#define sz(v) v.size()
#define repit(m) for(auto it=m.begin();it!=m.end();it++)
#define cYES cout<<"YES\n";
#define cNO cout<<"NO\n";
#define ins insert
#define INF 1000000000000000000
#define NP 50000
//  cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
 
//  IIITA
//SUNEET KUMAR -->  ਸੁਨੀਤ 
 int power(int a,int x)
 {
        int res=1;
		while(x>0)
        {
            if(x&1)
            res=res*a;
            a=a*a;
            x>>=1;  
        }
		return res;
}
int mai(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}
int madd(int a,int b)
{
    int ans;
    ans=(a%mod+b%mod)%mod;
    return ans;
}
int mmult(int a,int b)
{
    int ans=1;
    ans=((a%mod)*(b%mod))%mod;
    return ans%mod;
}
int modinverse(int a)
{
    return power(a,mod-2);
}

int a[39];
// function to get count of each bit i.e the number of times it was set for all numbers from 1 to n
void corona(int n)
{
    while(n)
    {
        int k=log2(n);
        k=pow(2,k);
        n=n-k; 
        int i=0; // ith bit
        int val=k/2;
        // ex: if k=4, add val=4/2=2 to every ith bit having 2^i<4. 
        while(k>1)
        {
        a[i]+=val;
        i++;
        k=k/2;
        }
        a[i]+=(n+1);
    }
}
signed main()
{
       cases(t)
       {
           int n;
           cin>>n;
           for(int i=0;i<=37;i++)
           {
               a[i]=0;
           }

           int x=n;
           corona(n);
           int ans=0;
           for(int i=0;i<=35;i++)
           {
               int p=(int )pow(2,i);
               ans+=madd( mmult(mmult(p,n),a[i]), mmult((x-a[i]),mmult(p,a[i])));
            //    ans+=((((a[i])*((int)pow(2,i)*x)%mod)%mod+((x-a[i])*(a[i]*(int)pow(2,i))%mod)%mod)%mod);
               ans=ans%mod;
           }
           cout<<ans;el
       }
}

