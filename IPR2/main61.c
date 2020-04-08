#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char s[20],c[5]="65535";
	int i;
	printf("������� ����ࠫ쭮� ������筮� ��᫮:\n");
	scanf("%20s",&s);
	for (i=0;s[i]!='\0';i++)
	{
		if((s[i]<'0')||(s[i]>'9'))
		{
			printf("�����४���� ����\n");
			system("pause");
			return 0;
		}
	}
	if(i>5)
	{
		printf("��᫮ ������ �।�⠢��� � ��ଠ�� unsigned short int\n");
		system("pause");
		return 0;
	}
	else if (i<5)
	{
		printf("��᫮ ����� �।�⠢��� � ��ଠ�� unsigned short int\n");
		system("pause");
		return 0;
	}
	else for (i=-2;i<2;i++)
	{
		if (s[i]>c[i])
		{
			printf("��᫮ ������ �।�⠢��� � ��ଠ�� unsigned short int\n");
			break;
		}
		else if (s[i]<c[i])
		{
			printf("��᫮ ����� �।�⠢��� � ��ଠ�� unsigned short int\n");
			break;
		}
	}
	if(i==5) printf("��᫮ ����� �।�⠢��� � ��ଠ�� unsigned short int\n");
	system("pause");
	return 0;
}
