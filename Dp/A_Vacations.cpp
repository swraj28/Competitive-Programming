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

int dp[105][3];
int min_rest(int arr[],int n,int si,int act_d){
    if(si==n){
        return 0;
    }
    if(dp[si][act_d]!=-1){
        return dp[si][act_d];
    }
    if(arr[si]==0){//rest
        dp[si][act_d]=1+min_rest(arr,n,si+1,0);
    }else if(arr[si]==1){ //contest happening
        if(act_d==1){
            dp[si][act_d]=1+min_rest(arr,n,si+1,0);
        }else{
            dp[si][act_d]=min_rest(arr,n,si+1,1);
        }    
    }else if(arr[si]==2){//gym
        if(act_d==2){
            dp[si][act_d] = 1 + min_rest(arr, n, si + 1, 0);
        }else{
            dp[si][act_d] = min_rest(arr, n, si + 1, 2);
        }
    }else{//contest or gym
        int a=(act_d==1)?INT_MAX:min_rest(arr,n,si+1,1);
        int b=(act_d==2)?INT_MAX:min_rest(arr,n,si+1,2);

        dp[si][act_d]=min(a,b);
    }
    return dp[si][act_d];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    mk(arr,n,int);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<min_rest(arr,n,0,0);

    return 0;
}