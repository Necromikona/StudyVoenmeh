/*Даны две строки. Составить третью строку из слов, имеющихся в обеих данных
строках.*/

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main (){
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	
	char strIn1[200],strIn2[200],strOut[200],buff[200] , sps =' ';
	int flag  = 0, count = 0, sr = 0;
	char *pIn1 = strIn1,*pIn2 = strIn2, *pOut = strOut, *pbuff1 = strIn1, *pbuff2 = strIn2, *pSR;

	memset(strOut,'\0',sizeof(strOut));
	memset(buff,'\0',sizeof(buff));
	printf("������� ������  ������ ��������\n");
	gets(strIn1);
	printf("������� ������  ������ ��������\n");
	gets(strIn2);
	while((*pIn1 != '\0')){
		while((*pbuff1 != ' ') && (*pbuff1 != '\0')){
			pbuff1++;
			count++;
		}
		memcpy(buff,pIn1,sizeof(char) *  count);
		pSR = strstr(strIn2,buff);
		if (pSR != NULL){
			buff[count] = sps;
			strcat(strOut,buff);
			sr++;
		}
		memset(buff,'\0',sizeof(buff));
		if(*pbuff1 != '\0')
			pbuff1++;
		pIn1 = pbuff1;
		count = 0;

	}
	if (sr)
		printf("������ �� ����, ��������� � ����� ������ �������:\n%s\n",strOut);
	else
		printf("���������� ���\n");
}
