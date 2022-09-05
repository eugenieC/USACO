#include <bits/stdc++.h>
using namespace std;

// compute the total number of consistent pairs
int main() {
    freopen("gymnastics.in","r",stdin);
    // read n cows and k practices
    int n,k;
    cin >> n >> k;
    // read n X k array
    int e[n][k];
    for (int i=0;i<n;i++) {
        for (int j=0;j<k;j++) {
            cin >> e[i][j];
        }
    }

    // calculate the number of consistent pairs
    int pair_left_location,pair_right_location;
    int ans=0;

    // get the all possible pairs of the first line from iteration i and j
    for (int i=0;i<k;i++) {
        for (int j=(i+1);j<k;j++) {
            // pair of the first line
            int cnt=0;
            int left_firstline = e[0][i];
            int right_firstline = e[0][j];

            // get the locations of first line pair
            for (int z=1;z<n;z++) {
                for (int w=0;w<k;w++) {
                    // find the location of left and right in zth row
                    if (e[z][w]==left_firstline) pair_left_location=w;
                    if (e[z][w]==right_firstline) pair_left_location=w;
                }
                // check if pair is in order in zth line
                if (pair_left_location < pair_right_location) cnt +=1;
            }
            if (cnt==(n-1)) ans+=1;
        }
    }
    cout << ans << endl;
}
