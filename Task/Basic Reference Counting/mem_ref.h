#ifndef MEM_REF_H
#define MEM_REF_H
#include <stdlib.h>

void* new_ref(size_t size, void* dep);
void* assign_ref(void* ref);
void* del_ref(void* ref);

#endif
