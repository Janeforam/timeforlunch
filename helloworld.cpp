#include <stdio.h>
#include "strindex.h"

int main(int argc, char* argv[]) {
	char str1[20] = "12.3e+6";
	char str2[5] = "bc"; //3
	char str3[5] = "";//-1
	char str4[10] = "abcbcdeff"; //-1

	printf("the reuslt of atof: %f\n", atof_scientific(str1));
	return 0;
}