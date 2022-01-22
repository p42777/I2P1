#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    MAX_LEN = 60,
    NUM_WORDS = 120000
};

int lookup(char word[], char *dict[], int nwords);

int main(void)
{
    char **p, buf[MAX_LEN + 1];
    int i, j;
    FILE *fin;

    fin = fopen("words.txt", "r");
    p = (char **) malloc(sizeof(char *)* NUM_WORDS);
    i = 0;
    while(i< NUM_WORDS && (fgets(buf, MAX_LEN + 1, fin) != NULL)) {
        buf[strlen(buf) - 1] =  '\0';
        p[i] = malloc(strlen(buf)+1);
        if (p[i] != NULL) {
            strcpy(p[i], buf);
            i++;
        }
    }
    fclose(fin);

    while(fgets(buf, MAX_LEN + 1, stdin) != NULL) {
        buf[strlen(buf)-1] = '\0';
        j = lookup(buf, p, i);
        while (j >= 0) {
            if (strncmp(p[j], buf, strlen(buf))!=0) {
                j++;
                break;
            }
            j--;
        }
        if (j < 0) j = 0;
        while (j<i) {
            if (strncmp(p[j], buf, strlen(buf))!=0)
                break;
            printf("%s\n", p[j]);
            j++;
        }
    }

    for (j = 0 ; j < i ; j++) {
        free(p[j]);
    }
    free(p);

    return 0;
}

int lookup(char *word, char *dict[], int nwords)
{
    int  low, high, mid, cmp;
    low = mid = 0;
    high = nwords - 1;
    while (low <= high) {
        mid = low + (high - low)/2;
        cmp = strcmp(word, dict[mid]);
        if (cmp < 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else
            break;
    }
    return mid;
}

//也可以直接使用 bsearch 函數