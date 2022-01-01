#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct SeqList
{
    int *data;
    int MaxSize,Length;
};

int main(){
    SeqList a;
    a.data = (int*)malloc(sizeof(int)*InitSize);
    a.MaxSize = 20;
    a.Length = 0;
    for(int i = 0;i<a.MaxSize;i++){
        a.data[i] = i+1;
        printf("%d\n",a.data[i]);
    }
    return 0;
}