// METADATA
#include <bits/stdc++.h>
#include <time.h>
using namespace std;



// GLOBAL VARIABLES
int N, K;
vector<int> INP;
chrono::duration<double, milli> timed;
vector<int> ans;



int main()
{
    // INPUT
    while (true)
    {
        cin >> N >> K;
        
        if (N == 0 && K == 0) break;    // EOF

        INP.clear();
        for (int n = 0; n < N; n++)
        {
            int cup; cin >> cup;
            INP.push_back(cup);
        }
        
        
        
        // CLOCK START
        auto start = chrono::steady_clock::now();



        // PROCESS
        int mx = 0;
        for (int c : INP)
        {
            if (K + c > 100) break;
            else
            {
                K += c;
                mx++;
            }
        }
        ans.push_back(mx);
        
        
        
        // CLOCK END
        auto end = chrono::steady_clock::now();
        timed += end - start;
    }



    // OUTPUT
    ofstream out;
    out.open("out.txt");
    out << (timed).count() << "\n";
    for (int i : ans) out << i << "\n";
    out.close();



    return 0;
}