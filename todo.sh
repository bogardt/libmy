#test segfault:
gcc my_split.c - I./ includes - L.- lmy - O0 - g3;
valgrind./ a.out

#principal cmd:
make re; make clean; make re_test; make clean_test; ./check_tests

#pour trouver les memory leaks
valgrind ./check_tests