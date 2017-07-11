#include "mem_ref.h"
#define MAX 1000
typedef struct ref_node_t node;

struct ref_node_t {
    int count;
    void* ref;

};

node n[MAX];
int counter = 0;

void* new_ref(size_t size, void* dep) {


    if(dep==NULL){

        void* tmp = malloc(size);
        n[counter].ref = tmp;
        n[counter].count = 1;
        counter++;
        return tmp;
    }
    else{
        void* tmp = malloc(size);

        n[counter].ref = tmp;
        n[counter].count = 1;
        counter++;
        return tmp;
    }

}

void* assign_ref(void* ref) {


    int index = 0;
    while(index<counter){
        if(n[index].ref == ref)
            break;
        else
            index++;
    }
    if(index==counter)
        return NULL;

    void* tmp = n[index].ref;
    n[index].count++;
    return tmp;


}
void* del_ref(void* ref) {


    int index = 0;
    while(index<counter){
        if(n[index].ref == ref)
            break;
        else
            index++;
    }
    if(index==counter)
        return NULL;


    n[index].count--;

    if(n[index].count==0){
        free(n[index].ref);
        return NULL;
    }

    return ref;

}

