#include <stdio.h>
#include <time.h>

// Case 1: Normal power function (O(y))
int Power1(int x, int y) {
    int f = 1;
    for (int i = 1; i <= y; i++) {
        f *= x;
    }
    return f;
}

// Case 2: Fast exponentiation using bitwise shift (O(log y))
int Power2(int x, unsigned int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) 
            res = res * x;
        y = y >> 1;
        x = x * x; 
    }
    return res;
}

// Count digits
int countDigits(int n) {
    if (n == 0) return 1;
    int len = 0;
    while (n != 0) {
        len++;
        n /= 10;
    }
    return len;
}

// Armstrong with Case 1
void armstrong_case1(int n) {
    for (int i = 1; i <= n; i++) {
        int len = countDigits(i);

        // calculate Armstrong sum
        int res = 0, temp = i;
        while (temp != 0) {
            int rem = temp % 10;
            res += Power1(rem, len);
            temp /= 10;
        }
    }
}

// Armstrong with Case 2 
void armstrong_case2(int n) {
    for (int i = 1; i <= n; i++) {
        int len = countDigits(i);

        // calculate Armstrong sum
        int res = 0, temp = i;
        while (temp != 0) {
            int rem = temp % 10;
            res += Power2(rem, len);
            temp /= 10;
        }
    }
}

int main() {
    int testN[] = {10, 100, 1000, 10000, 100000, 1000000 , 10000000};
    int size = sizeof(testN) / sizeof(testN[0]);

    printf("%8s %15s %15s\n", "N", "Case1_Time(s)", "Case2_Time(s)");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        int n = testN[i];
        clock_t start, end;
        double t1, t2;

        // Case 1 timing
        start = clock();
        armstrong_case1(n);
        end = clock();
        t1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Case 2 timing
        start = clock();
        armstrong_case2(n);
        end = clock();
        t2 = ((double)(end - start)) / CLOCKS_PER_SEC;

        // print row
        printf("%8d %15f %15f\n", n, t1, t2);
    }

    return 0;
}