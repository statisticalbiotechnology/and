

# Performance Test Results

## Background

Here are results displayed from running the Percolator C++ source code and measuring the run-time it took for the program to finish. Measurements do not include the time it took to load input-data.

Measurements was done by running the python script "SystemTest_Percolator_Speed.py". This script starts a child-process, which in this case is the Percolator executable and also pass on relevant inputs and flags. Then it captures the output which includes the run-time by re-directing pipes from stdout and stderr.

It's necessary to evaluate the performance before deciding on making changes to the source code. The tests here include checking the speed of running Percolator unmodified, using the Quick-LOHify algorithm or replacing some parts of the code that use std::sort with the parallelized version __gnu_parallel::sort (note that in C++17 and C++20 parallelization is more or less automatically implemented for std::sort).

## Tests

The most interesting data retrieved from tests were the minimum and average run-time it took to run Percolator. Most tests were repeted 10 or 5 times. The input data contained 25 million lines of PSMs. C++14 was used for these tests and the time it took reading the input from disk not accounted for.

All tests was conducted on a stationary computer running Ubuntu 18.04.5 LTS with the following hardware:
- 32 GB of RAM (clocked at 1333Mhz)
- Intel(R) Core(TM) i7-4790K CPU @ 4.00GHz
- Seagate 10 TB HDD

## Results

The raw data for the results can be seen [here](https://github.com/statisticalbiotechnology/and/tree/master/raw_data). The tests showed a minor speed-up when implementing Quick-LOHify in CrossValidation::mergeCpCnPairs(...), as it was done by Oliver Serang et al. A 5.5 minute speed-up was achieved for what normally takes about 1 hour. In other words, Quick-LOHify could make Percolator up to 10% faster.

Parallelizing std::sort also showed a small improvement in speed, but not large enough perhaps to justify changing the source code. The reason for why not a greater imrovement was seen is probably that some code already is running in parallel through OpenMP.

