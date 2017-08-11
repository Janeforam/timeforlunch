#include <stdio.h>
#include "strindex.h"

int main(int argc, char* argv[]) {
	char str1[10] = "abbcdef";
	char str2[5] = "bc";
	printf("starting index: %d\n", strindex(str1, str2));
	return 0;
}