#include "only_smiths.h"

t_agent *mx_create_agent(char *name, int power, int strength){
    if (name == NULL){
        return NULL;
    }
    t_agent *res = malloc(sizeof(t_agent));
    res->name = mx_strdup(name);
    res->power = power;
    res->strength = strength;

    return res;
}
