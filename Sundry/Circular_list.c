struct node;
typedef struct node* List;

struct node{
	int data;
	node* prev;
	node* next;
}

// Initializes an empty circular linked list
List list_init(node* head){
	head = (node*)malloc(sizeof(struct node));

	head->prev = NULL;
	head->next = NULL;

	return head;
}

// Inserts given node before the head
void list_push(node* head, node* n){

	head->prev = n;
	n->next = head;
}


// Inserts given node after the head
void list_append(node* head, node* n); 

// Removes the given node from the list
void list_delete(node* n);

// Returns whether the list is empty
bool list_empty(node* head);