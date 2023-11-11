# ft_printf
A project to re-code the standard printf function

Usage/Description:
```
int  ft_printf(const char * restrict format, ...);
```
The ft_printf() function produces output according to a format as described below. The function writes the output under the control of a format string that specifies how subsequent arguments are converted for output. ft_printf() is variadic- that is, it expects a varriable number (zero or more) of arguments after the initial format string. It returns as an int the number of bytes printed. 

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.  Each conversion specification is introduced by the % character.  After the %, the following appear in sequence:
  1) zero or more of the following flags: + 0 . * -
  2) Optional decimal digit representing the maximum field width
  3) An optional precision, in the form of a period '.' followed by an optional digit string
  4) An optional length modifier, that specifies the size of the argument h hh l ll
  5) A (non-optional) conversion specifier c s p d i u x X f
  6) %% prints '%'


## A note on tests:
I have written extensive tests for this project. Printf is quite versatile, taking many different parameters such as flags, conversions, length modifiers, width and precision specifiers and various data types. On top of that, it is a variadic function, which means that it can take a variable number of arguments. In order to verify that my coding of the classic printf() function is correct, or close to it, I have written a number of tests which use the <assert.h> library macro in order to compare the output of my program to the output of the standard C printf() function. 
Currently, my program successfully passes **376,407 tests**. Many of these tests use different looping schema to cover a range of values, for example spanning boundary values for different data types as well as intermediate values. 

The ft_printf test suite can be found in ./src/main.c. In order to run the tests, navigate to the './test_suite' directory and run make filter. assert_test_output_filtered.txt contains the assert statement and two lines of output, one from standard printf() and another from my ft_printf(), making it possible to view the test run followed by both outputs. 
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
