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
    correct = list()
    outline = out.readline()
    solline = solution.readline()
    while solline != '':
        if outline == solline:
            correct.append(True)
        else:
            correct.append(False)
        outline = out.readline()
        solline = solution.readline()
    if sum(correct) == 0:
        verdict.write("Verdict: Completely Incorrect\n")
    elif sum(correct) < len(correct):
        verdict.write("Verdict: Partially Incorrect\n")
    else:
        verdict.write("Verdict: Completely Correct\n")
    for case in range( len(correct) ):
        verdict.write( str(case + 1) + ". " + str(correct[case]) + "\n" )



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



# CLOSE FILES
solution.close()
out.close()
verdict.close()
