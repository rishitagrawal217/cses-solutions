//dp[i][v] = number of ways to fill upto i-th index with value v, transition from v, v-1, v+1 previous row se hota hai. Base case pehle row initialize karo. Last row ka sum = answer
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    
 
    if (a[0] == 0) {
        for (int v = 1; v <= m; ++v) dp[0][v] = 1;
    } else {
        dp[0][a[0]] = 1;
    }
 
    for(int i=1;i<n;i++){
        int el=a[i];
        if(el!=0){
            int ok1=0, ok2=0, ok3=0;
            if(a[i]-1 >= 1){
                ok1=dp[i-1][a[i]-1];
            }
            ok2=dp[i-1][a[i]];
            if(a[i]+1 <= m){
                ok3=dp[i-1][a[i]+1];
            }
            dp[i][a[i]]=( (ok1+ok2)%mod + ok3 )%mod;
        }else{
            for(int j=1;j<=m;j++){
                int ok1=0, ok2=0, ok3=0;
                if(j-1 >= 1){
                    ok1=dp[i-1][j-1];
                }
                ok2=dp[i-1][j];
                if(j+1 <= m){
                    ok3=dp[i-1][j+1];
                }
                dp[i][j]=( (ok1+ok2)%mod + ok3 )%mod;
            }
        }
    }
 
    int ans=0;
    for(int j=1;j<=m;j++) ans=(ans+dp[n-1][j])%mod;
    cout<<ans<<endl;
}
