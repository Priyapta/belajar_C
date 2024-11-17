#include <stdio.h>

int main() {
    int base, actual;

    // Meminta input Base dan Actual langsung dalam satu baris
    printf("Subaru menyerang! Base: ");
    scanf("%d", &base);
    printf(", Actual: ");
    scanf("%d", &actual);

    // Menampilkan hasilnya
    printf("Subaru menyerang! Base: %d, Actual: %.2f (x0.60)\n", base, actual * 0.60);

    return 0;
}
