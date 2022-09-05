#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("swap.in","r",stdin);
    int n,k;
    cin >> n >> k;

    // use array to find out the iteration time when cow is same to original order after iteration
    array<int, 100> cow;
    array<int, 100> sorted;

    for (int i=0;i<n;i++) {
        cow[i]=(i+1);
        sorted[i]=(i+1);
    }

    int ab[2][2]; 
    for (int i=0;i<2;i++) {
        cin >> ab[i][0] >> ab[i][1];
        ab[i][0]--;ab[i][1]--;
    }

    int original_order=k;

    for (int iter=1;iter<=k;iter++) {
        for (int i=0;i<2;i++) {
            
            int left=min( ab[i][0],ab[i][1]);
            int right=max( ab[i][0],ab[i][1]);

            while (left < right) {
                int tmp = cow[left];
                cow[left] = cow[right];
                cow[right] = tmp;
                left++;
                right--;
            }

        }
        // if the swap set is same to original order, the just run remainder time
        if (cow==sorted) {
            //cout << "back to original order after: " << iter <<  " iteration" << endl;
            iter= k - (k % iter) ;
            //cout << "move to iteration number of remainder -1 :" << iter << endl; // because 1 is added in the loop start line
            }
    }

    // final result
    for (int z=0;z<n;z++) cout << cow[z] << endl;
}
