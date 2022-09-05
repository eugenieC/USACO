#include <bits/stdc++.h>
#include <charconv>
using namespace std;

// constraint: cow X must appear in the milking order either directly after cow Y or directly before cow Y.
// find  an ordering of cows, one cow per line, satisfying all constraints.

// 8 cows name
string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, int> cind;

int main() {
    // sort the cow names
    sort(cows, cows+8);
    for (int i=0;i<8;i++) {
        // map the order number to cows
        cind[cows[i]] = i;
    }

    freopen("lineup.in","r",stdin);
    int n;
    cin >> n;

    string eight="12345678";
    string strin,left_cow[n],right_cow[n];

    // read sentence. e.g "Buttercup must be milked beside Bella"
    // keep the indicators (as character) of left cows and right cows
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            cin >> strin;
            if(j==0) left_cow[i]=to_string(cind[strin]+1);
            else if (j==5) right_cow[i]=to_string(cind[strin]+1);
        }
    }

    int met_condition_cnt=0;  
    string out_s;
    // check all permutation cases
    do {
        met_condition_cnt=0;
        for(int i=0;i<n;i++) {
            char l=left_cow[i][0],r=right_cow[i][0];
            int match=0,z=0;
            // check if two cows are located side by side
            while(z<7 && match==0) {
                if ((l==eight[z] && r==eight[z+1]) || ((l==eight[z+1] && r==eight[z]))) {
                    match=1;
                }
                else z++;
            }
            met_condition_cnt += match;
        } 
        out_s=eight;  // assign the permutation case (eight) to out_s     
        if (met_condition_cnt==n) break;
    } while (next_permutation(eight.begin(), eight.end()));

    for(int i=0;i<8;i++) {
        int x=out_s[i]-49;  // character number to numeric number using ascii code (acii code 49 = character 1)
        cout << cows[x] << endl;
    }
    
}
