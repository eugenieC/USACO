#include <bits/stdc++.h>
using namespace std;
 
int main(){
    freopen("race.in","r",stdin);
    int k,n;
    cin >> k >> n;

    int value[n];

    for(int i=0;i<n;i++) {
        cin >> value[i];

        int min_speed=value[i];
        int left_travel =0,right_travel = 0,time_used =0, current_speed=1;

        while ((left_travel + right_travel) < k) {
            left_travel += current_speed;
            time_used++;
            if ( (left_travel + right_travel) < k && (current_speed >= min_speed)) {
                right_travel += current_speed;
                time_used++;
            }
            // cout << "value:" <<  value[i] << " current speed:" << current_speed << " left travel:" << left_travel << " right travel:" << right_travel << " timeused:" << time_used << endl;
            current_speed++;
        }
    cout << time_used << endl;
    }
}
