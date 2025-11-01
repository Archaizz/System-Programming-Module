# System-Programming-Module
Programming Class Projects
--------------------------------
USE GUIDE

Select option choice from 1 to 2 to navigate the menu.
The file reading and creation of new files does not interact with the inner data of main manu option 1 and 2.

--------------------------------
INSTALLATION GUIDE

Run the installer.

--------------------------------
Release 1:

This release had the basic menus and student information input manually and generation randomly.

--------------------------------
Release 2:

This release had file reading and mass student information generator added together with file creation for that information with the option to sort.

--------------------------------
FINAL VERSION Release

Measured speed performance with different container types and lastly with algorithm optimizations, specifically partition for student sorting.

--------------------------------

Applying optimization strategy 1.

I applied this strategy from the start so I cannot comment on the changes.

Using the strategy of having two groups of weak and strong students sorted by partition.

--------------------------------

-------->File creation

1,000 - Execution time: 10 ms
10,000 - Execution time: 105 ms
100,000 - Execution time: 1005 ms
1,000,000 - Execution time: 10241 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'

-------->Data reading

kursiokai.txt -Execution time: 6611 ms
studentai10000 - Execution time: 19385 ms
studentai100000 - Execution time: 16574 ms
stuentai1000000 - Execution time: 20744 ms

-------->Student sorting into two groups

1,000 - Execution time: 0 ms
10,000 - Execution time: 4 ms
100,000 - Execution time: 17 ms
1,000,000 - Execution time: 187 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'


-------->Writing sorted results to files

1,000 - Execution time: 2 ms
10,000 - Execution time: 19 ms
100,000 - Execution time: 130 ms
1,000,000 - Execution time: 1193 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'

 ---------------------------------------------------------------------> Container performance test:
Measure program speed using three container types:
std::vector 
std::list
std::deque
Measure only these steps:

----->Reading data from files

std::vector---------------- 
kursiokai.txt -Execution time: 6611 ms
studentai10000 - Execution time: 19385 ms
studentai100000 - Execution time: 16574 ms
stuentai1000000 - Execution time: 20744 ms

std::list------------------
kursiokai.txt - File Reading Execution time: 6480 ms
studentai10000 - File Reading Execution time: 11362 ms
studentai100000 - File Reading Execution time: 12412 ms
stuentai1000000 - File Reading Execution time: 24545 ms

std::deque----------------

kursiokai.txt - File Reading Execution time: 0 ms
studentai10000 - File Reading Execution time: 205 ms
studentai100000 - File Reading Execution time: 2245 ms
stuentai1000000 - File Reading Execution time: 16146 ms


------>Sorting students into two groups

std::vector-------------

1,000 - Student Sorting Execution time: 3 ms
10,000 - Student Sorting Execution time: 7 ms
100,000 - Student Sorting Execution time: 20 ms
1,000,000 - Student Sorting Execution time: 365 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'


std::list----------------
1,000 - Student Sorting Execution time: 0 ms
10,000 - Student Sorting Execution time: 0 ms
100,000 - Student Sorting Execution time: 42 ms
1,000,000 - Student Sorting Execution time: 196 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'

std::deque--------------

1,000 - Student Sorting Execution time: 1 ms
10,000 - Student Sorting Execution time: 4 ms
100,000 - Student Sorting Execution time: 22 ms
1,000,000 - Student Sorting Execution time: 209 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'

------>Creating new files

std::vector------------

1,000 - Creating File Execution time: 2 ms
10,000 - Creating File Execution time: 21 ms
100,000 - Creating File Execution time: 123 ms
1,000,000 - Creating File Execution time: 1312 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'


std::list-----------

1,000 - Creating File Execution time: 7 ms
10,000 - Creating File Execution time: 69 ms
100,000 - Creating File Execution time: 709 ms
1,000,000 - Creating File Execution time: 7100 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'

std::deque---------------

1,000 - Creating File Execution time: 2 ms
10,000 - Creating File Execution time: 21 ms
100,000 - Creating File Execution time: 128 ms
1,000,000 - Creating File Execution time: 1307 ms
10,000,000 - terminate called after throwing an instance of 'std::bad_alloc'
------------------------------------

POST OPTIMIZATION sorting with Partition

	In a way it appears to be slower with the optimization but for the first time I was able to get a result from 10,000,000 without getting an error.

std::vector-------------

1,000 - Student Sorting Execution time: 1 ms
10,000 - Student Sorting Execution time: 5 ms
100,000 - Student Sorting Execution time: 44 ms
1,000,000 - Student Sorting Execution time: 372 ms
10,000,000 - Student Sorting Execution time: 4580 ms
-----------------------------------


--------------------------------