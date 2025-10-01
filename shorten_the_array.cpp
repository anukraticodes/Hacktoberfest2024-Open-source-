#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

void helper(ll n, ll k, vector<ll>& arr) {
    if (k == 0) {
        cout << 1 << endl;
        return;
    }

    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ll curMax = 0;
        for (ll j = i + 1; j < n && j < i + 65; j++) {
            for (ll p = i; p < j; p++) {
                curMax = max(curMax, arr[p] ^ arr[j]);
            }
            if (curMax >= k) {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

void wushangclan() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    helper(n, k, arr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        wushangclan();
    }
    return 0;
}