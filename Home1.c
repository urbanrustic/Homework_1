#include <stdio.h>
#include <stdbool.h>

// int power(int a, int b) {
// 	int c = 1;
// 	while (b) {
// 		c*= a;
// 		b--;
// 	}
// 	return c;
// }

//Функция для отсева, если число не состоит только из двоичного кода программа закрывается
int isbool(char s) {
	if ((s != '1') && (s != '0')) return 0;
	else return 1;
}

int main() {
	char sym, array_num[32] = {};
	int i = 0, count = 0;

	while ((sym = getchar()) != '\n') {
		if (isbool(sym)) {
			if (i > 32) return 1;
			array_num[i++] = sym;
		}
		else return 1;
	}
	
	//Идёт с начала массива, надо чтоб шла с конца
	if (array_num[31] == '\0') {
		for (int k = 0; k < i; k++) {
			count = (array_num[k]-'0') + count*2;
		}
	}
	else {
		for (int k = 0; k < i-1; k++) {
			count = (array_num[k]-'0') + count*2;
		}
		count = ~(count-1);
	}
	
	printf("%d\n", count);
	return 0;
}
