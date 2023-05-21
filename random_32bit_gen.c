#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main() {

    srand(time(0));

    char num[8];
    char buffer[50];
    char hex_numbers[16] = "0123456789abcdef";

    unsigned int i, j;

    FILE *outFile;

    outFile = fopen("outFile.txt", "w");

    for(i = 0; i < 2097152; ++i) {
        memset(num, '\0', 8);
        memset(buffer, '\0', 50);

        for(j = 0; j < 8; ++j) {
            num[j] = hex_numbers[rand() % 16];
        }

        snprintf(buffer, 50, "%d => x\"%s\",\n", i, num);
        fputs(buffer, outFile);
    }

    fclose(outFile);

    return(0);

}