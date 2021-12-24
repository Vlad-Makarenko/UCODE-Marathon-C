#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count){
    if (*name == NULL || power == NULL || strength == NULL){
        return NULL;
    }
    t_agent **res = malloc(sizeof (t_agent ) * (count + 1));
    for (int i = 0; i < count; ++i) {
        res[i] = mx_create_agent(name[i], power[i], strength[i]);
    }
    res[count] = NULL;
    return res;
}


