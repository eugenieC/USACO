#include <bits/stdc++.h>
using namespace std;
 
using pi = pair<int,int>;
#define f first
#define s second

// prefix sum
int pfixs[2501][2501] ={0};

//sort second element of pair
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main() {
    int N;
    vector<pi> cows;
    cin >> N; cows.resize(N); 
	for (pi& cow: cows) cin >> cow.f >> cow.s;

    // compressed the matrix    
    // Using sort() function to sort by 2nd element of pair 
    sort(begin(cows), end(cows), sortbysec); 

    for (int i=0;i<N; ++i)
        cows[i].s=i;

    //print cows to check sorting result
    // for (int i=0;i<N; ++i) 
    //     cout << cows[i].f << " " << cows[i].s << "\n";


    // compress the number by order index
    sort(begin(cows),end(cows));
    for (int i=0;i<N; ++i)
        cows[i].f=i;

    //print cows to check sorting result
    // for (int i=0;i<N; ++i) 
    //     cout << cows[i].f << " " << cows[i].s << "\n";

  

    // prefix sum: first row
    for (int j=0;j<N;j++) pfixs[0][j] = (cows[0].s<=j?1:0);
    // prefix sum: second to last row
    for (int i=1;i<N;i++) {
        for (int j=0;j<N;j++) {
            pfixs[i][j] += pfixs[i-1][j] + (cows[i].s<=j?1:0);
            // cout << "i:"<< i << " j:" << j <<" prefix:" << ((cows[i].s==j)?1:0) << "\n";
        }
    }

    // print prefix sum
    // for (int i=0;i<N;i++) 
    //     {
    //     cout << "\n";    
    //     for (int j=0;j<N;j++)
    //         cout << " "<< pfixs[i][j];
    //     }
    // cout << "\n";  

    long long ans = N + 1;  //Note that the empty subset (+1 in right hand side) should be counted as one of these.

    int bl,bb,tl,tt;
    // a to b
    for (int a=0;a<N;a++)
        for (int b=a+1;b<N;b++) {
            long pf_a = pfixs[a][cows[a].s];
            long pf_b = pfixs[b][cows[b].s];

            int ymax = max(cows[a].s,cows[b].s);
            int ymin = min(cows[a].s,cows[b].s);
            int xmin = cows[a].f;
            int xmax = cows[b].f;

            // tl  tt  tr
            // ll  a*b rr
            // bl  bb  br
            if (ymin==0) {
                 bl = 0; bb=0;
            }
            else {
                 bl = (xmin==0?0:pfixs[xmin-1][ymin-1]);
                 bb = pfixs[xmax][ymin-1] - bl ;
            };

            if (ymax==(N-1)) {
                 tl = 0; tt=0;
            }
            else {
                 tl = (xmin==0?0: (pfixs[xmin-1][N-1]) - (pfixs[xmin-1][ymax]));
                 tt = pfixs[xmax][N-1] - pfixs[xmax][ymax] - tl;
            };

            ans += (tt + bb + (tt*bb) +1);
            // cout << "a:" << a << " b:"<<b<<" top:" << tt << " bottom:" << bb << " ans:"<< ans << "\n";
    }
        
    cout << ans <<"\n";
}
