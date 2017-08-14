#include "strindex.h"

static bool isdigit(char c);
static bool isspace(char c);

//return the position of t in s
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

//return the position of the rightmost occurrence of str2 in str1
int strindex_rightmost(char* str1, char* str2) {
	int i = 0, j = 0;
	int m, n, k;
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		j++;

	if (j == 0) return -1;
	for (i = i-1 ; i >= 0; i--) {
		for (m = i, n = j - 1; m >= 0 && n >= 0 && str1[m] == str2[n]; m--, n--)
			;
		if (n < 0) return i-j+1;
	}
	return -1;
}

//string to float
double atof(char* str) {
	int i = 0, sign;
	double value = 0.0, power = 10.0;
	while (isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-') i++;

	for (; isdigit(str[i]); i++) {
		value = value*10.0 + str[i] - '0';
	}

	if (str[i] == '.')
		i++;
	for (; isdigit(str[i]); i++) {
		value += (str[i] - '0')/power;
		power *= 10.0;
	}

	return value * sign;

}
double atof_scientific(char* str) {
	int i = 0, sign, sign_e, value_e = 0;
	double value = 0.0, power = 10.0, power_e = 1.0;
	double result = 0.0;
	while (isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-') i++;

	for (; isdigit(str[i]); i++) {
		value = value*10.0 + str[i] - '0';
	}

	if (str[i] == '.')
		i++;
	for (; isdigit(str[i]); i++) {
		value += (str[i] - '0') / power;
		power *= 10.0;
	}
	if (str[i] == 'e' || str[i] == 'E')
		i++;
	sign_e = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+') i++;
	for (; isdigit(str[i]); i++)
		value_e = value_e * 10 + str[i] - '0';
	result = value*sign;
	if (sign_e == 1) {
		while (value_e > 0) {
			result *= 10.0;
			value_e--;
		}
	}else {
		while (value_e > 0) {
			result /= 10.0;
			value_e--;
		}

	}
	return result;

}
static bool isspace(char c) {
	return (c == ' ');
}

static bool isdigit(char c) {
	return (c >= '0' && c <= '9');
}