#
# This is The Grader script. Use it to verify your solution.
#
# To run The Grader, enter the following command into the Terminal located to the current folder
# python grader.py
#
# You will find the verdict in the file called verdict.txt
#



# OPEN FILES
solution = open("solution.txt", "r")
out      = open("out.txt", "r")
verdict  = open("verdict.txt", "w")



# GRADE FUNCTION
def grade():
    total = int( solution.readline() )
    score = list()
    while True:
        try:
            K = int( solution.readline() )
            F = int( out.readline() )
        except ValueError:     # EOF 
            break

        if F != K:
            score.append(False)
            solution.readline()
            for f in range(F):
                out.readline()
            continue

        correct = set( solution.readline().split() )
        case = True

        for f in range(F):
            word = out.readline()[:-1]
            if word not in correct: 
                case = False

        score.append(case)
    if len(score) < total:
        verdict.write("Verdict: Output lacks test cases or output format is incorrect\n")
    elif sum(score) == 0:
        verdict.write("Verdict: Completely Incorrect\n")
    elif sum(score) < total:
        verdict.write("Verdict: Partially Incorrect\n")
    else:
        verdict.write("Verdict: Completely Correct\n")
    for case in range( len(score) ):
        verdict.write( str(case + 1) + ". " + str(score[case]) + "\n" )



# TIME LIMIT
limit = float( solution.readline() )
try:
    spent = float( out.readline() )
except ValueError:
    raise ValueError("<Time Spent> line missing or specified incorrectly!")
if spent > limit:
    verdict.write("Verdict: Time Limit Excceeded")
else:
    grade()

	

print("Your verdict is written to verdict.txt")



# CLOSE FILES
solution.close()
out.close()
verdict.close()
