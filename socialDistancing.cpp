
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);

    int n,m;
    cin>>n>>m;

    vector<pair<long long,long long>> v(m);

    for (int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end());

    auto check = [&](long long d){
        long long count=1;
        long long last=v[0].first;

        for (int i=0;i<m;i++){
            long long start=max(v[i].first,last+d);

            if (start>v[i].second){
                continue;
            }

            long long add=1+(v[i].second-start)/d;
            count+=add;
            last=start+(add-1)*d;

            if (count>=n){
                return true;
            }
        }

        return false;
    };

    long long l=1,r=v[m-1].second-v[0].first;
    long long ans=0;

    while (l<=r){
        long long mid=l+(r-l)/2;

        if (check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    cout<<ans<<'\n';
    return 0;
}
