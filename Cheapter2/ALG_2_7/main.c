#include <stdio.h>
#include <stdlib.h>

void printList(int * list, int length){
    int i = 0;
    for(i=0;i<length;i++){
        printf("%d ", list[i]);
    }

    printf("\n");
}

int main()
{
    int list1[] = {1,2,3,4,5,6};
    int list2[] = {3,6,8,9,10};

    int len1 = sizeof(list1)/sizeof(int);
    int len2 = sizeof(list2)/sizeof(int);

    int * list3 = (int *)malloc((len1+len2) * sizeof(int));
    int * pList3 = list3;

    int * pList1 = list1, * pList2 = list2;
    int * list1Last = pList1 + len1 - 1;
    int * list2Last = pList2 + len2 - 1;

    while( (pList1 <= list1Last) && (pList2 <= list2Last)){
        if( * pList1 < * pList2 ){
            * pList3 ++ = * pList1 ++;
        }else {
            * pList3 ++ = * pList2 ++;
        }
    }

    while( pList1 <= list1Last ){
        * pList3 ++ = * pList1 ++;
    }

    while( pList2 <= list2Last ){
        * pList3 ++ = * pList2 ++;
    }
    
    printList(list3, len1 + len2);

    return 0;
}

