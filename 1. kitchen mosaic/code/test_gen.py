# 
# This is a Test Gen. Use it to generate random test cases for the problem in this folder.
# 
# For this Test Gen you will have to specify two parameters: height and width of the grid. 
# You decide how large it should be. However, you should probably remember that
# my test cases can only be 5'000 x 5'000 large at most. Just do not go crazy...
#
# Run this command to generate a test case:
# python test_gen.py <height> <width> <number of cases>
#
# Do not forget to replace <height> and <width> with actual numerical values. 
#



# IMPORTS
from sys import argv
from random import randint



# VARIABLES
H = int(argv[1])
W = int(argv[2])
N = int(argv[3])



# GENERATOR
file = open("testin.txt", "w")

for n in range(N):
    file.write( "{} {}\n".format(H, W) )
    for h in range(H):
        for w in range(W):
            file.write( "." if randint(0, 1) == 0 else "#" )
        file.write("\n")
file.write("0 0")

file.close()
