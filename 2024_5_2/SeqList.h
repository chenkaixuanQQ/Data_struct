#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


//Define the struct of sequence table
//An interface or method implemented by a sequential list


//Static sequence table
#define N 100
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType arr[N];
	int size;//Represent the actural length of the arr.
}SL_1;


//Dynamic sequence table

typedef int SL_2DataType;

typedef struct SeqList_2
{
	SL_2DataType* arr;
	int capacity;  //Size of SL_2
	int size;      //Number of valid data
}SL;


void CapacityCheck(SL* ps);//Determine whether the capacity is sufficient
void SLPrintInt(const SL* ps);


//Initialization and destroy
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//Add data:
void SLPushBack(SL* ps, SLDataType x);
void SLPushFront(SL* ps, SLDataType x);
void SLInsert(SL* ps, int pos, SLDataType x);


//Delete data
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);
void SLErase(SL* ps, int pos);