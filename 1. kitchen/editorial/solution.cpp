// METADATA
#include <bits/stdc++.h>
#include <time.h>
using namespace std;



// GLOBAL VARIABLES
int H, W;
vector< vector<bool> > grid;        // # = true, . = false
vector< vector<bool> > visited;
chrono::duration<double, milli> timed;
vector<int> ans;



// FUNCTIONS
void displayGrid()
{
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cout << grid[h][w] << " ";
        }
        cout << "\n";
    }
}

void clearGrid()
{
    grid.clear();
    visited.clear();
    for (int h = 0; h < H; h++)
    {
        vector<bool> line;
        for (int w = 0; w < W; w++)
            line.push_back(false);
        grid.push_back(line);
        visited.push_back(line);
    }
}

int dfs(int h, int w)
{
    visited[h][w] = true;

    int ttl = 1;

    // check all 4 neighbours for 
    // 1. being inside the grid (you don't want to surpass the border)
    // 2. being not visited yet
    // 3. being the same colour as the current square
    if (h - 1 > -1 && !visited[h - 1][w] && grid[h][w] == grid[h - 1][w])   // top
        ttl += dfs(h - 1, w);
    if (w + 1 < W  && !visited[h][w + 1] && grid[h][w] == grid[h][w + 1])   // right
        ttl += dfs(h, w + 1);
    if (h + 1 < H  && !visited[h + 1][w] && grid[h][w] == grid[h + 1][w])   // bottom
        ttl += dfs(h + 1, w);
    if (w - 1 > -1 && !visited[h][w - 1] && grid[h][w] == grid[h][w - 1])   // left
        ttl += dfs(h, w - 1);

    return ttl;
}



int main()
{
    // INPUT
    while (true)
    {
        cin >> H >> W;
        
        if (H == 0 && W == 0) break;    // EOF

        clearGrid();
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                char c; cin >> c;
                grid[h][w] = (c == '#');
            }
        }
        
        
        
        // CLOCK START
        auto start = chrono::steady_clock::now();



        // PROCESS
        int mx = 1;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!visited[i][j])
                {
                    mx = max( mx, dfs(i, j) );
                }
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