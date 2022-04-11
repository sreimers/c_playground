#include <stdio.h>
#include <stdlib.h>

struct test {
	int i;
};

int main(int argc, char **argv)
{
	int test[]     = {1, 2, 3};
	struct test *t = NULL;
	int i;

	if (argc < 2)
		exit(1);

	i = atoi(argv[1]);

	printf("Hello World %d %d", test[i], t->i);

	return 0;
}
