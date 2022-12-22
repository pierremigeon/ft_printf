# Description: takes assert() tests from the main.c file and updates any that are not also printed to standard out upon being run. 
# Usage: bash reformat_tests.sh

if [ ! -e ../../src/main_backup.c]; then cp ../../src/main.c ../../src/main_backup.c; fi
python format_print_tests.py
mv ../../src/main_temp.c ../../src/main.c
make -C ../../ && ../../ft_printf

#If successful, remove backup

