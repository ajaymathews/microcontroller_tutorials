#include<stdio.h>
#include<string.h>
/*
struct grand
{
	char granddad[10];
	char grandmom[10];
}old;

struct child
{
	char son[10];
	char daughter[10];
}teen;

struct parent
{
	char dad[10];
	char mom[10];
	struct child teen;
	struct grand old;	
}home;
void main()
{
	printf("grand:");
	gets(home.old.granddad);
	puts(home.old.granddad);
	
	printf("\nParent:");
	gets(home.dad);
	puts(home.dad);
}
*/
typedef struct grand
{
	char granddad[10];
	char grandmom[10];
}old;

typedef struct child
{
	char son[10];
	char daughter[10];
}teen;

typedef struct parent
{
	char dad[10];
	char mom[10];
	teen pub;
	old aged;	
}home;
void main()
{
	/********1st method***********/
	/*
	printf("grand:");
	gets(home.aged.granddad);
	puts(home.aged.granddad);
	
	printf("\nParent:");
	gets(home.dad);
	puts(home.dad);
	*/
	
	/*********2nd method*********/
	home me={"dad","mom",{"son","daught"},{"grand","grany"}};
	puts(me.dad);
	puts(me.mom);
	puts(me.pub.son);
	puts(me.pub.daughter);
	puts(me.aged.granddad);
	puts(me.aged.grandmom);
	
}

