#include <stdio.h>
#include <stdbool.h>

void printList(int * list, int length){
    int i = 0;
    for(i=0;i<length;i++){
        printf("%d ", list[i]);
    }

    printf("\n");
}

bool exist(int * list, int length, int element){
    int i = 0;
    for(i = 0; i < length; i++){
        if(list[i] == element){
            return true;
        }
    }
    return false;
}

void unionList(int * list1, int list1Len, int * list2, int list2Len,int * list3){
    int i = 0,j = 0;

    for(i = 0; i < list1Len ; i++){
        list3[i] = list1[i];
    }

    for(j = 0; j < list2Len; j++){
        if(exist(list1,list1Len,list2[j]) == false){
            list3[i] = list2[j];
            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int list1[] = {1,2,3,4,5,6,7,8,9,10};
    int list2[] = {100,80,456,3,4,5,6};
    int finalListLen = sizeof(list1)/sizeof(int) + sizeof(list2)/sizeof(int);
    int list3[sizeof(list1)/sizeof(int) + sizeof(list2)/sizeof(int)] = {0};

    unionList(list1,sizeof(list1)/sizeof(int),list2,sizeof(list2)/sizeof(int),list3);
    printList(list3,finalListLen);

    return 0;
}

