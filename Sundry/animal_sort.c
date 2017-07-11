#include <stdio.h>
#define LEN(x) (sizeof(x) / sizeof(x[0]))


struct animal 
{ 	
	char* name;
	int cuteness;
};
// A comparator for integers
static int compare_int(const void* x, const void* y) { 

	return (*(int *) x) - (*(int *) y);
}
// A comparator for animals, in terms of cuteness
static int compare_animal(const void* x, const void* y) { 
	// TODO
}

// Bubble sort
static void bubble_sort(void* base, size_t nmemb, size_t size, int (*compar) (const void*, const void*)) {
// TODO
}
int main(void) {
	int array[] = { 9, 1, 4, 1, 2, 10 }; struct animal animals[] = {
	        { -1, "trout" },
	        { 9, "puppy" },
	        { 10, "kitten"},
	        { -2, "eagle" },
	};
	
	bubble_sort(array, LEN(array), sizeof(array[0]), compare_int); puts("The integers from smallest to largest:");
	
	for (size_t i = 0; i < LEN(array); ++i) {
		printf("%d\n", array[i]);
	}

	bubble_sort(animals, LEN(animals), sizeof(animals[0]), compare_animal); puts("The animals ranked from cutest to least cutest:");
	
	for (size_t i = 0; i < LEN(animals); ++i) {
		printf("%d %s\n", animals[i].cuteness, animals[i].name);
	}
	return 0;
}