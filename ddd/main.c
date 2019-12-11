#include <stdio.h>
#include <stdlib.h>
typedef enum{Hefa,Delete,Empty}Hw;
struct TNode
{
    int Data;
    Hw Info;
};
struct HNode
{
    int TableSize;
    struct TNode *Cells;
};
int Hash(int key,int num)
{
    return key%num;
}
struct HNode *create(int n)
{
    struct HNode *H;
    H=(struct HNode *)malloc(sizeof(struct HNode));
    H->TableSize=n;
    H->Cells=(struct TNode*)malloc(H->TableSize*sizeof(struct TNode));
    for(int i=0;i<H->TableSize;i++)
    {
        H->Cells[i].Info=Empty;
    }
    return H;
}
int find(struct HNode *H,int key)
{
    int index,tmp;
    index=tmp=Hash(key,H->TableSize);
    while(H->Cells[index].Info!=Empty&&H->Cells[index].Data!=key)
    {
        index++;
        if(index>=H->TableSize)
        {
            index=index%H->TableSize;
        }
        if(index==tmp)
        {
            break;
        }
    }
    if(H->Cells[index].Info==Empty||H->Cells[index].Data==key)
    {
        return index;
    }
    else
    {
        return -1;
    }
}
int i;
void insert(struct HNode *H,int key)
{
    int index=find(H,key);
    if(H->Cells[index].Info!=Hefa)
    {
        if(i==0)
        {
            printf("%d",index);
            i++;
        }
        else
        {
            printf(" %d",index);
        }
        H->Cells[index].Data=key;
        H->Cells[index].Info=Hefa;
    }
    else
    {
        if(i==0)
        {
            printf("%d",index);
            i++;
        }
        else
        {
            printf(" %d",index);
        }
    }
}
int main()
{
    int n;int P;
    scanf("%d %d",&n,&P);
    struct HNode *H;
    H=create(P);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(H,x);
    }
    return 0;
}
