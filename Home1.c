#include <stdio.h>


//Функция для отсева, если число не состоит только из двоичного кода программа закрывается
int isbool(char s) {
	if ((s != '1') && (s != '0')) {
		printf("You made a mistake.");
		return 0;
	}
	else return 1;
}

//Функция для перевода в десятичное число из двоичного
int counter(int min, int max, char* arr) {
	int k = 0;
	for (int i = min; i < max; i++)
	{
		k = (arr[i]-'0') + k*2;
	}
	return k;
}


int main() {
	char sym, array_num[32] = {};
	int i = 0, count = 0;

	while ((sym = getchar()) != '\n') {
		if (isbool(sym)) {
			if (i > 32) {
				printf("You entered too large a number");
				return 1;
			}
			array_num[i++] = sym;
		}
		else return 1;
	}
	
	if ((array_num[0]-'0') == 1 && (array_num[31] != '\0')) {
		count = counter(1, 32, array_num);
		count = ~(2147483647-count);	
	}
	else {
		count = counter(0, i, array_num);
	}
	
	printf("%d\n", count);
	return 0;
}
