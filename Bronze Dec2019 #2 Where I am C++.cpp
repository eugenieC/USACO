#include <bits/stdc++.h>
using namespace std;

// determine the location of that sequence along the road
// smallest value of K consecutive mailboxes
int main() {
    freopen("whereiam.in","r",stdin);
    // n mail boxes
    int n;
    cin >> n;

    // mailbox letters
    string p;
    cin >> p;

    int ans=0;

    for (int i=0;i<(n-1);i++) {
        for (int j=(i+1);j<n;j++) {
            // start when ith letter is equal to jth letter
            if (p[i]==p[j]) {
                int left=i;
                int right=j;

                // move left point and right point by one click togther
                int cnt=1;
                int left_point=left;
                int right_point=right+left_point-left;
                while (right_point < n && p[left_point]==p[right_point]) {
                    cnt += 1;
                    left_point+=1;
                    right_point+=1;
                }
                ans = max(ans,cnt);
            }
        }

    }
    cout << ans << endl;
}
