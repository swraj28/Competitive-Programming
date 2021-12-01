#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
const int mod = 1000000007;
#define fo1(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];

int dp[200000][2];

int ok(int arr[],int n,int si,int cnt){
    if(si>=n){
        return 0;
    }
    if(dp[si][cnt]!=-1){
        return dp[si][cnt];
    }
    int a1=INT_MAX,a2=INT_MAX;
    if(cnt==1){
        cnt=0;
        a1=ok(arr,n,si+1,cnt);
        a2 =ok(arr, n, si + 2, cnt);
    }else{
        cnt=1;
        if(si<n){
        a1=arr[si]+ok(arr,n,si+1,cnt);
        }
        if(si+1<n){
            a2=arr[si]+arr[si+1]+ok(arr,n,si+2,cnt);
        }
    }
    if(cnt==1){//revert the cnt
        cnt=0;
    }else{
        cnt=1;
    }
    dp[si][cnt]=min(a1,a2);
    return min(a1,a2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        mk(arr,n,int);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<ok(arr,n,0,0)<<endl;
    }

    return 0;
}