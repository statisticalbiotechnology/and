# Test of sorting speed with std::sort

I tried the sorting speed of a couple of different objects. In each of the experiments we sorted 25 million entries.

(base) lukask@shannon:~/git/and/exp/std_sort_speed$ ./float ; ./pair; ./scoreholder
MB USED BEFORE PSMs: 2.544
MB USED: 98.56
MB USED: 98.56
MB USED: 98.56
MB USED: 98.56
MB USED: 98.56
 MAX: 8769
 MIN: 8663
 AVG: 8728
Test completed.
MB USED BEFORE PSMs: 2.544
MB USED: 196.248
MB USED: 196.248
MB USED: 196.248
MB USED: 196.248
MB USED: 196.248
 MAX: 11858
 MIN: 11655
 AVG: 11737
Test completed.
MB USED BEFORE PSMs: 2.544
MB USED: 1367.94
MB USED: 1367.94
MB USED: 1367.94
MB USED: 1367.94
MB USED: 1367.94
 MAX: 11975
 MIN: 11561
 AVG: 11781
Test completed.
(base) lukask@shannon:~/git/and/exp/std_sort_speed$ ^C
