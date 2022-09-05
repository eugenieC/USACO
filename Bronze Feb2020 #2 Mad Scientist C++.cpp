#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in","r",stdin);
    int n;
    cin >> n;
    char a[n],b[n];

    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    int ans=0;

    for (int i=1;i<n;i++) {
        if (a[i-1]!=b[i-1] && a[i]==b[i]) ans++;
        else if (a[i-1]!=b[i-1] && i==n) ans++;
    }

    cout << ans << endl;
}
