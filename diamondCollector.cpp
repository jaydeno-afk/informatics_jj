#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    vector<int> front(n),back(n);

    // best group from the left
    int l=0;

    for (int r=0;r<n;r++){
        while (a[r]-a[l]>k){
            l++;
        }

        int len=r-l+1;

        if (r==0){
            front[r]=len;
        }else{
            front[r]=max(front[r-1],len);
        }
    }

    // best group from the right
    int r=n-1;

    for (int l=n-1;l>=0;l--){
        while (a[r]-a[l]>k){
            r--;
        }

        int len=r-l+1;

        if (l==n-1){
            back[l]=len;
        }else{
            back[l]=max(back[l+1],len);
        }
    }

    // Combine the two groups
    int ans=0;

    for (int i=0;i<n-1;i++){
        ans=max(ans,front[i]+back[i+1]);
    }

    cout<<ans<<"\n";
}