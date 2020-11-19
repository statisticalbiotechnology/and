# Percolator Notes


This document contains purely subjective thoughts regarding the process of coming to grips with the Percolator source code.

## Flags

It's possible to call the Percolator executable with a myriad of different use-flags. For instance, one may tune the maximum number of threads, n, the application use by specifying
> --num-threads n 

This allows one to change how the software acts. Currently, all optional flags are handled by the *Caller* class. As there is a large ammount of different flags, the class definition becomes very large, and particularly the functions themselves. Actually, most functions are too large in the source code. This makes it difficult to get an overview for what is happening in various code regions. At first glance, it was not clear that the flags were set in the Caller class, perhaps as the class name itself is ambigous. Many parts of the source code have ambigous names. Personally, I don't think that it's always a negative thing to have simple names, but often one wants it to be clear what a function does.

### Too Many Flags?

There are a lot of different optional use-flags to choose from. I don't know what the purpose is for most of them. Perhaps these flags are obviously clear for people that know more about biology. For anyone else though, it might be warranted to have fewer optional flags. If you have too many options the code gets more complicated to use.