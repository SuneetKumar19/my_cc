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
#define sz(v) (int)v.size()
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
         a%=mod;
        int res=1;
		while(x>0)
        {
            if(x&1)
            res=res*a%mod;
            a=a*a%mod;
            x>>=1;  
        }
		return res;
}
int max(int a,int b)
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
vector<int>tree[500005];
int a[100005];
int n;

// building the merge sort tree
void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node].pb(a[start]);
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        // tree[node]=merge(tree[2*node],tree[2*node+1]);
        merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
    }
}

// this query returns number of element in a given range greater or equal to k

int query(int node,int start,int end,int l,int r,int k)
{
    if(l>end||r<start)
    {
        return 0;
    }
    else if(r>=end&&l<=start)
    {
        return (tree[node].size()-(lb(all(tree[node]),k)-tree[node].begin()));
    }
    int mid= (start+end)/2;
    int p1=query(2*node,start,mid,l,r,k);
    int p2=query(2*node+1,mid+1,end,l,r,k);
    return p1+p2;
}
// merge sort tree
void single_hi_rahoge_bc()
{
    cin>>n;
    int q;
    cin>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    // while(q--)
    // {
    //     int l,r,x;cin>>l>>r>>x;
    //     cout<<query(1,1,n,l,r,x);el
    // }
    while(q--)
    {
        int an,am;cin>>am>>an;
        int x=query(1,1,n,1,n,am);
        if(x>=an)
        {
            int l=1,r=n,pos=0;
            while(r>=l)
            {
                int mid=l+(r-l)/2;
                int zz=query(1,1,n,1,mid,am);
                // cout<<"->"<<mid<<" "<<zz;el
                if(zz>=an)
                {
                    pos=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            cout<<a[pos];el
        }
        else
        {
            cout<<-1;el
        }
    }
}
signed main()
{
    single_hi_rahoge_bc();
}