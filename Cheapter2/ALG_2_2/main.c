#include <stdio.h>
#include <stdlib.h>

void printList(int * list, int length){
    int i = 0;
    for(i=0;i<length;i++){
        printf("%d ", list[i]);
    }

    printf("\n");
}

void mergeList(int * list1, int list1Len, int * list2, int list2Len, int * list3){
    int i=0,j=0;
    int k = 0;

    while( (i<list1Len) && (j<list2Len)){
        if( list1[i] <= list2[j] ){
            list3[k] = list1[i];
            i++;
        } else {
            list3[k] = list2[j];
            j++;
        }
        k++;
        printList(list3, 9);
    }

    while( i < list1Len ){
        list3[k] = list1[i];
        i++;
        k++;

        printList(list3, 9);
    }

    while(j < list2Len ){
        list3[k] = list2[j];
        j++;
        k++;

        printList(list3, 9);
    }
}

int main()
{
    int list1[] = {1,2,3,4,5};
    int list2[] = {2,5,8,10};
    int list3[9] = {0};

    mergeList(list1,5,list2,4,list3);
    printList(list3, 9);
    
    return 0;
}
