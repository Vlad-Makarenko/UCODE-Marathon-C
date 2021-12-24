#include "header.h"

void mx_exterminate_agents(t_agent ***agents){
    for (int i = 0; (*agents)[i] != NULL ; ++i) {
        free( (*agents)[i] -> name);
        free((*agents)[i]);
        //(*agents)[i] = NULL;
    }
    free(**agents);
    **agents = NULL;
}



