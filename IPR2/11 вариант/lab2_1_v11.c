/*Дана строка символов до точки. Подсчитать, сколько каких знаков препинания она
содержит.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main (){
	char str[200];
	char *pS;
	int vpr = 0, vsk = 0, zpt = 0, dvt = 0, tzp = 0, tr = 0;

	printf("Введите строку\n");
	fgets(str,200,stdin);
	pS = str;
	while ((*pS != '.') && (*pS != '\0')){
		switch(*pS) {
			case ',' :
				zpt++;
			break;
			case ';' :
				tzp++;
			break;
			case ':' :
				dvt++;
			break;
			case '!' :
				vsk++;
			break;
			case '?' :
				vpr++;
			break;
			case '-' :
				tr++;
			break;
			default:
			break;
		}
		pS++;
	}
	printf("Количество ,%d-;,  %d-:,  %d-!, %d-?, %d-%d", zpt, tzp, dvt, vsk, vpr, tr);
}