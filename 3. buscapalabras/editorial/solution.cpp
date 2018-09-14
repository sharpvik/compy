// METADATA
#include <bits/stdc++.h>
#include <time.h>
using namespace std;



// DECLARATIONS
struct Node 
{
	int id;
	char letter;
	vector<Node> children;
	bool isend;
};



// GLOBAL VARIABLES
int N, H, W;
vector< vector<char> > grid; 
vector<string> words;
chrono::duration<double, milli> timed;
vector<Node> tree;
vector<int> ans;			    // number of words found for every test case
vector< set<string> > sans;		// words found for each test case



// FUNCTIONS
void displayGrid()
{
	for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
            cout << grid[h][w] << " ";
        cout << "\n";
    }
}

void clearGrid()
{
    grid.clear();
    for (int h = 0; h < H; h++)
    {
        vector<char> line;
        for (int w = 0; w < W; w++)
            line.push_back('A');
        grid.push_back(line);
    }
}

int child(char letter, vector< vector<Node> > &tree, int pos)
{
	for (Node n : tree[pos])
		if (n.letter == letter) return n.id;
	return 0;
}

bool ender(char letter, vector< vector<Node> > &tree, int pos)
{
	for (Node n : tree[pos])
		if (n.letter == letter && n.isend) return true;
	return false;
}

vector< vector<Node> > createTree()
{
	vector< vector<Node> > tree;
	vector<Node> root;
	tree.push_back(root);
	
	for (string word : words)
	{
		int pos = 0;
		//cout << "word is " << word << endl; //
		for ( auto it = word.begin(); it != word.end() - 1; it++ )	// for every letter except last one
		{
			char letter = *it;
			//cout << "\tletter " << letter << " "; //
			// if letter is child of tree[pos] --> change pos to child()
			int id = child(letter, tree, pos);
			//cout << "\tid = " << id << endl; //
			if (id) pos = id;
			// else --> create new path for the rest of the word
			else
			{
				//cout << "\tnot a child --> creating new node at id " << tree.size() << endl; //
				Node n = {
					.id = tree.size(),
					.letter = letter,
					.children = {},
					.isend = false
				};
				tree[pos].push_back(n);
				tree.push_back(root);
				pos = n.id;
				//cout << "\tnext pos is " << pos << endl; //
			}
		}
		char last = word.back();
		Node n = {
			.id = tree.size(),
			.letter = last,
			.children = {},
			.isend = true
		};
		tree[pos].push_back(n);
	}

	return tree;
}

vector<string> check(int h, int w, vector< vector<Node> > &tree)
{
	vector<string> out;

	// find words starting at this square
	int pos = 0;
	string word;
	int inw = w;
	int inh = h;
		// horizontally
	while (true)
	{
		char letter = grid[h][w];
		int np = child(letter, tree, pos);		
		if ( ender(letter, tree, pos) )			// if this letter is the last one in a word
												// push it into {out}, reset parameters, break while()
		{
			cout << "Letter " << letter << " is ender of " << word << endl;
			word += letter;
			out.push_back(word);
			word = "";
			pos = 0;
			w = inw;
		}
		if (np)									        // if this letter is included into a word
														// update parameters and continue
		{
			cout << "continue... " << letter << endl;
			pos = np;
			word += letter;
			if (w + 1 < W) w++;
			else 
			{
				word = "";
				pos = 0;
				w = inw;
				break;
			}
		}
		else											// if this letter is not present in the tree
														// reset parameters, break the while loop, do not push anything
		{
			cout << "Letter " << letter << " is not present in the tree. BREAK" << endl;
			word = "";
			pos = 0;
			w = inw;
			break;
		}
	}

		// vertically
	while (true)
	{
		char letter = grid[h][w];
		int np = child(letter, tree, pos);		
		if ( ender(letter, tree, pos) )			// if this letter is the last one in a word
												// push it into {out}, break while()
		{
			cout << "Letter " << letter << " is ender of " << word << endl;
			word += letter;
			out.push_back(word);
			word = "";
			pos = 0;
			w = inw;
		}
		if (np)									// if this letter is included into a word 
														// update parameters and continue
		{
			cout << "continue... " << letter << endl;
			pos = np;
			word += letter;
			if (h + 1 < H) h++;
			else 
			{
				word = "";
				pos = 0;
				h = inh;
				break;
			}
		}
		else break;										// if this letter is not present in the tree
														// reset parameters, break the while loop, do not push anything
	}

	return out;
}



int main()
{
    // INPUT
    while (true)
    {
        cin >> N >> H >> W;
        
        if (N == 0 && H == 0 && W == 0) break;    	// EOF

        clearGrid();
		words.clear();
		for (int n = 0; n < N; n++)			// get words
		{
			string w; cin >> w;
			words.push_back(w);
		}
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                char c; cin >> c;
                grid[h][w] = c;
            }
        }
        
        
        
        // CLOCK START
        auto start = chrono::steady_clock::now();



        // PROCESS
		// preprocess the words and create a tree
		vector< vector<Node> > tree = createTree();

		// go through every cell in a grid and check for words 
		int c = 0;
		set<string> found_case;
		for (int h = 0; h < H; h++)
		{
			for (int w = 0; w < W; w++) 
			{
				vector<string> found = check(h, w, tree);
				for (string wo : found) found_case.insert(wo);
				c += found.size();
			}
		}
		ans.push_back(c);
		sans.push_back(found_case);
	 
        
        
        // CLOCK END
        auto end = chrono::steady_clock::now();
        timed += end - start;
    }



    // OUTPUT
    ofstream out;
    out.open("out.txt");
    out << (timed).count() << "\n";
    for ( int c = 0; c < ans.size(); c++ )
	{
		out << ans[c] << "\n";	
		for (string word : sans[c]) out << word << "\n";
	}
    out.close();



    return 0;
}
