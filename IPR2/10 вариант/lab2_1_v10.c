/*Дана строка символов. Изменить строку – во всех словах, имеющих нечетное
количество символов, средний символ удалить.*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main (){
	char strIn[200],strOut[200];
	int count  = 0, tmp = 0;
	char *pIn = strIn, *pOut = strOut, *pbuff = strIn;

	memset(strOut,'\0',sizeof(strOut));
	printf("Введите строку символов\n");
	gets(strIn);
	while( *pIn != '\0'){
		while( (*pbuff != ' ') && (*pbuff != '\0')){
			pbuff++;
			count++;
		}
		if (count%2){
			tmp = count/2;
			memcpy(pOut, pIn, (sizeof (char)) * tmp);
			memcpy(pOut + tmp, pIn + tmp + 1 , (sizeof (char)) * (tmp + 1));
			pOut += count;
		}
		else{
			count++;
			memcpy(pOut,pIn,(sizeof(char) * count));
			pOut += count;
		} 
		pbuff++;
		pIn = pbuff;
		count = 0;
	}
	printf("%s\n",strOut);
}
