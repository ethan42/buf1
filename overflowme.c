#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_good() {
    char __attribute__((no_reorder)) * magic = "8675309";
    char buf[32];
    fread(buf, 128, 1, stdin);
    if (strncmp(magic, buf, strlen(magic)) == 0) {
        return 1;
    }
    return 0;
}

int main() {
    if (is_good()) {
        printf("Looking good\n");
        return 0;
    }
    return 1;
}
