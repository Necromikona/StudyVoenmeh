/*Дана строка символов. Удалить из нее все слова нечетной длины. Слова отделяются
друг от друга одним пробелом.*/
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main (){
	SetConsoleCP(1251); //СѓСЃС‚Р°РЅРѕРІРєР° РєРѕРґРѕРІРѕР№ СЃС‚СЂР°РЅРёС†С‹ win-cp 1251 РІ РїРѕС‚РѕРє РІРІРѕРґР°
	SetConsoleOutputCP(1251);
	char strIn[200],strOut[200];
	int count  = 0;
	char *pIn = strIn, *pOut = strOut, *pbuff = strIn;

	printf("������� ������ ��������\n");
	gets(strIn);
	while( *pIn != '\0'){
		while( (*pbuff != ' ') && (*pbuff != '\0')){
			pbuff++;
			count++;
		}
		if (!(count%2)){
			count++;
			memcpy(pOut, pIn, (sizeof (char)) * count);
			pOut += count;
		}
		pbuff++;
		pIn = pbuff;
		count = 0;
	}
	printf("%s\n",strOut);
}
