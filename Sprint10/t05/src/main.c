#include "header.h"
#include "../inc/header.h"

int main(int argc, char *argv[]){
    int error = errorCheck(argc, argv);
    if (error == -1){
        return 0;
    }


    char *res = mx_file_to_str(argv[2]);
    int resLen = mx_strlen(res);
    int countAgents = 0;
    for (int i = 0; res[i] != '\0'; ++i) {
        if(res[i] == '{') {
            countAgents++;
        }
    }
    t_agent **agents = (t_agent**)malloc(sizeof(t_agent) * (countAgents));

    for (int i = 0; i < countAgents; ++i) {
        agents[i] = (t_agent*)malloc(sizeof (t_agent));
    }


    for (int i = 0; i < countAgents; ++i) {
        res = mx_strstr(res, "name:");
        res += 6;
        int tmp = 0;
        for (int j = 0; res[j] != '\n' ; ++j) {
            tmp++;
        }
        agents[i]->name = mx_strnew(tmp);
        mx_strncpy(agents[i]->name, res, tmp);
        res = mx_strstr(res, "power: ");
        res += 6;
        agents[i]->power = mx_atoi(res);
        res = mx_strstr(res, "strength: ");
        res += 9;
        agents[i]->strength = mx_atoi(res);
    }


    if(mx_strcmp(argv[1], "-p") == 0){
        sortAgentsByPower(agents, countAgents);
    } else if(mx_strcmp(argv[1], "-s") == 0){
        sortAgentsByStrength(agents, countAgents);
    } else {
        sortAgentsByName(agents, countAgents);
    }

    for (int i = 0; i < countAgents; ++i) {
        mx_printstr("agent: ");
        mx_printstr(agents[i]->name);
        mx_printstr(", strength: ");
        mx_printint(agents[i]->strength);
        mx_printstr(", power: ");
        mx_printint(agents[i]->power);
        mx_printchar('\n');
    }



    for (int i = 0; i < countAgents; i++) {
        free(agents[i]->name);
        agents[i]->name = NULL;
        free((agents[i]));
        agents[i] = NULL;

    }

    res -= resLen - mx_strlen(res);
    free(res);
    res = NULL;
    return 0;
}


