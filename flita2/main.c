#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define NUM 100

FILE *file1, *file2;

int32_t main(void)
{
    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.dot", "w");
    fprintf(file2, "digraph graph1 {\n");
    int8_t str[NUM];
    if (file1 != NULL)
        while (fgets(str,NUM, file1) != NULL)
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == ' ') {
                    fputs("->", file2);
                } else {
                    fputc(str[i], file2);
                }
            }
    fprintf(file2, "\n}\n");
    fclose(file1);
    fclose(file2);
    puts("graph is successfully created!\n");
    system("dot -Tpng -O file2.dot");
    return 0;
}
