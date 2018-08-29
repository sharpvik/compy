# Explanation | #1

Practically any grid can be represented as a **graph**. Knowing this, we can think of any given grid as a graph composed of multiple vertices (squares) some of which are connected (to be connected two squares-vertices must be of the same colour and neighbouring) and others are not.

To count the longest path we can either use **DFS** or **BFS** -- both will do. For me it's easier to deal with DFS, so I used it in my own solution, yet you are free to choose for yourself.

If we skip simple implementation details, this task is pretty easy in my opinion. All we needed to do is implement a recursive DFS function, run this function for every square in a grid (unless already visited), and work out the **maximum** of those calls. To keep track of visited squares I use a grid-sized matrix filled with boolean values where `false` is an unvisited cell and `true` is a visited one.

In pseudocode it looks like this:

```txt
mx = 1;
for cells in grid:
    if cell is not visited:
        cur = dfs(cell)
        if cur > mx: mx = cur
```

Lastly, we need to implement the DFS function itself. My DFS function

1. Receives coordinates of a cell as arguments.
2. Marks cell as visited.
3. Declares a variable that holds the total number of squares there are in the path that starts with the given cell.
4. Checks all 4 neighbouring cells on
    + being inside the grid (coordinates like [-1, 1] are invalid and must not be checked);
    + being visited / unvisited;
    + being the same colour as the current cell;
5. For each cell that meets these criteria, it recursively runs DFS and adds result to the *total*.
6. Returns *total*.

DFS in pseudocode:

```txt
function dfs(h, w):
    visited[h][w] = true

    ttl = 1

    for each neighbouring, unvisited,
        valid cell of the same colour as the current cell:
            ttl = ttl + dfs(neighbour)

    return ttl
```