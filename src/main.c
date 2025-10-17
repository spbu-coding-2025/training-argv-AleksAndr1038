#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int lower_bound = 0;
	int upper_bound = 0;
	int lower_bound_check = 0;
	int upper_bound_check = 0;

	for (int i = 1; i < argc; i++) {
		if (strncmp(argv[i], "--lower_bound=", 14) == 0) {
			lower_bound = atoi(argv[i] + 14);
			lower_bound_check = 1;
		}
		else if (strncmp(argv[i], "--upper_bound=", 14) == 0) {
			upper_bound = atoi(argv[i] + 14);
			upper_bound_check = 1;
		}
	}

	if (!lower_bound_check) {
		fprintf(stderr, "Flag --lower_bound is missing\n");
		return 1;
	}

	if (!upper_bound_check) {
		fprintf(stderr, "Flag --upper_bound is missing\n");
		return 1;
	}

	if (!lower_bound_check && !upper_bound_check) {
		fprintf(stderr, "No flags found\n");
		return 1;
	}

	if (lower_bound > upper_bound) {
		fprintf(stderr, "The lower bound is greater than the upper bound\n");
		return 1;
	}

	for (int i = lower_bound; i <= upper_bound; i++) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}