#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> freq(1000001,0);

    int l=0,distinct=0;
    int best=0;
    int ansl=0,ansr=0;

    for (int r=0;r<n;r++){

        if (freq[a[r]]==0){
            distinct++;
        }
        freq[a[r]]++;

        while (distinct>k){
            freq[a[l]]--;

            if (freq[a[l]]==0){
                distinct--;
            }

            l++;
        }

        int len=r-l+1;

        if (len>best){
            best=len;
            ansl=l;
            ansr=r;
        }
    }

    cout<<ansl+1<<" "<<ansr+1<<"\n";
}