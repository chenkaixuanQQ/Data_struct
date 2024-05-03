#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define NAME_MAX 20
#define GENDER_MAX 8
#define TEL_MAX 13
#define ADDR_MAX 100


//Define contact informations:
typedef struct PersonalInfo
{
	char name[NAME_MAX];
	int  age;
	char gender[GENDER_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];

}Info;


typedef Info SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	int Capacity;
	int size;
}CSL;




//Contact initial
void ContactInit(CSL* pcont);

void ContactEnter(CSL* pcont, int i);


//ADD、POP、EDTI、FIND、SHOW
void ContactAdd(CSL* pcont);
void ContactPop(CSL* pcont);
void ContactEdit(CSL* pcont);
void ContactFind(CSL* pcont);
void ContactShow(CSL* pcont);




//Destroy the contact.
void ContactDestroy(CSL* pcont);
