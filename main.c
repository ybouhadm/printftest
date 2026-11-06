
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(name, format, ...) \
	do \
	{ \
		int original; \
		int mine; \
		printf("\n--- %s ---\n", name); \
		printf("ORIGINAL: "); \
		fflush(stdout); \
		original = printf(format, ##__VA_ARGS__); \
		printf("MINE:     "); \
		fflush(stdout); \
		mine = ft_printf(format, ##__VA_ARGS__); \
		printf("RETURNS:  original=%d | mine=%d | %s\n", \
			original, mine, \
			(original == mine) ? "PASS" : "FAIL"); \
	} while (0)

int	main(void)
{
	int	x;
	int	y;

	x = 42;
	y = -42;

	printf("\n========================================\n");
	printf("       FT_PRINTF COMPLETE TESTS\n");
	printf("========================================\n");

	printf("\n========== 1. BASIC CONVERSIONS ==========\n");
	TEST("CHAR", "%c\n", 'A');
	TEST("STRING", "%s\n", "Hello World");
	TEST("DECIMAL", "%d\n", -42);
	TEST("INTEGER", "%i\n", 42);
	TEST("UNSIGNED", "%u\n", 4294967295u);
	TEST("HEX LOWER", "%x\n", 255u);
	TEST("HEX UPPER", "%X\n", 255u);
	TEST("POINTER", "%p\n", (void *)&x);
	TEST("PERCENT", "%%\n");

	printf("\n========== 2. INTEGER EDGE CASES ==========\n");
	TEST("ZERO", "%d\n", 0);
	TEST("POSITIVE ONE", "%d\n", 1);
	TEST("NEGATIVE ONE", "%d\n", -1);
	TEST("INT MIN", "%d\n", INT_MIN);
	TEST("INT MAX", "%d\n", INT_MAX);
	TEST("INT MIN WITH I", "%i\n", INT_MIN);
	TEST("INT MAX WITH I", "%i\n", INT_MAX);

	printf("\n========== 3. UNSIGNED EDGE CASES ==========\n");
	TEST("UNSIGNED ZERO", "%u\n", 0u);
	TEST("UNSIGNED ONE", "%u\n", 1u);
	TEST("UNSIGNED MAX", "%u\n", UINT_MAX);
	TEST("HEX ZERO", "%x\n", 0u);
	TEST("HEX MAX", "%x\n", UINT_MAX);
	TEST("HEX UPPER MAX", "%X\n", UINT_MAX);

	printf("\n========== 4. STRING EDGE CASES ==========\n");
	TEST("NULL STRING", "%s\n", (char *)NULL);
	TEST("EMPTY STRING", "[%s]\n", "");
	TEST("ONE CHARACTER", "%s\n", "A");
	TEST("LONG STRING", "%s\n",
		"This is a longer string to test ft_printf.");
	TEST("STRING WITH SPACES", "[%s]\n", "Hello 42 World");

	printf("\n========== 5. POINTER EDGE CASES ==========\n");
	TEST("NULL POINTER", "%p\n", (void *)NULL);
	TEST("ZERO POINTER", "%p\n", (void *)0);
	TEST("INTEGER POINTER", "%p\n", (void *)&x);
	TEST("SECOND POINTER", "%p\n", (void *)&y);

	printf("\n========== 6. CHARACTER EDGE CASES ==========\n");
	TEST("SPACE", "[%c]\n", ' ');
	TEST("NULL CHARACTER", "[%c]\n", '\0');
	TEST("TAB", "[%c]\n", '\t');
	TEST("NEWLINE", "[%c]\n", '\n');
	TEST("ASCII 127", "[%c]\n", 127);

	printf("\n========== 7. MULTIPLE CONVERSIONS ==========\n");
	TEST("MULTIPLE INTEGERS", "%d%d%d\n", 1, 2, 3);
	TEST("MULTIPLE CHARACTERS", "%c%c%c\n", 'A', 'B', 'C');
	TEST("MULTIPLE STRINGS", "%s%s%s\n", "Hello", "", "World");
	TEST("MIXED CONVERSIONS", "%c %s %d %i %u %x %X %%\n",
		'A', "Hello", -42, 42, 100u, 255u, 255u);

	printf("\n========== 8. PERCENT EDGE CASES ==========\n");
	TEST("ONE PERCENT", "%%\n");
	TEST("TWO PERCENTS", "%%%%\n");
	TEST("THREE PERCENTS", "%%%%%%\n");
	TEST("PERCENT BETWEEN TEXT", "100%% completed\n");

	printf("\n========== 9. FORMAT EDGE CASES ==========\n");
	TEST("EMPTY FORMAT", "");
	TEST("PLAIN TEXT", "Hello World!\n");
	TEST("NO CONVERSIONS", "123456789\n");
	TEST("CONVERSION AT START", "%d is the answer\n", 42);
	TEST("CONVERSION AT END", "The answer is %d", 42);

	printf("\n========== 10. MIXED STRESS TEST ==========\n");
	TEST("ALL CONVERSIONS",
		"%c | %s | %p | %d | %i | %u | %x | %X | %%\n",
		'Z', "Testing", (void *)&x,
		INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);

	TEST("NEGATIVE AND POSITIVE",
		"%d | %d | %d | %d\n",
		INT_MIN, -1, 0, INT_MAX);

	TEST("UNSIGNED AND HEX",
		"%u | %x | %X\n",
		UINT_MAX, UINT_MAX, UINT_MAX);

	printf("\n========================================\n");
	printf("          ALL TESTS FINISHED\n");
	printf("========================================\n");
	return (0);
}
