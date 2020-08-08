# lab-5---as1
C++ code.

This proj read weather sensory data from .csv files; directories of these file are in met_index.txt; read into struct array [date,time,data]
to perform a list of operation such as average, highest, lowest of a date, month year etc.
BST and STL map is used to indexed the data so that processing calculation will be much faster. 



NOTE:submitted as ict283-2 assignment1 

this is originally lab 5 ict283 that modified for assignment 1 and then 2.
basically the assignment require read from a file and load it in a kind of data structure and then run calculation based on the requirements.

assignment 2 requires read from mulitple file in a directories and load in to at least self written Binary Search Tree (BST) and STL map and perform calculation and test the performance by running a timer to calculate the duration for certain task of 
the program (performance timing not done as of 19 april).

STL map is has index value of the main sensor data which is in vector. so that all menu search option will only involve a very small amount of data.

Limitation of the program:

    BST is not AVL or red-black
    BST cannot do rotation
    data (date: date, month, year) can be repeated in vector and BST
    poorly organised code file due to short dev time (4 days -no prev testing on data structure)
    

Version:master is now divided into 2 local repos (not updated to Github): 
    one on Mac for running duration check for program (dependency compatibility: Mac has built-in time.h that conflict with custom time.h)
    windows will run test on Merge and Intersection implementation from algorithm in the Exam 

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
