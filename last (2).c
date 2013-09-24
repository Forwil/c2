#include <stdio.h>

#define MAXLEN 90 
#define MAXLINES 5000

char *lineptr[MAXLINES];
char *alloc(int);

int getlines(char *s,int lim)
{
    int c,i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int strlen(char *s)
{
    int n;
     
    for (n=0; *s != '\0'; s++)
        n++;
    return n;
}

void strcpys(char *s, char *t)
{
    int i;

    i=0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void qsort(char *v[], int left, int right)
{
    void swaps(char *v[],int s);
    int j, i;
    for (j = left; j <= right; j++) {
      for (i = left; i <= right-j+2; i++)
         if (strlen(v[i]) > strlen(v[i+1]))
             swaps(v, i);
    }
}

int readlines(char *lineptr[],int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len=getlines(line, MAXLEN))>0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpys(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[],int nlines)
{
    int x=nlines,i;
    if (nlines <= 20){
      for (i = 0; i < nlines; i++)
          printf("%s\n", lineptr[i]);
    }
    else {
      i=x-20;
      for (i = x-20; i < nlines; i++)
          printf("%s\n", lineptr[i]);
    }
}

void swaps(char *v[], int s)
{
    char *temp;
    
    temp = v[s];
    v[s] = v[s+1];
    v[s+1] = temp;
}

main()
{
    int nlines;
 
    if ((nlines = readlines(lineptr,MAXLINES)) >= 0) {
      
        writelines(lineptr,nlines);
        printf("\n");
        if (nlines > 20) {
            qsort(lineptr, nlines-20, nlines-1);
            writelines(lineptr, nlines);
        } else {
            qsort(lineptr, 0, nlines-1);
            writelines(lineptr, nlines);        
          }
    } else {
        printf("error: input too big too sort\n");
        return 1;
  
}
}
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}
