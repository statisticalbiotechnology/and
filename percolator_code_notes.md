# Percolator Notes


This document contains purely subjective thoughts regarding the process of coming to grips with the Percolator source code.

## Things That Would Help

Here are some things which normally might make a code base easier to understand for newcomers. It might not be trivial to implement these ideas in Percolator.

### UML Diagram
UML diagrams allows one to plan ahead and also map how existing classes depend on one another to function correctly. Having a UML map makes it easier to see which classes are coupled and thereby helps making the code as a whole more modular. Modularity is a cornerstone in programming best practices. If the code is modular, it becomes trivial to add, remove or edit functions, since these would be indepentent towards the rest of the program. If the UML diagram is hard to interpret it usually means that the code is poorly structured.

### Separation of Calculations and I/O
Reading and outputting text occur everywhere as it's now. It would make it easier to maintin the code if most of the output was limited to a specific individual function, and the process of reading data from files were limited as well to its own place.

### Unit Tests

Whilst I'm aware that this is being considered in future updates, there are currently pretty much non-existent unit testing in place. Due to there being no unit tests, one does not dare to make modifications to the code. It's extremely easy to create bugs when programming. Unit tests makes it possible to check, for the most part, that modifications do not cause the code to malfunction. It would be very helpful if there were unit tests in place that checked that the output is correct. Thereby, if something is changed one can still know that the program works.

### Documentation
There is already some documentation available through the wiki-page. However, there could be more documentation. The wiki was lastly updated 3 years ago, and might be out-dated.

## Things That Felt Unstructured
Here are some notes of things that appeared unstructured when I looked into Percolator.

### Bad Comments
There are old comments that no longer match the code they are describing. It's tricky to decide if one should delete the code or the comments as they both might be important.

### Flags

It's possible to call the Percolator executable with a myriad of different use-flags. For instance, one may tune the maximum number of threads, n, the application use by specifying
> --num-threads n 

This allows one to change how the software acts. Currently, all optional flags are handled by the *Caller* class. As there is a large ammount of different flags, the class definition becomes very large, and particularly the functions themselves. Actually, most functions are too large in the source code. This makes it difficult to get an overview for what is happening in various code regions. At first glance, it was not clear that the flags were set in the Caller class, perhaps as the class name itself is ambigous. Many parts of the source code have ambigous names. Personally, I don't think that it's always a negative thing to have simple names, but often one wants it to be clear what a function does.

### Design
Some structs or functions were overly complicated. In some parts of the code dynamic memory was used when not needed. Also, it would make the code better if memory was freed in class destructors instead of manually in the code.

One should try to avoid passing boolean variables as function parameters. Instead of passing a boolean it's usually better to simply create two different functions.

#### Too Many Flags?

There are a lot of different optional use-flags to choose from. I don't know what the purpose is for most of them. Perhaps these flags are obviously clear for people that know more about biology. For anyone else though, it might be warranted to have fewer optional flags. If you have too many options the code gets more complicated to use.


### Bloat
There are some code snippets here and there which don't really belong to the functions they are in, or at the very least could be moved into their own class-objects. For instance, one may specify a flag called *VERBOSE*. It specifies how much output information that should be printed out to the screen. It's also possible to set this flag to a "maximum level" which makes the program output huge amounts of text. I don't know any type of person who would want this kind of output and don't really think anyone is interested in reading that much text from a program. Especially if most of the text is not very interesting. Regardless, this has led to a lot of if-statements in all areas of the code which checks against the VERBOSE flag and then output debug-information if it has a high enough level. This makes the actual functionality harder to read as there is bloat coming from intermixed VERBOSE if-statements. The same problem goes for other optional use-flags. There are a lot of optional flags with randomly distributed if-statements blasted into the source code, which makes the code itself harder to maintain. It's unclear if these if-statements are warranted and really have to take up space in the source code.

### CMake Constants
Some C++ files are marked with ".cmake" extensions, and are used by CMake scripts to define constants. This makes the code coupled directly to CMake, even though that is not necessary. This could be fixed by having CMake defining constants in plain non-C++ text-files, and having the program reading in those text-files instead.

## Things That were Hard to Understand

A lot of things are still unclear regarding the code base. Here are some general things to note that make (or made) Percolator hard to understand.

There is an extensive use of jargon from (presumably) the field statistical biology. If one is not familiar with words related to that area it becomes harder to know what certain parts of the code does.
