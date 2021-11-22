/*
讀取 imdb_top250.txt 檔案
裡面包含了 250 筆電影資料
每一筆資料包含四個項目
分別是 平均評分、電影名稱、上映年份、參與評分的網友數目
每一筆資料之間用空行隔開

利用 qsort() 將資料以不同原則重新排列 

(a) 依照電影名稱的英文字母順序
(b) 依照上映年份排序，從早期到近期，如果年份相同，則再依照電影名稱的英文字母順序排序
(c)  依照平均評分的高低排序，由高到低，如果評分相同，則再依照參與評分的網友數量排序

將 (a) (b) (c) 的排序結果 分別輸出為 sort1.txt, sort2.txt, sort3.txt
*/

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
    s = (Movie*) a;
    t = (Movie*) b;
    return strcmp(s->name, t->name);
}
int cmp2(const void *a, const void *b)
{
    Movie *s, *t;
    s = (Movie*) a;
    t = (Movie*) b;
    if (s->year > t->year) return 1;
    else if (s->year < t->year) return -1;
    else
         return strcmp(s->name, t->name);
}
int cmp3(const void *a, const void *b)
{
    Movie *s, *t;
    s = (Movie*) a;
    t = (Movie*) b;
    if (s->rating > t->rating) return -1;
    else if (s->rating < t->rating) return 1;
    else {
        if (s->reviews > t->reviews) return -1;
        else if (s->reviews < t->reviews) return 1;
        else return 0;
    }
}

void write(char * fname, Movie *mvs, int NM)
{
    int i;
    FILE *fout;
    fout = fopen(fname, "w");
    for (i=0; i<NM; i++) {
        fprintf(fout, "%3d: %f\t%s\t(%d)\t%d\n",
               i+1, mvs[i].rating, mvs[i].name, mvs[i].year, mvs[i].reviews);
    }
    fclose(fout);
}

int main(void)
{
    int NM;
    FILE *fin;

    char line[255];
    fin = fopen("imdb_top250.txt", "r");

    NM = 0;
    while (!feof(fin) ) {
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].rating = atof(line);
        if (fgets(line, 255, fin)==NULL) break;
        strcpy(movies[NM].name, line);
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].year = atoi(line);
        if (fgets(line, 255, fin)==NULL) break;
        movies[NM].reviews = atoi(line);
        NM++;
        if (fgets(line, 255, fin)==NULL) break;
    }
    fclose(fin);
/*
    for (i=0; i<NM; i++) {
        printf("%3d: %f\t%s\t(%d)\t%d\n",
               i+1, movies[i].rating, movies[i].name, movies[i].year, movies[i].reviews);
    }
*/
    qsort(movies, NM, sizeof(Movie), cmp1);
    write("sort1.txt", movies, NM);

    qsort(movies, NM, sizeof(Movie), cmp2);
    write("sort2.txt", movies, NM);

    qsort(movies, NM, sizeof(Movie), cmp3);
    write("sort3.txt", movies, NM);


    return 0;
}