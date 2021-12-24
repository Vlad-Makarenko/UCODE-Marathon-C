#include "header.h"

bool compareName(char *name1, char *name2){
    return mx_strcmp(name1, name2) > 0;
}

bool compareNum(int a, int b){
    return a > b;
}

void sortAgentsByStrength (t_agent **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (compareNum(arr[j]->strength, arr[j + 1]->strength)) {
                t_agent *buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
            }
        }
    }
}

void sortAgentsByPower(t_agent **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (compareNum(arr[j]->power, arr[j + 1]->power)) {
                t_agent *buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
            }
        }
    }
}

void sortAgentsByName(t_agent **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (compareName(arr[j]->name, arr[j + 1]->name)) {
                t_agent *buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
            }
        }
    }
}

