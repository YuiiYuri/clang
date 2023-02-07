#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nums = 0;
typedef struct students{
    char name[100];
    char SID[10];
    char SBP[10];
} students;

typedef struct student_list{
    students str;
    struct student_list *next;
} student_list;

student_list *root, *curr;

void addNode(){
	student_list *newNode;
	students addr;
	newNode = (student_list *)malloc(sizeof(student_list));
	while(getchar()!='\n');
	printf("Nhap thong tin sinh vien: \n");
	printf("Nhap ten: \n");
	fgets(addr.name,20,stdin);
	addr.name[strlen(addr.name)-1]='\0';
	printf("Nhap ma so sinh vien: \n");
	scanf("%s", addr.SID);
	printf("Nhap diem: \n");
	scanf("%s", addr.SBP);
	newNode->str = addr;
	newNode->next = NULL;
	if(root==NULL){
		root=newNode;
		curr=root;
	}
	else{
		curr->next = newNode;
		curr = newNode;
	}		
}

void display(){
	student_list *curNode;
	curNode = (student_list *)malloc(sizeof(student_list));
	curNode = root;
	printf("Danh sach sinh vien: \n");
    printf("Ten                  MaSoSinhVien         Diem\n");
	while(curNode!=NULL){
		printf("%-20s %-20s %-25s\n",curNode->str.name, curNode->str.SID, curNode->str.SBP);
		curNode = curNode ->next;
	}
}

void deleteAll(){
	student_list *curNode;
	curNode = (student_list *)malloc(sizeof(student_list));
	while(root!=NULL){
		curNode = root;
		root = root->next;
		free(curNode);					
	}
	printf("Da xoa toan bo list:\n");
}

void readfile(){
	FILE *f;
    f = fopen("assi3input.txt", "r");
    if (f == NULL) {
        printf("file can't be opened \n");
    }
    while(!feof(f)){
        student_list *newNode;
	    students addr;
	    newNode = (student_list *)malloc(sizeof(student_list));
        fscanf(f, "%s %s %s\n", addr.name, addr.SID, addr.SBP);
		nums++;
        newNode->str = addr;
	    newNode->next = NULL;
	    if(root==NULL){
		    root=newNode;
		    curr=root;
	    }
	    else{
		    curr->next = newNode;
		    curr = newNode;
	    }		
    }
    fclose(f);
}
/*
void writefile(){
	FILE *f;
    f = fopen("assi3input.txt", "a");
    if (f == NULL) {
        printf("file can't be opened \n");
    }
	student_list *curNode;
	curNode = (student_list *)malloc(sizeof(student_list));
	curNode = root;
	while(curNode!=NULL){
			fprintf(f,"%s %s %s\n",curNode->str.name, curNode->str.SID, curNode->str.SBP);
		    curNode = curNode ->next;	
	}
	fclose(f);
}
*/
void addfile(){
	student_list *newNode;
	students addr;
	newNode = (student_list *)malloc(sizeof(student_list));
	while(getchar()!='\n');
	printf("Nhap thong tin sinh vien: \n");
	printf("Nhap ten: \n");
	fgets(addr.name,20,stdin);
	addr.name[strlen(addr.name)-1]='\0';
	printf("Nhap ma so sinh vien: \n");
	scanf("%s", addr.SID);
	printf("Nhap diem: \n");
	scanf("%s", addr.SBP);
	FILE *f;
    f = fopen("assi3input.txt", "a");
    if (f == NULL) {
        printf("file can't be opened \n");
    }
	fprintf(f,"%s %s %s\n",addr.name, addr.SID, addr.SBP);
	fclose(f);
	nums++;
	newNode->str = addr;
	newNode->next = NULL;
	if(root==NULL){
		root=newNode;
		curr=root;
	}
	else{
		curr->next = newNode;
		curr = newNode;
	}		
}

int main(void){
	int i, n;
	int key;
	root = NULL;
	do {
		instruction();
		printf("enter your choice:\n");
		scanf("%d",&key);
		switch(key){
			case 1:
			readfile();
			break;
			case 2:
			addfile();
			break;
			case 3:
			display();
			//printf("%d\n", nums);
			break;
			case 4:
			searchinfile();
			break;
		}
	}
	while(key!=0);
    deleteAll();
	return 0;
}

int instruction(){
	printf("==========================================\n");
    printf("Danh sach thao tac:\n");
    printf("1.INSERT FILE:\n");
    printf("2.ADD FILE:\n");
    printf("3.Display:\n");
    //printf("4.PRINT FILE\n");
	printf("4.SEARCH BY NAME\n");
    printf("0.EXIT\n");
	printf("==========================================\n");
}

void searchinfile(){
	FILE *f;
    f = fopen("assi3input.txt", "r");
    if (f == NULL) {
        printf("file can't be opened \n");
    }
	FILE *fo;
    fo = fopen("assi3output.txt", "w");
    if (fo == NULL) {
        printf("file can't be opened \n");
    }
	char searchname[100];
	char name[100];
	char SID[10];
	char SBP[10];
	printf("ENTER A NAME:\n");
	scanf("%s", searchname);
	//printf("%s", searchname);
	//printf("\n");
	//fscanf(f, "%s %s %s\n", name, SID, SBP);
	//printf("%s", name);
	int found = 0;
	while(!feof(f)){
		fscanf(f, "%s %s %s\n", name, SID, SBP);
		if(strcmp(searchname, name) == 0){
			printf("%s %s %s\n", name, SID, SBP);
			fprintf(fo, "%s %s %s\n", name, SID, SBP);
			found = 1;
			break;
	    }
    }
	if(found == 0){
		printf("NOT FOUND\n");
	}
	fclose(f);
	fclose(fo);
}