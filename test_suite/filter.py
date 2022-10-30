#!/usr/bin/env python3


def valid (line):
	for c in match:
		if c in line:
			return (0)
	return (1)

print("Filtering the test output...");

r = open("assert_test_output_raw.txt", "r")
w = open("assert_test_output_filtered.txt", "w")

match = ['\t\t#', '~~~~~~~~~x is ', '~~~~~~~~~a is ']

for x in r:
	if valid(x):
		w.write(x);

r.close()
w.close()
