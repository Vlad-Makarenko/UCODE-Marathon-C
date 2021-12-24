#include "../inc/header.h"

int errorCheck(int argc, char *argv[]){
    if (argc != 3){
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        return -1;
    }

    if(mx_strcmp(argv[1], "-p") != 0
       && mx_strcmp(argv[1], "-s") != 0
       && mx_strcmp(argv[1], "-n") != 0){
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        return -1;
    }

    char *fileStr = mx_file_to_str(argv[2]);
    if (fileStr == NULL){
        mx_printerr("error\n");
        return -1;
    }

    int countRBrace = 0;
    int countLBrace = 0;
    int countName = mx_count_substr(fileStr, "name:");
    int countPower = mx_count_substr(fileStr, "power:");
    int countStrength = mx_count_substr(fileStr, "strength:");
    int countAgent = mx_count_substr(fileStr, "agent");


    for (int i = 0; fileStr[i] != '\0' ; ++i) {
        if (fileStr[i] == '{'){
            countLBrace++;
        }
        if (fileStr[i] == '}'){
            countRBrace++;
        }
    }

    if (countLBrace != countRBrace){
        mx_printerr("error\n");
        return -1;
    }
    if (countName != countPower
        || countName != countStrength
        || countPower != countStrength
        || countAgent != countName
        || countAgent != countStrength
        || countAgent != countPower
        || countStrength == 0
        || countPower == 0
        || countName == 0){
        mx_printerr("error\n");
        return -1;
    }

    free(fileStr);
    fileStr = NULL;

    return 0;
}

