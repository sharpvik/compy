# Caffeine Addiction | #2

## Metadata

### Time Limit

1000 milliseconds.

### Tags

Maths | Implementation
-|-

## General Statement

If you have read the [first problem](../1.%20kitchen/task.md), you already know that Bill **loves** to party. Yet, it is very hard to stay active during the day if you did not sleep at night. For this reason, over the years, Bill has developed his caffeine addiction. He would like to know how he would feel if he did not drink coffee but he could never know because if he does not receive his caffeine shot when it is needed, he falls asleep for a long time. That is why Bill wants to drink as much coffee as possible for a human being to process. Yet, overdose is unacceptable!

![Question](images/question.png)

To control his coffee level, Bill uses a special detector that measures it. Detector gives output in *Coffee Units* (CU).

Unfortunately, Bill's coffee machine is broken and he cannot control the coffee strength, yet he knows the strength of each cup he gets from it. Each morning coffee machine produces *N* coffee cups of different strength. The stronger the coffee the bigger the CU boost Bill gets after consuming it.

Every day Bill wakes up at a level of *K* CU (this level never drops throughout the day -- it can only increase). Out of those *N* coffee cups produced by the machine he wants to drink as many as he can without getting an overdose. Bill gets overdose whenever his coffee level rises above **100 CU**. Bill can **only** drink cups in an order they are produced by the machine. Bill needs **your** help to get it right!

## Input

There will be *D* test cases (D days). For each day, in the first line, you will be given the *number of coffee cups produced* (N) and *Bill's initial coffee level* (K). **1 ≤ N ≤ 101, 0 ≤ K ≤ 100**.

For each day, in the second line, you will get a list of numbers of size *N* -- CU boost Bill gets by consuming *i-th* cup of coffee. Each number *C* in this list is of limited size **1 ≤ C ≤ 101**.

Input ends with `0 0`.

Input is contained within the *in.txt* file inside the *code* folder. You can make your program read the file or you can `copy + paste` its contents into the console while running your algorithm.

## Task

Look at the numbers and calculate the **maximum** number of cups Bill will be able to drink this morning without getting an overdose. Remember, **his fate depends on you**!

## Output

Inside the *code* folder you will find a file named *out.txt* where you must write your answers. First line of *out.txt* must contain a number of **milliseconds** it took your algorithm to compute the solution. Next *D* lines must contain **one** number each -- solution for the *i-th* of the *D* test cases you were given.

**IMPORTANT**: You have to be careful with the way you time your code. You do not want to time the part of your code that asks for input, *especially* if you provide input through the Terminal window instead of reading a file. Make sure to **only** time the part that processes the input and produces the result.

## Samples & Explanations

### Sample Input

```txt
3 50
5 10 15
3 100
5 10 15
1 0
101
5 50
30 10 5 5 1
0 0
```

### Sample Output

```txt
3
0
0
4
```

### Explanation

In the **first test case**, Bill's initial coffee level is 50 and even if he was to consume all 3 cups, his coffee level would not reach 100.

```txt
50 + (5 + 10 + 15) = 50 + 30 = 80
--> 80 < 100
--> answer is 3 (all cups).
```