#include "mem_ref.h"

struct player {
    char* name;
    int rank;
};

void example() {
    struct player* p = new_ref(sizeof(struct player), NULL);
    p->name = new_ref(sizeof(char)*20, p);

    //Do things

    //Extension:
    char* str = assign_ref(p->name);

    //Normal thing
    p = del_ref(p); //removes p gets deallocated, str decrements
    str = del_ref(str); //removes str
}

int main(void){
    example();
    return 0;
}