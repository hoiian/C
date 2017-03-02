#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
	unsigned int data;
	struct Node* next;
};

unsigned int randnum(void);
inline unsigned long long int rdtsc(void);
struct Node* new(unsigned int val);
void insert(struct Node** head, unsigned int val);
struct Node* search(struct Node* head, unsigned int val);
void del(struct Node** head, unsigned int val);
void del_all_node(struct Node* head);

int main(int argc, char* argv[])
{
	int k, n, m;				
	struct Node** seg_tb;
	unsigned int* stack;	
	unsigned int r;	
	int i;			
	unsigned long long int begin, end, result;
	double ave_ins=0, ave_srh=0, ave_del=0;
	struct Node* location;	

	k = atoi(argv[1]);
	n = atoi(argv[2]);
	m = atoi(argv[3]);

	if(k>32) printf("k should be less than 32.\n");

	stack = malloc(sizeof(unsigned int)*m);
	seg_tb = malloc(sizeof(struct Node*)*(2<<k));

	for(i=0;i<(2<<k);i++){
		seg_tb[i]=NULL;
	}

	//******insert	
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		r = randnum();

		if(i < m){
			stack[i]=r;
			begin=rdtsc();
		}

		if(seg_tb[r>>(32-k)]==NULL){
			seg_tb[r>>(32-k)]=new(r);
		}
		else{	// not first time
			insert(&seg_tb[r>>(32-k)],r);
		}

		if(i<m){
			end=rdtsc();
			result=end-begin;
			ave_ins+=result;
		}
	}

	ave_ins=ave_ins/m;

	//*********search
	for(i=0;i<m;i++){
		begin = rdtsc();
		printf("%4d: ",i+1);
		location = search(seg_tb[stack[i]>>(32-k)],stack[i]);
		// error: didn't find it
		if(location == NULL)
			printf("Missing node in SearchNode.\n");

		end = rdtsc();
		result=end-begin;
		ave_srh+=result;
	}
	ave_srh=ave_srh/m;

	//******* delete
	for(i=0;i<m;i++){
		begin=rdtsc();

		del(&seg_tb[stack[i]>>(32-k)],stack[i]);

		end=rdtsc();
		result=end-begin;
		ave_del+=result;
	}
	ave_del=ave_del/m;

	printf("average insert clock cycle: %f\n",ave_ins);
	printf("average search clock cycle: %f\n",ave_srh);
	printf("average delete clock cycle: %f\n",ave_del);

	// free all memory
	for(i=0;i<(2<<k);i++){
		del_all_node(seg_tb[i]);
		seg_tb[i] = NULL;
	}

	return 0;
}

unsigned int randnum(void){
	unsigned int a, r;
	a = rand();
	a = (a&1)<<31;
	r = rand();
	r = r|a;
	return r;
}

inline unsigned long long int rdtsc(void){
	unsigned long long int x;
	asm volatile("rdtsc":"=A"(x));
	return x;
}

struct Node* new(unsigned int val){
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void insert(struct Node** head, unsigned int val){
	struct Node* travel = *head, *prev = NULL;
	struct Node* temp = new(val);

	// travel to find desirable place
	while(travel!=NULL && travel->data < val){
		prev = travel;
		travel = travel->next;
	}

	if(travel == *head){	// replace head to become new head
		temp->next = (*head);
		(*head) = temp;
	}
	else if(travel!=NULL){	// insert in the middle
		temp->next = travel;
		prev->next = temp;
	}
	else{	// insert at the end
		prev->next = temp;
	}

	return;
}

struct Node* search(struct Node* head, unsigned int val){
	struct Node* travel = head;
        FILE *res;
        res = fopen("result.txt", "a");
	
	while(travel!=NULL && travel->data!=val){
		travel = travel->next;
	}
	
	if(travel!=NULL){	// find it!
		printf("%u\n",travel->data);
		fprintf(res,"%u\n",travel -> data); 
		fclose(res);
	}

	return travel;
}

void del(struct Node** head, unsigned int val){
	struct Node* travel=*head, *prev=NULL;
	
	// travel to find object node
	while(travel!=NULL && travel->data!=val){
		prev = travel;
		travel = travel->next;
	}

	// object node is head, need another node to be head
	if(travel==*head){
		*head=(*head)->next;
		free(travel);
	}
	else if(travel!=NULL){	// object node is in the middle of linked list, connect the gap
		prev->next = travel->next;
		free(travel);
	}

	return;
}

void del_all_node(struct Node* head)
{
	struct Node* travel = head;
	
	// travel to delete node
	while(travel!=NULL){
		travel=travel->next;
		free(head);
		head=travel;
	}

	return;
}
