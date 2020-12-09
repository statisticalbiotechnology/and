# Test of sorting speed with std::sort

I tried the sorting speed of a couple of different objects. In each of the experiments we sorted 25 million entries.

```
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
```
The same code executed on UoM gives  

### float
```
MB USED BEFORE PSMs: 2.696
MB USED: 98.272
MB USED: 98.272
MB USED: 98.272
MB USED: 98.272
MB USED: 98.272
 MAX: 15493
 MIN: 15324
 AVG: 15393
Test completed.
```
### pair
```
MB USED BEFORE PSMs: 2.696
MB USED: 195.896
MB USED: 195.896
MB USED: 195.896
MB USED: 195.896
MB USED: 195.896
 MAX: 19447
 MIN: 19283
 AVG: 19353
Test completed.
```
### scoreholder
```
MB USED BEFORE PSMs: 2.696
MB USED: 1367.79
MB USED: 1367.79
MB USED: 1367.79
MB USED: 1367.79
MB USED: 1367.79
 MAX: 18936
 MIN: 18753
 AVG: 18836
Test completed.
```

## Version check
The execution speed is significantly slower on the UoM machine. Could this be due to differenses in configurations?

My stdlib is
```
(base) lukask@shannon:~/git/and/exp/std_sort_speed$ ls -l /lib/x86_64-linux-gnu/libstdc++.so.?
lrwxrwxrwx 1 root root 19 Aug  8 14:12 /lib/x86_64-linux-gnu/libstdc++.so.6 -> libstdc++.so.6.0.28
```
which according to the [documentation](http://gcc.gnu.org/onlinedocs/libstdc++/manual/abi.html) corresponds to GCC 9.3.0.
