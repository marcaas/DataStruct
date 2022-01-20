#include"SqList.h"

//「练习1」从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值.空出的位置由最后一个元素填补,若顺序表为空,则显示出错信息并退出运行.
int practice_1(SqList &L){
    if (Empty(L)==0)                            //判空
        printf("空表\n");
        return 0;
    int ans = L.data[0];                        //设置返回值为表中第一个元素
    int loc;                                    //设置返回值的位置
    for(int i=1;i<L.Length;i++){                //遍历表并找出最小值
        if(L.data[i]<L.data[i-1]){
            ans = L.data[i];
        }
    }
    loc = LocateElem(L,ans);                    //找到该最小值的位置
    L.data[loc-1] = L.data[L.Length-1];         //用表尾元素替代最小元素以实现删除和填补的操作
    return ans;                                 //返回删除的值
}
//「练习2」设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）。
bool practice_2(SqList &L){
    if(L.Length == 0||L.Length == 1)            //若表长为0或1则逆置后不变
        return true;
    int a;                                      //使用一个空间复杂度用于逆置时值的存储
    for(int i=1;i<=L.Length/2;i++){             //遍历前半个表，将对称的两个元素交换位置
        a = L.data[i-1];
        L.data[i-1] = L.data[L.Length-i];
        L.data[L.Length-i] = a;
    }
    return true;
}
//测试
int main(){
    SqList L;
    for(int i = 1;i<=MaxSize;i++){
        ListInsert(L,i,i);
    }
    practice_2(L);
    PrintList(L);
    return 0;
}