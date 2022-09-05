#include <bits/stdc++.h>
using namespace std;
 
 // change line when each line contain no more than K (1≤K≤80) characters, not counting spaces.
int main(){
    freopen("word.in","r",stdin);
    int n,k;
    // n word and k character cap
    cin >> n >> k;

    string wrd;
    int character_cnt=0;

    for (int i=0;i<n;i++) {
        // read word
        cin >> wrd;
        // if character size of previous words + new word is greater than character cap (k), 
        // then change line and print word. also character_cnt is refreshed with new word size
        // else print word and add new word size to character_cnt
        if ((wrd.size() + character_cnt) > k) {
            cout << endl << wrd << " ";
            character_cnt = wrd.size();
        }
        else {
            cout << wrd << " ";
            character_cnt += wrd.size();
        }
    }
}
