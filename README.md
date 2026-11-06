# Compile and Run

Run these commands from your printf project directory:

```bash
make fclean
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf

make re && cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf && ./test_printf
