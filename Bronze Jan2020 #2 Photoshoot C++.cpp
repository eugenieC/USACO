#include <bits/stdc++.h>
using namespace std;
 
// given b_i = a_i + a_(i+1), find a 

int main(){
    freopen("photo.in","r",stdin);
    int n;
    cin >> n;

    int b[n],a[n];

    // read b array
    for(int i=0;i<(n-1);i++) {
        cin >> b[i];
    }

    // simulate possible a_i combination and check if each number appears once
    int appear[n],total;
    int i=1;

    // iteration while i <=n and all n donot appear
    while(i<=n && total < n) {
        // initialize with zero
        for (int u=0;u<n;u++) {appear[u]=0;a[u]=0;}
        // seed value from i, used flag, total used
        a[0]=i;appear[i-1]=1;total=0;

        for (int j=1;j<n;j++) {
            // calculate a_j = b_(j-1) - a_(j-1)
            a[j] = b[j-1] - a[j-1];
            // if calculated a[j] is zero or below, then stop for iteration
            if (a[j] < 1) break;
            // used flag
            appear[a[j]-1]=1;
        }
        // calculate total appear. if total number of appear is 
        for (int u=0;u<n;u++) {total += appear[u];}
        i++;
    }

    for(int k=0;k<n;k++) cout << a[k] << " "; 
}
