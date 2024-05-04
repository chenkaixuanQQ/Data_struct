#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"

//Contact initial.
void ContactInit(CSL* pcont)
{
	pcont->arr = NULL;
	pcont->Capacity = pcont->size = 0;
}
void ContactEnter(CSL* pcont, int i)
{
	int c = 0;
	printf("Please enter name: ");
	c = scanf("%s", pcont->arr[i].name);
	printf("Please enter age: ");
	c = scanf("%d", &pcont->arr[i].age);
	printf("Please enter gender: ");
	c = scanf("%s", pcont->arr[i].gender);
	printf("Please enter phone number: ");
	c = scanf("%s", pcont->arr[i].tel);
	printf("Please enter address: ");
	c = scanf("%s", pcont->arr[i].addr);
}

void ContactAdd(CSL* pcont)
{
	assert(pcont);

	//Determine whether there's enough space:
	if (pcont->size >= pcont->Capacity)
	{
		pcont->Capacity = pcont->Capacity == 0 ? 4 : 2 * pcont->Capacity;
		SLDataType* ps_cpy = (SLDataType*)realloc(pcont->arr, 2 * pcont->Capacity * sizeof(SLDataType));
		assert(ps_cpy);
		pcont->arr = ps_cpy;
		//free(ps_cpy);//Very serious error!!!!!!!
		ps_cpy = NULL;
	}

	int c = 0;
	ContactEnter(pcont, pcont->size);

	pcont->size++;
}
void ContactPop(CSL* pcont)
{
	assert(pcont);

	char name[NAME_MAX];
	printf("Please enter his name who you want to delete: ");
	scanf("%s", name);

	for (int i = 0; i < pcont->size; i++)
	{
		if (strcmp(name, pcont->arr[i].name) == 0)
		{
			for (int j = i; j < pcont->size - 1; j++)
			{
				pcont->arr[j] = pcont->arr[j + 1];
			}
			pcont->size--;
			return;
		}
	}
	printf("I'm so sorry that we don't have any information on that person.");
}
void ContactEdit(CSL* pcont)
{
	assert(pcont);

	char name[NAME_MAX];

	printf("Please enter the name that you wanna check: ");
	scanf("%s", name);

	for (int i = 0; i < pcont->size; i++)
	{
		if (strcmp(name, pcont->arr[i].name) == 0)
		{
			ContactEnter(pcont, i);
			return;
		}
	}
	printf("I'm so sorry that we can't find him, so we couldn't edit his massage.");
}
void ContactFind(CSL* pcont)
{
	assert(pcont);

	char name[NAME_MAX];
	printf("Please enter the name you wanna check: ");
	scanf("%s", name);
	for (int i = 0; i < pcont->size; i++)
	{
		if (strcmp(name, pcont->arr[i].name) == 0)
		{
			printf("Find successfully! His massage as follows:\n");
			printf("NAME     AGE   GENDER    PHONE_NUMBER   ADDRESS\n");
			printf("%s", pcont->arr[i].name);
			printf("%d", pcont->arr[i].age);
			printf("%s", pcont->arr[i].gender);
			printf("%s", pcont->arr[i].tel);
			printf("%s\n", pcont->arr[i].addr);
			return;
		}
	}
	printf("I'm so sorry that we can't find him");
}
void ContactShow(CSL* pcont)
{
	assert(pcont);
	printf("NAME     AGE   GENDER    PHONE_NUMBER   ADDRESS\n");
	for (int i = 0; i < pcont->size; i++)
	{
		printf("%s", pcont->arr[i].name);
		printf("%d", pcont->arr[i].age);
		printf("%s", pcont->arr[i].gender);
		printf("%s", pcont->arr[i].tel);
		printf("%s\n", pcont->arr[i].addr);
	}
}



//Contact destroy.
void ContactDestroy(CSL* pcont)
{
	assert(pcont);
	free(pcont->arr);
	pcont->arr = NULL;
	pcont->Capacity = pcont->size = 0;
}