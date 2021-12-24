clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c *.c
ar -cq minilibmx.a *.o
rm *.o