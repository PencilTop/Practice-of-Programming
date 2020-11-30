#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fin, *fout;
    int c;
    if (argc != 3) {
        printf("Usage: cp input output\n");
    }
    else if ((fin = fopen(argv[1], "r")) == NULL) {
        printf("can't open input file %s", argv[1]);
    }
    else if ((fout = fopen(argv[2], "w")) == NULL) {
        printf("can't open output file %s", argv[2]);
        fclose(fin);
    } else {
        while ((c = getc(fin)) != EOF) 
            putc(c, fout);
        fclose(fin);
        fclose(fout);
    }
    return 0;
}