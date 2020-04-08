/*Дана строка, содержащая дату в формате “дд.мм.гггг”. Проверить корректность этой
даты и сформировать строку, содержащую следующую по порядку дату.*/


#include <stdlib.h>
#include <stdio.h>


void main (){
	char str[20];
	int i;

	printf("Введите дату в формате дд.мм.гггг\n");
	scanf("%20s",str);
	for(i = 0; i < 20; i++){
		if(str[i] == '\0')
			break;
		else if(((str[i] > '9') || (str[i] < '0')) && (str[i] != '.')) {
			printf("Неверный формат ввода1\n");
			return;
		}
	}
	if((i > 10) || (i == 1)){
		printf("Неверный формат ввода2\n");
		return;
	}
	if((str[2] != '.') && (str[5] != '.')){
		printf("Неверный формат ввода3\n");
		return;
	}
	if((str[0] > '3') || (str[3] > '1')){
		printf("Неверный формат ввода4\n");
		return;
	}
	if(((str[3] == '0') && (str[4] == '2')) && (str[0] == '3')){
		printf("Неверный формат ввода5\n");
		return;
	}
	if((str[3] == '0') && (str[4] == '2')){
		if (str[0] < '2'){
			if (str[1] != '9')
				str[1]++;
			else{
				str[0]++;
				str[1] = '0';
			}
		}
		else {
			if ((str[1] != '9') && (str[1] != '8'))
				str[1]++;
			else{
				str[0] = '0';
				str[1] = '1';
				str[4] = '3';
			}
		}
	}
	else {
		if (str[0] < '3'){
			if (str[1] != '9')
				str[1]++;
			else{
				str[0]++;
				str[1] = '0';
			}
		}
		else{
			if(str[3] == '0'){
				if ((str [4] =='4') || (str [4] =='6') || (str [4] =='9')){
					str[0] = '0';
					str[1] = '1';
					str[4] ++;
				}
				else{
					if (str[1] == '1'){
						str[0] = '0';
						str[1] = '1';
						str[4] ++;
					}
					else
						str[1] = '1';
				}
			}
			else{
				if (str[4] == '0'){
					str[0] = '0';
					str[1] = '1';
					str[4] ++;
				}
				if (str[4] == '1'){
					if (str[1] == '1'){
						str[0] = '0';
						str[1] = '1';
						str[4] ++;
					}
					else
						str[1] = '1';
				}
				if (str[4] = '2'){
					if (str[1] == '1'){
						str[0] = '0';
						str[1] = '1';
						str[3] = '0';
						str[4] = '1';
						if(str[9] == '9'){
							str[9] = '0';
							if (str[8] != '9')
								str[8] ++;
							else {
								str[8] = '0';
								if (str[7] != '9')
									str[7]++;
								else{
									str[7] = '0';
									str[6]++;
								}
							}
						}
					}
					else
						str[1] = '1';
				}
			}
		}
	}
	printf("%s\n",str);
}




