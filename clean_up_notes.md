

###   To Do Code Clean Up


Divide the code into smaller functions so that it becomes clear how much time different stages takes up in the code. The following stages in the code should be marked as their own sections in the code:

1. Read and load input data from disk.
2. Pre-iterate the data and choose a direction, known as a feature.
3. Iterate a function 10 times that picks the optimal score vector direction. Training is based on scoring. If a method has a high score it receives more PSMs accordingly.
4. Do a cross-validation. Use 3 SVMs, one for each cross-validation bin. Merge all PSMs into one report.
5. Write the result to file(s).


#### Other Improvements
* Remove unused variables or functions.
* Remove commented out code.
* Remove semicolons placed wrongly, I.e. double semi-colons.
