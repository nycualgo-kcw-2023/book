#include <iostream>
using namespace std;
int main()
{
    long long n, m, k, ans = 0;
    cin >> n >> m >> k;

    if (n > m) swap(n, m);

    for (int i = 1; i <= n; i++){
        ans += min(m, k / i) - max(1LL, (m + 1 - (m * n - k + 1) / (n - i + 1))) + 1;
    }
    cout << ans << '\n';
    return 0;
}
