#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    if (primeiro >= ultimo)
        return 1;
    
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1])
        return 0;

    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}