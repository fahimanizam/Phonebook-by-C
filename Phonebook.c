#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int dmenu();
void dadd();
void dfind();
void dedit();
void ddel();
void ddisp();

struct dnode {
char dname[20], dtel[15];
struct dnode *dnext;
};
typedef struct dnode node;
node *dstart, *dtemp;

COORD coord={0,0};

 void gotoxy(int x,int y)
 {
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

int dmenu()
{
int dch;
	gotoxy(30,5);
	printf(" PHONE DIRECTORY ");

gotoxy(30,6);
printf(" =================== ");

	gotoxy(30,10);
	printf(" 1. Add ");
	gotoxy(30,11);
	printf(" 2. Find ");
	gotoxy(30,12);
	printf(" 3. Edit ");
	gotoxy(30,13);
	printf(" 4. Delete ");
	gotoxy(30,14);
	printf(" 5. Display All ");
	gotoxy(30,15);
	printf(" 6. EXIT ");
	gotoxy(30,20);
	printf(" Enter your choice(1-6):");
	gotoxy(55,20);
	scanf("%d", &dch);
	return dch;
}
void dadd()
{
	node *dptr,*dprev;
	dtemp=(node *)malloc(sizeof(node));
	printf("\n\t\t------------------------------\n");
	printf("\t\tName: ");
	scanf("%s", dtemp->dname);
	printf("\t\tPhone No.: ");
	scanf("%s", dtemp->dtel);
	dtemp->dnext=NULL;
	if(dstart==NULL) dstart=dtemp;
	else {
 	dprev=dptr=dstart;
 	while(strcmp(dtemp->dname,dptr->dname)>0){
 		dprev=dptr;
 		dptr= dptr->dnext;
	if (dptr == NULL) break;
 	}
		if(dptr==dprev) {
			dtemp->dnext=dstart;
			dstart=dtemp;
}
		else if(dptr==NULL)
			dprev->dnext=dtemp;
		else {
			dtemp->dnext=dptr;
			dprev->dnext=dtemp;
		}
	}
}
void dfind()
 {
	node *dptr;
	char dstr[20];
	if(dstart==NULL) {
		printf("\n\t\t\tPhone Directory is Empty....\n");
getch();
		return;
	}
	printf("Name to Find : ");
	scanf("%s",dstr);
 dptr=dstart;
 while(strcmp(dptr->dname,dstr)!=0){
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL) {
		printf("Name : %s\n",dptr->dname);
		printf("Phone Number : %s\n",dptr->dtel);
	}
	else {
		printf("No Matching Records Found .......\n");
	}
 getch();
}
void dedit()
{
	node *dptr;
	char dstr[20];
	if(dstart==NULL) {
		printf("\n\t\t\tPhone Directory is Empty....\n");
getch();
		return;
	}
	printf("Name to Edit : ");
	scanf("%s",dstr);
 dptr=dstart;
 while(strcmp(dptr->dname,dstr)!=0){
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL) {
		printf("Name : %s", dptr->dname);
		gotoxy(14,19);
		scanf("%s", dptr->dname);
		printf("Phone Number : %s", dptr->dtel);
		gotoxy(16,21);
		scanf("%s", dptr->dtel);
	}
	else {
		printf("No Matching Records Found .......\n");
	}
 getch();
}
void ddel()
 {
	node *dptr,*dprev,*dtemp;
	char dstr[20],dyn='n';
	if(dstart==NULL) {
		printf("\n\t\t\tPhone Directory is Empty....\n");
getch();
		return;
	}
	printf("Name to Delete : ");
	scanf("%s",dstr);
 dprev=dptr=dstart;
 while(strcmp(dptr->dname,dstr)!=0){
 	dprev=dptr;
 	dptr= dptr->dnext;
if (dptr == NULL) break;
 }
	if(dptr!=NULL){
		printf("\nDeleting Record.....Confirm [y/n]: ");
		dyn=getch();
printf("\n\n---------------------------------------------------------");
		printf("\nName : %s\n",dptr->dname);
		printf("Phone Number : %s\n",dptr->dtel);
printf("---------------------------------------------------------");
		if(dyn=='y') {
			if (dptr==dstart) {
				dtemp=dstart->dnext;
				free(dstart);
				dstart=dtemp;
			}
			else {
				dtemp=dptr->dnext;
				free(dptr);
				dprev->dnext=dtemp;
			}
			printf("\n\n1 Record Deleted....");
		}
		else
			printf("\n\nRecord not Deleted....");
	}
	else {
		printf("\nNo Matching Records Found .......");
	}
 getch();
}
void ddisp()
{
	node *dptr;
	if(dstart==NULL) {
		printf("\n\t\t\tPhone Directory is Empty....\n");
getch();
		return;
	}
	system("cls");
	printf("\t\t------------------------------\n");
    for(dptr=dstart; dptr!=NULL; dptr=dptr->dnext) {
    printf("\t\tName: %s", dptr->dname);
    printf("\n\t\tPhone No.: %s", dptr->dtel);
    printf("\n\t\t------------------------------\n");
 }
 getch();
}
void main()
{
	int dch;
	dstart=(node *)malloc(sizeof(node));
	dstart=NULL;
	do{
		system("cls");
		dch=dmenu();
system("cls");
		switch(dch) {
			case 1: dadd();
						break;
			case 2: dfind();
						break;
			case 3: dedit();
						break;
			case 4: ddel();
						break;
			case 5: ddisp();
						break;
	 }
 }while(dch!=6);
}

