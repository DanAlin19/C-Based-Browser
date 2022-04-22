#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void citire(site *v, int i) {
    i = 0;
    FILE *f, *fp;
    char a[100], linie[100];
    if((f = fopen("master.txt","rt")) == NULL) 
        exit(1);
    while(fscanf(f,"%s",a) != EOF) {
        fp = fopen(a,"rt");
        fscanf(fp,"%s",v[i].link);
        fscanf(fp,"%d",&v[i].lungime);
        fscanf(fp,"%d",&v[i].nr_accesari);
        fscanf(fp,"%d",&v[i].checksum);
        v[i].site_code = (char*)malloc(v[i].lungime * sizeof(char));
        v[i].paragraf = (char*)malloc(v[i].lungime * sizeof(char));
        while(fgets(linie,100,fp) != NULL) {
            linie[strcspn(linie,"\n")] = 0;
            strcat(v[i].site_code,linie);
            if(strstr(linie,"<title>") != 0) {
                strcpy(v[i].titlu,linie + strlen("<title>"));
                v[i].titlu[strlen(v[i].titlu) - strlen("</title>")] = '\0';
            }
        }
        const char *parag_1 = "<p";
        const char *parag_2 = "</p>";
        char *start, *end;
        start = strstr(v[i].site_code,parag_1);
        end = strstr(start,parag_2);
        v[i].paragraf = (char *)malloc(end - start + 1);
        memcpy(v[i].paragraf,start,end - start + strlen(parag_2));
        v[i].paragraf[start - end] = '\0';
        i++;
    }
    fclose(f);
    fclose(fp);
}

int marime (site *v) {
    FILE *f;
    int i = 0;
    char a[100];
    int marime = 3;
    if((f = fopen("master.txt","rt")) == NULL) 
        exit(1);
    while(fscanf(f,"%s",a) != EOF) {
        if(i == marime) {
            marime += 3;
            v = realloc(v, marime * sizeof(site));
        }
        i++;
    }
    fclose(f);
    return i;
    
}
