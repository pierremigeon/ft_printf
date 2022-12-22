#!/usr/bin/env python3

from __future__ import print_function
import re

# Description: Creates printf statements for orphan assertion tests (not yet printed to stdout) and adds them to main.c
# Usage: python ./format_print_tests.py
# author: Pierre Migeon 12/20/2022

def get_assertion(line):
	replacements = re.findall("[^%](%[^\s\\\\n%]+)", line)
	replacements = replacements[:len(replacements)//2]
	leading = re.findall('[\t ]+', line)
	vars = re.findall(', [^,)]+', line)
	out = leading[0] + "printf(\"" + line.strip().replace('\\', '\\\\').replace(";","").replace("%","%%").replace("\"","\\\"")
	for i, x in enumerate(replacements):
		out = out.replace(vars[i], ", " + replacements[i])
	out += ";\\n\""
	for x in vars:
		out += x
	out += ");\n"
	return out


r = open("../../src/main.c", "r")
w = open("../../src/main_temp.c", "w")

line =""
for i in r:
	if "\tassert" in i and line == "" and not re.findall('//\t' ,i) :
		w.write(get_assertion(i))
	line = i if "\tprintf" in i and '(\"assert' in i else ""
	w.write(i)

r.close()
w.close()
