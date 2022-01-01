# include <stdio.h>
# include <stdlib.h>

#define MaxSize 10
typedef struct SqList
{
    int data[MaxSize];
    int Length;
};

bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.Length)
        return false;
    if(L.Length>=MaxSize)
        return false;
    for(int j = L.Length;j>=i;j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.Length++;
    return true;
}

bool ListDelete(SqList &L,int i,int &e){
    if(i>L.Length||i<1)
        return false;
    e = L.data[i-1];
    for(int j = i-1;j<L.Length-1;j++)
        L.data[j] = L.data[j+1];
    L.Length--;
    return true;
}

int main(){
    SqList L;
    L.Length = 0;
    for(int i = 0;i<MaxSize - 1;i++){
        L.data[i] = i+1;
        L.Length++;
    }
    for(int i = 0;i<L.Length;i++)
        printf("%d\n",L.data[i]);
    ListInsert(L,2,10);
    for(int i = 0;i<L.Length;i++)
        printf("%d\n",L.data[i]);
    int e;
    ListDelete(L,2,e);
    for(int i = 0;i<L.Length;i++)
        printf("%d\n",L.data[i]);
        printf("%d",e);
    return 0;
}