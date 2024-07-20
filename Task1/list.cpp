#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "list.h"

void StringListInit(char** &list) {
    list = (char**)malloc(sizeof(char*));
    list[0] = NULL;
}

void StringListDestroy(char** &list) {
    for (size_t i = 0; list[i] !=NULL; i++){
        free(list[i]);
    }
    free(list);
    list = NULL;
}

void StringListAdd(char** &list, const char* str) {
    int size = StringListSize(list);
    list = (char**)realloc(list, sizeof(char*) * (size + 2));
    list[size] = (char*)malloc(strlen(str) + 1);
    strcpy(list[size], str);
    list[size + 1] = NULL;
}

void StringListRemove(char** &list, const char* str){
    size_t i = 0, j = 0;
    while(list[i] != NULL){
        if (strcmp(list[i], str) == 0) {
            free(list[i]);
        } else {
            list[j++] = list[i];
        }
        i++;
    }
    list[j] = NULL;
    list = (char**)realloc(list, sizeof(char*) * (j + 1));
}

int StringListSize(char** list) {
    int size = 0;
    while(list[size]!=NULL) {
        size++;
    }
    return size;
}

int StringListIndexOf(char** list, char* str) {
    for (int i = 0; list[i] != NULL; i++){
        if (strcmp(list[i], str) == 0) {
            return i;
        }
    }
    return -1;
}

void StringListRemoveDuplicates(char** list){
    int size = StringListSize(list);
    for (size_t i = 0; i < size; i++){
        size_t k = i + 1, j = i + 1;
        while (list[j] != NULL){
            if (strcmp(list[i], list[j]) == 0){
                free(list[j]);
                size--;
            } else {
                list[k] = list[j];
                k++;
            }
            j++;
        }
        list[size] = NULL;
    }
    list = (char**)realloc(list, sizeof(char*) * (size + 1));
    list[size] = NULL;
}

void StringListReplaceInStrings(char** &list, const char* before, const char* after){
    for(int i = 0; list[i] != NULL; i++){
        char* ptr = list[i];
        while((ptr = strstr(ptr, before)) != NULL){
            int pos = ptr - list[i];
            int before_len = strlen(before);
            int after_len = strlen(after);
            int tail_len = strlen(ptr + before_len);
            char* tail = (char*)malloc(tail_len + 1);
            strcpy(tail, ptr + before_len);
            list[i] = (char*)realloc(list[i], strlen(list[i]) - before_len + after_len + 1);
            ptr = list[i] + pos;
            strcpy(ptr, after);
            strcpy(ptr + after_len, tail);
            free(tail);
            ptr += after_len;
        }
    }
}

void mergeSort(char** list, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char** leftArr = (char**) malloc(sizeof(char*) * (n1 + 1));
    char** rightArr = (char**) malloc(sizeof(char*) * (n2 + 1));

    for (int i = 0; i < n1; i++) {
        leftArr[i] = list[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = list[mid + 1 + j];
    }

    leftArr[n1] = NULL;
    rightArr[n2] = NULL;

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(leftArr[i], rightArr[j]) <= 0) {
            list[k] = leftArr[i];
            i++;
        } else {
            list[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void ListSort(char** list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ListSort(list, left, mid);
        ListSort(list, mid + 1, right);
        mergeSort(list, left, mid, right);
    }
}

void StringListSort(char** list) {
    int size = StringListSize(list);
    ListSort(list, 0, size - 1);
}
