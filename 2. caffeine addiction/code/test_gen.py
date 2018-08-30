# 
# This is a Test Gen. Use it to generate random test cases for the problem in this folder.
# 
# For this Test Gen you will have to specify two parameters: number of coffee cups per day and number of test cases. 
#
# Run this command to generate a test case:
# python test_gen.py <number of cups> <number of cases>
#
# Do not forget to replace <number of cups> and <number of cases> with actual numerical values. 
#



# IMPORTS
from sys import argv
from random import randint



# VARIABLES
N = int(argv[1])
D = int(argv[2])



# GENERATOR
file = open("testin.txt", "w")

for d in range(D):
    file.write( "{} {}\n".format( N, randint(0, 30) ) )
    for n in range(N):
        file.write( "{} ".format( randint(1, 40) ) )
    file.write("\n")
file.write("0 0")

file.close()
