#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"


void menu()
{
	printf("***********CONTACT**************\n");
	printf("*********1.ADD  2.POP***********\n");
	printf("*********3.EDIT 4.FIND**********\n");
	printf("*********5.SHOW 0.EXIT**********\n");
	printf("********************************\n");
}

int main()
{
	CSL con;
	ContactInit(&con);//Initialization

	int Option = -1;
	do
	{ 
		menu();//Generate a graphical menu;
		printf("Please enter what you want to do: ");
		scanf("%d", &Option);
		switch(Option)
		{
		case 1:
			//ADD
			ContactAdd(&con);
			break;
		case 2:
			//POP
			ContactPop(&con);
			break;
		case 3:
			//EDIT
			ContactEdit(&con);
			break;
		case 4:
			//FIND A SPECIFIC ONE
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			//VIEW ALL CONTACT
			break;
		case 0:
			//EXIT
			printf("\nProgram exiting.....\n");
			break;
		default:
			printf("Please enter a right number!\n");
			break;
		}
	} while (Option);


	//Contact Destroy
	ContactDestroy(&con);
	return 0;
}


//int main111()
//{
//	struct stu
//	{
//		char name[20];
//		int age;
//	};
//	struct stu s1 = {"zhangsan", 20};
//	struct stu s2 = s1;
//	printf("%s", s2.name);
//}