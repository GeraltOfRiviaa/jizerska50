#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SOUBOR "jizerska50.txt"
#define DEL "; ():"

typedef struct {
    int hod;
    int min;
    int sec;
} CAS;

typedef struct {
    int start;
    char prijmeni[50];
    char jmeno[50];
    int rocnik;
    char narod[50];
    CAS cas;
} DATA;

DATA *cteniSouboru(int *pocet, DATA *data) {
    FILE *f = NULL;
    char *temp;
    char lajna[100];
    int i = 0;


    f = fopen(SOUBOR, "r");

    if (f == NULL) {
        printf("Nastal problem pri otevirani souboru %s\n", SOUBOR);
    }

    fgets(lajna, 100, f);
    while (fgets(lajna, 100, f)) {
        data = (DATA *) realloc(data, (*pocet + 1) * sizeof(DATA));
        i = 0;
        temp = strtok(lajna, DEL);
        while (temp != NULL) {
            switch (i) {
                case 0:
                    data[*pocet].start = atoi(temp);
                    break;
                case 1:
                    strcpy(data[*pocet].prijmeni, temp);
                    break;
                case 2:
                    strcpy(data[*pocet].jmeno, temp);
                    break;
                case 3:
                    data[*pocet].rocnik = atoi(temp);
                    break;
                case 4:
                    strcpy(data[*pocet].narod, temp);
                    break;
                case 5:
                    data[*pocet].cas.hod = atoi(temp);
                    break;
                case 6:
                    data[*pocet].cas.min = atoi(temp);
                    break;
                case 7:
                    data[*pocet].cas.sec = atoi(temp);
                    break;
            }
            temp = strtok(NULL, DEL);
            i++;
        }


        (*pocet)++;
    }

    fclose(f);

    return data;
}

int main(void) {
    int pocet = 0;
    DATA *dejta = NULL;
    dejta = cteniSouboru(&pocet, dejta);

    printf("%d", dejta[10].rocnik);
    return 0;
}
