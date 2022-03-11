#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* https://splone.com/blog/2015/3/11/integer-overflow-prevention-in-c/ */

int main_test(int val)
{
	int i;
	char *mem;

	 /* `char *` is a bad example since char
	    needs only 1 byte and we waste memory ;-) */
	size_t v = val * sizeof(char *);

	mem = malloc(v);
	if (mem == NULL) {
		printf("ENOMEM\n");
		return 0;
	}

	for (i = 0; i < val; i++) {
		mem[i] = 'A';
		/* With no read avoid -O3 since the the complete for-loop would
		 * be optimized out */
		/* printf("%c", mem[i]); */
	}

	free(mem);

	return 0;
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t sz)
{
	char string[128] = {0};

	if (sz > sizeof(string) - 1)
		return 0;

	memcpy(&string, data, sz);
	main_test(atoi(string));
	return 0; // Non-zero return values are reserved for future use.
}
