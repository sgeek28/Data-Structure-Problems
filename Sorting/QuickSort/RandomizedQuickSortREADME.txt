Quick SORT
Quick sort is a inplace sorting technique.

-------------------------------------------------------------
REQUIRED LIBRARIES:
-------------------------------------------------------------
<chrono>
<sys/time.h>
<vector>

-------------------------------------------------------------
PLATFORM(USED WHILE RUNNING CODE):
-------------------------------------------------------------
OS:Kali GNU/linux Rolling(64 bit)
Processor: i5-7200U CPU @ 2.50GHz x 4

-------------------------------------------------------------
INPUT PARAMETERS:-
-------------------------------------------------------------
For running a program sucessfully in program itself we have 
created random input file and we have to pass the text
file containing the random numbers preferabally containing
large ammount of number (above 10k elements) to the algorithm.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
OUTPUT:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

i/p Size          Exection time of                  Execution time in                Exection time in                Execution time in
                  normal partion(ms)                hoare partion(ms)                median patition                 prob partition

  2048                  321                                388                             360                             1100
 
  4096                  680                                715                             850                             3001

  5000                  842                                981                             990                             4100

  7000                  1300                               1290                            1599                            6500
  
  8192                  1470                               1520                            1820                            9000

  32768                 7082                               6560                            8264                            79741
  
  65536                 15400                              13600                           19106                           234501

  262144                87909                              55900                           95369                           1544784
  
  1048576               727096                             236961                          799450                          12696195

------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ANALYSIS:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
In above aoutput analysis we see that initially the hoare partion
algorithm is taking a bit more than than that of normal partion method
(in which we are considering the last element as a  pivot element).
in general for the random input quick sort run with O(n log n) complexity.
As we can see for input size of upto roughly 5000-6000 we are getting 
slightly better results for normal partion method.
But as we start increasing the the input size the hoare partition tends
is giving output in less time.
Also when we given input of 4096 it took 680ms for input size 8192(twice)
it took 1470 which is approximately above 2 time similar to n log n.

For larger inputs the hoare partion is working visibally better than the
simple normal partion method.


In above aoutput analysis we see that initially the median partition 
algorithm is taking less time,
In general for the random input quick sort run with O(n log n) complexity.
But as we start increasing the the input size the median partition taking
signigficant time in n log n times approximately.

input 2048        -> 360 ms

input 4096(twice) -> 850 ms (around 2 times and above approximately nlog n)

input 8192(2 * 4096) -> 1820 ms 

here if we check as 8192 is twice of 4096 we should get 2 * n log n time 

so we can say that the time complexity is increasing n log n times.


In above output analysis we see that initially the random partition
algorithm is taking very high compared to other quick sort methods time,
In general for the random input quick sort run with O(n log n) complexity.
But as we start increasing the the input size the median partition taking
signigficant time in n log n times approximately.

input 2048        -> 1100 ms

input 4096(twice) -> 3001 ms (around 2 times and above approximately nlog n)

input 8192(2 * 4096) -> 9000 ms 

This type of the partion method is suprisingly taking very high time as 
compared to the other partion routines.

so we can say that the time complexity is increasing n log n times.









































