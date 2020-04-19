# lab-5---as1
submitted as ict283-2 assignment1

this is originally lab 5 ict283 that modified for assignment 1 and then 2.
basically the assignment require read from a file and load it in a kind of data structure and then run calculation based on the requirements.

assignment 2 requires read from mulitple file in a directories and load in to at least self written Binary Search Tree (BST) and
STL map and perform calculation and test the performance by running a timer to calculate the duration for certain task of 
the program (not done as of 19 april).

Limitation of the program:
    BST is not AVL or red-black
    BST cannot do rotation
    data (date: date, month, year) can be repeated in vector and BST
    

master is now divided into 2 local repos (not updated to Github): 
    one on Mac for running duration check for program
    windows one will run test on Merge and Intersection implementation from algorithm in the Exam 

STRUCTURE:

     main > readfile  > readMetIndex 

                      > SplitString > checkNA ("Not Available")
                 
          > indexMonthYear
          > displayMenu
          > Menu  > showDataOfAmonthOfYear
                  > processData > searchBSTtime
                                > month_to_int
                                > Wh_to_KWh

          > //testUnit
          > //testBST
          > //testMap
          > //unit_testing_func..
