# include <stdio.h>
# include <stdlib.h>
// 静态分配顺序表定义
#define MaxSize 10
typedef struct SqList
{
    int data[MaxSize];
    int Length;
};
// 插入操作
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
// 删除操作
bool ListDelete(SqList &L,int i,int &e){
    if(i>L.Length||i<1)
        return false;
    e = L.data[i-1];
    for(int j = i-1;j<L.Length-1;j++)
        L.data[j] = L.data[j+1];
    L.Length--;
    return true;
}
// 按值查找操作
int LocateElem(SqList L,int e){
    for(int i = 0;i<L.Length;i++)
        if(L.data[i] == e)
            return i+1;
    return 0;
}
//按位查找
int GetElem(SqList L,int i){
    if(i<1||i>L.Length){
        printf("输入位置不合法");
        return 0;
    }
    return L.data[i-1];
}
//测试
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
    printf("%d\n",e);
    int ans = LocateElem(L,2);
    printf("%d\n",ans);
    ans = GetElem(L,9);
    printf("%d\n",ans);
    return 0;
}