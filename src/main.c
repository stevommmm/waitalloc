#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Missing number of bytes to allocate via args.\n");
        exit(1);
    }
    long long bytes = atoll(argv[1]);
    long long i = 0;
    long ps = sysconf(_SC_PAGESIZE);

    unsigned char *m = malloc(bytes);
    if (m == NULL) {
        printf("Failed to allocate %lld bytes.\n", bytes);
        exit(1);
    }
    // Mark bytes in pages so we actually consume it
    while (i < bytes) {
        m[i] = 1;
        i += ps;
    }

    printf("Allocated %lld bytes. Press enter to free.\n", bytes);
    getchar();
    free(m);
    return 0;
}
