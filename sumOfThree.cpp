#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,z;
    int target;
    cin>>n>>target;
    unordered_map<int,int> check;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin>>z;
        v[i]=z;
        check[z]=i;
    }
    vector<int> index;
    bool found=false;
    for (int i=0;i<n;i++){
        if (!found){
        for (int j=i+1;j<n;j++){
            int search=target-v[i]-v[j];
            if (check.count(search)){
                if (check[search]!=i && check[search]!=j){
                    index.push_back(i);
                    index.push_back(j);
                    index.push_back(check[search]);
                    found=true;
                    break;

                }
            }
        }
    }else{
        break;
    }
    }
    if (index.empty()){
        cout<<"IMPOSSIBLE";

    }else{
        for (int i:index){
            cout<<i+1<<' ';
        }
    }
}
