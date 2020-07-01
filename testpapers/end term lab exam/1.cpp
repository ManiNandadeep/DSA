#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll LongConsSubseq(ll a[],ll n)
{
    unordered_map<ll,ll>m; //hash map from a[i] to the number of times a[i] occured in the array
    ll ans=0;
    for(ll i=0;i<n;i++) m[a[i]]++;
    for(ll i=0;i<n;i++)
    {
        if(m[a[i]-1]==0) 
        {
            ll j=a[i];
            while (m[j]>0)
            {
                j++;        
            }
            ans=max(ans,j-a[i]);    
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);   //fastio
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,t=1;             //if we have multi test cases;
    while (t--)
    {
        cout<<"Enter the sizeof the array"<<endl;
        cin>>n;//sizeof the array
        ll*a=(ll*)malloc(sizeof(ll)*n);
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<LongConsSubseq(a,n)<<endl;
    }
    return 0;
}