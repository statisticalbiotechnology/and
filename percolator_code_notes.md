# Percolator Notes


This document contains purely subjective thoughts regarding the process of coming to grips with the Percolator source code.

## Flags

It's possible to call the Percolator executable with a myriad of different use-flags. For instance, one may tune the maximum number of threads, n, the application use by specifying
> --num-threads n 

This allows one to change how the software acts. Currently, all optional flags are handled by the *Caller* class. As there is a large ammount of different flags, the class definition becomes very large, and particularly the functions themselves. Actually, most functions are too large in the source code. This makes it difficult to get an overview for what is happening in various code regions. At first glance, it was not clear that the flags were set in the Caller class, perhaps as the class name itself is ambigous. Many parts of the source code have ambigous names. Personally, I don't think that it's always a negative thing to have simple names, but often one wants it to be clear what a function does.

### Too Many Flags?

There are a lot of different optional use-flags to choose from. I don't know what the purpose is for most of them. Perhaps these flags are obviously clear for people that know more about biology. For anyone else though, it might be warranted to have fewer optional flags. If you have too many options the code gets more complicated to use.


## Bloat
There are some code snippets here and there which don't really belong to the functions they are in, or at the very least could be moved into their own class-objects. For instance, one may specify a flag called *VERBOSE*. It specifies how much output information that should be printed out to the screen. It's also possible to set this flag to a "maximum level" which makes the program output huge amounts of text. I don't know any type of person who would want this kind of output and don't really think anyone is interested in reading that much text from a program. Especially if most of the text is not very interesting. Regardless, this has led to a lot of if-statements in all areas of the code which checks against the VERBOSE flag and then output debug-information if it has a high enough level. This makes the actual functionality harder to read as there is bloat coming from intermixed VERBOSE if-statements. The same problem goes for other optional use-flags. There are a lot of optional flags with randomly distributed if-statements blasted into the source code, which makes it harder to maintain. It's unclear if these if-statements are warranted and really have to take up space in the source code.