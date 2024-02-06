#include <stdio.h>

int binarySearch(char arr[], int l, int r, char x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1; // Produto não encontrado
}

int main() {
    char products[] = {'apple', 'banana', 'grape', 'orange', 'pear'};
    int n = sizeof(products) / sizeof(products[0]);
    char search_product = 'orange';

    int result = binarySearch(products, 0, n - 1, search_product);

    if (result == -1)
        printf("Produto não encontrado\n");
    else
        printf("Produto encontrado na posição %d\n", result);

    return 0;
}
