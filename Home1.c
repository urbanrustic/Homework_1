#include <stdio.h>


//Функция для отсева, если число не состоит только из двоичного кода программа закрывается
int isbool(char s) {
    if ((s != '1') && (s != '0')) {
        printf("You made a mistake. There must be letters and numbers from 2 to 9.\n");
        return 0;
    } else return 1;
}

//Функция для перевода двоичного числа в десятичное 
int bin_dec(int min, int max, char * arr) {
    int k = 0;
    for (int i = min; i < max; i++) {
        k = (arr[i] - '0') + k * 2;
    }
    return k;
}

int main() {
    char sym, array_bin[32] = {};
    int counter = 0, res = 0;

    while ((sym = getchar()) != '\n') {
        if (isbool(sym)) {
            // Проверка на переполнение
            if (counter > 31) {
                printf("You entered too large a number!\n");
                return 1;
            }
            array_bin[counter++] = sym;
        } else return 2;
    }
    //Проверяем каким является число (-|+)
    if ((array_bin[0] - '0') == 1 && (array_bin[31] != '\0')) {
        res = bin_dec(1, 32, array_bin);
        res = ~(2147483647 - res);
    } else {
        res = bin_dec(0, counter, array_bin);
    }

    printf("%d\n", res);
    return 0;
}