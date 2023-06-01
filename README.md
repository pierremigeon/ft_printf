# ft_printf
A project to re-code the standard printf function

Once again, I'm updating a old project. Taking a break from the minishell to catch my breath! This one's simple by comparison. At least, I can say that not yet having worked on the %f flag. I expect that to be the hardest part of the project!

-Pierre

## Requirements
1) must handle cspdiuxXf% conversions 
2) must handle '+0 .*-' flags
3) must handle width and precision specifiers
4) must handle length modifiers such as h, hh, l, ll, etc

## A note on tests:
I have written extensive tests for this project. Printf is quite versatile, taking many different parameters such as flags, conversions, length modifiers, width and precision specifiers and various data types. On top of that, it is a variadic function, which means that it can take a variable length of arguments. In order to verify that my coding of the classic printf() function is correct, or close to it, I have written a number of tests which use the <assert.h> library macro in order to compare the output of my program to the output of the standard C printf() function. 
Currently, my program successfully passes 376,407 tests. Many of these tests use different looping schema to cover a range of values, for example spanning boundary values for different data types as well as intermediate values. These tests are present in ./src/main.c. In order to run these tests, navigate to the './test_suite' directory and run make filter. The file "less assert_test_output_filtered.txt" contains the assert statement and two lines of output, one from standard printf() and another from my ft_printf().
```
cd ./test_suite
make filter
less assert_test_output_filtered.txt
```
In order to run the entire test suite, see summary statistics for the test results, and view failed tests, run make run_compare.
```
cd ./test_suite
make run_compare
less failed_tests.txt 
less summary.txt
```

Currently, my tests are passing nicely except for my %f flag tests. As I anticipated, this portion of the program has proven to be complicated. I believe that this project is nearly complete in some respects, except for this point. My code is able to handle some instances of %f calls, but I've managed to break it pretty thoroughly with some of my tests. Currently, these are commented out to demonstrate the pretty passing tests. Specifically, these start around line 730. You can see them in all their gory detail by uncommenting this section. Once I get back to working on this project actively again (soon?) I will tackle this and hopefully wrap the entire thing up once and for all.

And also... split the code into modules. And also... some of the code is pretty ugly and exceedingly compact. I also plan to improve this aspect. 
