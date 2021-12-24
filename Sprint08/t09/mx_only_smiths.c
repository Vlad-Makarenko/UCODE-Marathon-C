#include "only_smiths.h"


t_agent **mx_only_smiths(t_agent **agents, int strength){
    int count = 0;
    for (int i = 0; agents[i] != NULL ; ++i) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength){
            count++;
        }
    }
    t_agent **res = malloc(sizeof(t_agent) * (count + 1));
    int resIdx = 0;
    for (int i = 0; agents[i] != NULL ; ++i) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0 && agents[i]->strength < strength){
            res[resIdx] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
            resIdx++;
        }
    }
    res[count] = NULL;
    return res;
}

