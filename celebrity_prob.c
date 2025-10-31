#include <stdio.h>
#define N 4

int knows(int M[N][N], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[N][N], int n) {
    int a = 0;
    int b = n - 1;

    while (a < b) {
        if (knows(M, a, b))
            a++;
        else
            b--;
    }

    int candidate = a;

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(M, candidate, i) || !knows(M, i, candidate))
                return -1;
        }
    }

    return candidate;
}

int main() {
    int M[N][N] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int celebrity = findCelebrity(M, N);

    if (celebrity == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person P%d\n", celebrity);

    return 0;
}
