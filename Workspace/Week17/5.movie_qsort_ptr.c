#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_movie {
    double rating;
    char name[64];
    int year;
    int reviews;
};
typedef struct t_movie Movie;
Movie movies[300];

int cmp1(const void *a, const void *b)
{
    Movie *s, *t;
    s = * (Movie**) a;
    t = * (Movie**) b;
    return strcmp(s->name, t->name);
}
int cmp2(const void *a, const void *b)
{
    Movie *s, *t;
    s = * (Movie**) a;
    t = * (Movie**) b;
    if (s->year > t->year) return 1;
    else if (s->year < t->year) return -1;
    else
         return strcmp(s->name, t->name);
}
int cmp3(const void *a, const void *b)
{
    Movie *s, *t;
    s = * (Movie**) a;
    t = * (Movie**) b;
    if (s->rating > t->rating){
         return -1;
    }
    else if (s->rating < t->rating) {
        return 1;
    }
    else {
        if (s->reviews > t->reviews) {
            return -1;
        }
        else if (s->reviews < t->reviews) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void write(char * fname, Movie * pmvs[], int NM)
{
    int i;
    FILE *fout;
    fout = fopen(fname, "w");
    for (i=0; i<NM; i++) {
        fprintf(fout, "%3d: %f\t%s\t(%d)\t%d\n",
               i + 1, pmvs[i]->rating, pmvs[i]->name, pmvs[i]->year, pmvs[i]->reviews);
    }
    fclose(fout);
}

int main(void)
{
    int NM;
    FILE *fin;

    char line[255];
    fin = fopen("imdb_top250.txt", "r");

    Movie *pmovies[300];
    int i;
    for (i=0; i<300; i++) pmovies[i] = &movies[i];

    NM = 0;
    while (!feof(fin) ) {
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].rating = atof(line);
        if (fgets(line, 255, fin)==NULL) break;
        line[strlen(line)-1] = '\0';
        strcpy(movies[NM].name, line);
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].year = atoi(line);
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].reviews = atoi(line);
        NM++;
        if (fgets(line, 255, fin)==NULL) break;
    }
    fclose(fin);


    qsort(pmovies, NM, sizeof(Movie*), cmp1);
    write("sort1.txt", pmovies, NM);

    qsort(pmovies, NM, sizeof(Movie*), cmp2);
    write("sort2.txt", pmovies, NM);

    qsort(pmovies, NM, sizeof(Movie*), cmp3);
    write("sort3.txt", pmovies, NM);


    return 0;
}