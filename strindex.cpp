#include "strindex.h"
int strindex(char* s, char* t) {
	int i, j, k;
	for (int i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0'&&s[j] == t[k]; j++, k++)
			;
		if(t[k] == '\0' && k > 0)
			return i;
	}
	return -1;

}