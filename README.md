# How to Use Guide

If you are asking yourself what this repository is about -- it is a directory filled with all sorts of computational problems that are fun to solve; and here is how to use it.

## Task Description

Every folder has a problem statement -- a MarkDown type file named *task.md*. You can view it here (on GitHub) or you can also consider installing a [MarkDown Viewer](https://github.com/simov/markdown-viewer) and viewing the file locally, using your browser (which is probably more handy for offline use).

## Test Gen

Most folders will have a file called *test_gen.py* contained within the *code* folder, which, you guessed it right, can be used to generate random test cases to test your algorithm. However, it is a Python file, so make sure you have [Python3](https://www.python.org/downloads/) installed on your machine. During Python installation process make sure you tick the box that asks you to **add Python to the PATH** -- this way you will only need to open a Terminal, locate it to the necessary folder and run this command to generate a test input:

```terminal
python test_gen.py <probably some parameters>
```

The Generator may require you to specify some parameters -- most likely the size of the test input you want to get. Look into the *test_gen.py* file for specific information on that.

After you run the Generator, you will notice a file called *testin.txt* appear in the folder. Use it wisely.

## Editorial

### Solution

Inside each problem folder, you can find *editorial* folder that contains two files. One of those will be called *solution* -- it it a program file, if you run it using any valid input for the specific problem, it will generate a file called *out.txt*. In the file generated you will find correct output corresponding to the input provided.

### Explanation

Of course, it would be highly disrespectful of me to just leave you with my *solution.cpp* file and force you to decrypt my code in an attempt to understand what it is supposed to do.

Therefore, I put the file called *explanation.md* into every *editorial* folder for every problem there is. In that file you will find my explanation of the method I was using to solve this specific problem.

## Grader

Suppose you ran your program, it has generated the *out.txt* file into the *code* folder. Now you need to check if your solution is correct and if it satisfies the time limit. For these purposes you run the Grader script. It requires [Python3](https://www.python.org/downloads/) too, so make sure you have it installed.

To run the Grader you need to open your Terminal, locate it to the necessary *code* folder and run this command:

```terminal
python grader.py
```

Make sure that your output file is called *out.txt* and **do not modify** *solution.txt* file in any way, otherwise, you might get graded incorrectly.

Open *verdict.txt* file to see the verdict.

---

**Good luck and have fun!**