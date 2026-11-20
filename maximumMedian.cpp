
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mid = n / 2;

    for (int i = mid; i < n - 1; i++) {
        long long diff = a[i + 1] - a[i];
        long long count = i - mid + 1;
        long long cost = diff * count;

        if (cost <= k) {
            k -= cost;
        } else {
            cout << a[i] + k / count << '\n';
            return 0;
        }
    }

    cout << a[n - 1] + k / (n - mid) << '\n';

    return 0;
}
