
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b;
    cin>>n>>a>>b;

    vector<long long> pref(n+1,0);
    for (int i=1;i<=n;i++){
        long long x;
        cin>>x;
        pref[i]=pref[i-1]+x;
    }

    deque<int> dq;
    long long ans=LLONG_MIN;

    for (int r=a;r<=n;r++){
        int l=r-a;

        while (!dq.empty() && pref[dq.back()]>=pref[l]){
            dq.pop_back();
        }
        dq.push_back(l);

        while (!dq.empty() && dq.front()<r-b){
            dq.pop_front();
        }

        ans=max(ans,pref[r]-pref[dq.front()]);
    }

    cout<<ans<<'\n';
    return 0;
}
