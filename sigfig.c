#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double
roundto (const double x, const double n)
{
	double y = pow(10, n);
	return y * round(x / y);
}

int
relu (const int x)
{
	return x > 0 ? x : 0;
}

char *
sigfig (const double x, const int sigfigs)
{
	int digits = floor(log10(fabs(x))) + 1;
	double y = roundto(x, digits - sigfigs);
	char *res;
	int ret = asprintf(&res, "%.*f", relu(sigfigs - digits),  y);
	return res;
}


int
main (int argc, char *argv[])
{
	assert(argc >= 2);
	double x = atof(argv[1]);
	char *n;

	if (argc > 2) {
		n = sigfig(x, atoi(argv[2]));
		printf("%s\n", n);
		free(n);
	} else
		for (int i = 0; i < 10; ++i) {
			char *n = sigfig(x, i);
			printf("%2d: %s\n", i, n);
			free(n);
		}

	return 0;
}

