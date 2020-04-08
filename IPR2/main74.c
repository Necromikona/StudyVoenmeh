#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <io.h>
#define MAX_LINES_COUNT 3
struct zoolog
{
    char name[40];
    char zone[40];
    double price;
};

void show(char *);
void add(char *);
void edit(char *);
void search(char *);
void animal_content(char *);
void delete_zoo(char *);
void delete_symline(char *);
void table (int);

int main(int argc, char *argv[])
{
	char menu;
	char file[260]="zoo.dat";
	int i;
	system ("chcp 1251");
    system ("mode con cols=117");
    if (argc >1) strcpy(file, argv[1]);
    else
    {
        printf("Введите имя файла: ");
        fgets(file,260,stdin);
        for (i=0;i<260;i++)
            if (file[i]=='\n') file[i]='\0';
    }
	do
	{
        system("cls");
        puts("1) Просмотр данных ");
        puts("2) Добавление данных");
        puts("3) Корректировка данных");
        puts("4) Поиск животных по природной зоне");
        puts("5) Стоимость содержания животных");
        puts("6) Удаление данных ");
        puts("0) Выход ");
        printf("Введите номер команды: ");
        menu=getchar();
//        fflush(stdin);
        switch (menu)
		{
            case '1': show(file); break;
            case '2': add(file); break;
            case '3': edit(file); break;
            case '4': search(file); break;
            case '5': animal_content(file); break;
            case '6': delete_zoo(file); break;
        }
    }
	while (menu != '0');
    return 0;
}

typedef struct zoolog ZOO;

ZOO input(void)
{
    ZOO elem;
    int z=0;
    fflush(stdin);
    printf("Название   животного: ");
    fgets(elem.name, 40, stdin);
    fflush(stdin);
    delete_symline(elem.name);
    printf("Природная зона: ");
    fgets(elem.zone, 40, stdin);
    fflush(stdin);
    delete_symline(elem.zone);
	do
	{
		printf("Затраты на корм (за 1 день): ");
		z=0;
		if(!scanf("%lf", &elem.price))
			z=1;
		fflush(stdin);
		while(elem.price>ULLONG_MAX)
			elem.price/=10;
	}
    while(elem.price<0 || z);
    return elem;
}

void delete_symline(char *str)
{
    int i=0;
    while (str[i])
	{
        if(str[i] == '\n') str[i]='\0';
        i++;
        if(i==40)
		{
			str[i]='\0';
			break;
		}
    }
}
//добавление
void add(char *file)
{
    FILE *f;
    ZOO elem;
    system("cls");
    if((f = fopen(file, "ab")) == NULL)
	{
        perror("Ошибка открытия файла");
        system("pause");
        return;
    }
    elem=input();
    fwrite(&elem, sizeof(elem), 1, f);
    system("pause");
    fclose(f);
}
//вывод
void print_one(ZOO elem)
{
     printf("|%40s|%40s|%33.2lf|", elem.name, elem.zone, elem.price);
}
//просмотр
void show(char *file)
{
    FILE *f;
    ZOO elem;
    int y=0, i=0, k=0, pos=0, N;
    char flag='2';
    system("cls");
    if ((f = fopen(file, "r+b")) == NULL)
	{
        perror("Ошибка открытия файла");
        system("pause");
        return;
    }
    fseek(f, 0, SEEK_END);
    N=ftell(f);
    //printf("В файле нет данных\n");
    //system("pause");
    //return ;
    if (!N)
	{
        printf("В файле нет данных\n");
        system("pause");
        return ;
    }
    fseek(f, 0, SEEK_SET);
    fflush(stdin);
	do
	{
        switch (flag)
		{
            case '2':
            	if (k==0 || k==2)
            	{
                	i=0;
                	system("cls");
                	fseek(f, pos, SEEK_SET);
                	table (1);
                	while (fread(&elem, sizeof(ZOO), 1, f) && i<MAX_LINES_COUNT)
					{
                        print_one(elem);
                        table (2);
                        i++;
                	}
                	pos+=i*sizeof(ZOO);
                	break;
            	}
            	if (k==1)
            	{
            		pos-=y*sizeof(ZOO);
                	i=0;
                	system("cls");
                	fseek(f, pos, SEEK_SET);
                	table (1);
                	while (fread(&elem, sizeof(ZOO), 1, f) && i<MAX_LINES_COUNT)
					{
                        print_one(elem);
                        table (2);
                        i++;
                	}
                	pos+=i*sizeof(ZOO);
                	break;
				}
			case '1':
				if(k==0 || k==1)
				{
					pos-=(y+MAX_LINES_COUNT)*sizeof(ZOO);
                	i=0;
                	system("cls");
                	fseek(f, pos, SEEK_SET);
                	table (1);
                	while (fread(&elem, sizeof(ZOO), 1, f) && i<MAX_LINES_COUNT)
					{
                        print_one(elem);
                        table (2);
                        i++;
                	}
                	pos+=i*sizeof(ZOO);
                	break;
            	}
            	if(k==2)
            	{
            		pos-=y*sizeof(ZOO);
                	i=0;
                	system("cls");
                	fseek(f, pos, SEEK_SET);
                	table (1);
                	while (fread(&elem, sizeof(ZOO), 1, f) && i<MAX_LINES_COUNT)
					{
                        print_one(elem);
                        table (2);
                        i++;
                	}
                	pos+=i*sizeof(ZOO);
                	break;
				}
			default:
				pos-=y*sizeof(ZOO);
                i=0;
                system("cls");
                fseek(f, pos, SEEK_SET);
                table (1);
                while (fread(&elem, sizeof(ZOO), 1, f) && i<MAX_LINES_COUNT)
				{
                	print_one(elem);
                    table (2);
                    i++;
                }
                pos+=i*sizeof(ZOO);
                break;
        }
        y=i;
        k=0;
		if (pos>=N)  k=1;
        if (pos<=y*sizeof(ZOO))  k=2;
       	if(!k)   printf("\n0) Выйти      1) Назад      2) Дальше\n");
       	else if(k==1)
		{
			printf("  Конец файла\n");
			printf("\n0) Выйти      1) Назад \n");
		}
       	else if(k==2)
		{
			printf("  Начало файла\n");
			printf("\n0) Выйти      2) Дальше\n");
		}
		printf(" Введите команду: ");
		scanf("%c",&flag);
        fflush(stdin);
    }
	while (flag!='0');
}
//Редактирование
void edit(char *file)
{
	FILE *f;
    ZOO elem;
    char name[40], flag;
    int q=0;
    system("cls");
    if ((f = fopen(file, "r+b")) == NULL)
	{
        perror("Ошибка открытия файла ");
        system("pause");
        return;
    }
    printf("Название животного: ");
    fflush(stdin);
    fgets(name, 40, stdin);
    delete_symline(name);
    fseek(f, 0, SEEK_SET);
    while (fread(&elem, sizeof(ZOO), 1, f))
    {
		if (!strcmp(elem.name, name))
		{
			q++;
			do
			{
				system("cls");
				table (1);
				print_one(elem);
				table (3);
           		puts("0) Выйти      1) Редактировать      2) Пропустить");
           		printf(" Введите команду: ");
           		fflush(stdin);
           		scanf("%c",&flag);
			}
           	while (flag != '0' && flag != '1' && flag!='2');
	   		if (flag =='0') return;
           	else if (flag =='1')
			{
               	elem=input();
               	fseek(f, -sizeof(ZOO), SEEK_CUR);
               	fwrite(&elem, sizeof(ZOO), 1, f);
               	fseek(f, 0, SEEK_CUR);
           	}
       	}
    }
    if (!q)
	{
		puts(" Нет совпадений");
    	system("pause");
    }
    else
    {
    	puts("\n Больше совпадений не найдено");
    	system("pause");
	}
    fclose(f);
}
//поиск животных по природной зоне
void search(char *file)
{
	FILE *f;
    ZOO elem;
    char flag, zone[40];
    int q=0;
    system("cls");
    if ((f = fopen(file, "rb")) == NULL)
	{
        perror("Ошибка открытия файла ");
        system("pause");
        return;
    }
	printf("Природная зона: ");
	fflush(stdin);
    fgets(zone, 40, stdin);
    delete_symline(zone);
    fseek(f, 0, SEEK_SET);
    system("cls");
    table (1);
    while (fread(&elem, sizeof(ZOO), 1, f))
    {
		if (!strcmp(elem.zone, zone))
		{
			print_one(elem);
			table (2);
			q++;
       	}
    }
    if (!q) puts(" Нет совпадений");
    else printf("\n Количество животных природной зоны %s: %d\n",zone,q);
	system("pause");
    fclose(f);
}
//стоимость сожержания в месяц
void animal_content(char *file)
{
	FILE *f;
    ZOO elem;
    char name[40], flag;
    int q=0,s=0,z;
    double price;
    system("cls");
    if ((f = fopen(file, "rb")) == NULL)
	{
        perror("Ошибка открытия файла ");
        system("pause");
        return;
    }
	printf("Название животного: ");
    fflush(stdin);
    fgets(name, 40, stdin);
    delete_symline(name);
    fseek(f, 0, SEEK_SET);
    while (fread(&elem, sizeof(ZOO), 1, f))
    {
		if (!strcmp(elem.name, name))
		{
			q++;
			do
			{
				system("cls");
    			table (1);
				print_one(elem);
				table (3);
				puts("Вычислить стоимость содержания этого животного в месяц?   0) Выйти   1) Да   2) Нет");
	    		printf(" Введите команду: ");
	    		scanf("%c",&flag);
        		fflush(stdin);
			}
    		while (flag != '0'&& flag!='1' && flag!='2');
    		if (flag=='0')
			{
				fclose(f);
				return;
			}
    		else if (flag == '1')
    		{
    			do
				{
					system("cls");
    				table (1);
					print_one(elem);
					table (3);
					printf("Введите количесво дней в месяце: ");
					z=0;
					if(!scanf("%d",&s))
						z=1;
					fflush(stdin);
				}
				while(z || s<28 || s>31);
				system("cls");
    			table (1);
				print_one(elem);
				table (3);
    			printf(" Стоимость содержания животного %s за %d дней: %.2lf\n",name,s,elem.price*s);
    			system("pause");
			}
       	}
	}
	if (!q)
	{
		puts(" Нет совпадений");
    	system("pause");
    }
    else
    {
    	puts("\n Больше совпадений не найдено");
    	system("pause");
	}
    fclose(f);
}
//удаление
void delete_zoo(char *file)
{
	FILE *f;
    ZOO elem;
    char name[40], flag;
    int N,k,q=0,l;
    system("cls");
    if ((f = fopen(file, "r+b")) == NULL)
	{
        perror("Ошибка открытия файла ");
        system("pause");
        return;
    }
	printf("Название животного: ");
	fflush(stdin);
    fgets(name, 40, stdin);
    delete_symline(name);
    fseek(f, 0, SEEK_END);
    N=ftell(f);
    fseek(f, 0, SEEK_SET);
    for(l=0;l<N;l+=sizeof(ZOO))
    {
    	fseek(f, l, SEEK_SET);
	   	fread(&elem, sizeof(ZOO), 1, f);
		if (!strcmp(elem.name, name))
		{
			q++;
			do
			{
				system("cls");
				table (1);
				print_one(elem);
				table (3);
           		puts("0) Выйти      1) Удалить      2) Пропустить");
				printf(" Введите команду: ");
           		scanf("%c",&flag);
        		fflush(stdin);
			}
           	while (flag != '0' && flag != '1' && flag!='2');
	   		if (flag =='0') break;
           	if (flag =='1')
			{
				do
				{
					system("cls");
					table (1);
					print_one(elem);
					table (3);
					puts("Вы точно хотите удалить?   0) НЕТ      1) ДА");
					printf(" Введите команду: ");
           			scanf("%c",&flag);
        			fflush(stdin);
				}
				while (flag != '0' && flag != '1' );
           		if (flag =='1')
				{
					k=l;
					k+=sizeof(ZOO);
					for (;k<N;k+=sizeof(ZOO))
					{

						fseek(f, k, SEEK_SET);
						fread(&elem, sizeof(ZOO), 1, f);
						fseek(f, k-2*sizeof(ZOO), SEEK_SET);
						fwrite(&elem, sizeof(ZOO), 1, f);
               		}
               		N-=sizeof(ZOO);
                	chsize(fileno(f),N);
                	l-=sizeof(ZOO);
            	}
            }
        }
    }
    if (!q)
	{
		puts(" Нет совпадений");
    	system("pause");
    }
    else
    {
    	puts("\n Больше совпадений не найдено");
    	system("pause");
	}
    fclose(f);
}
void table (int n)
{
	if (n==1)
	{
		printf("|           Название животного           |             Природная зона             |   Затраты на корм (за 1 день)   |");
		printf("|----------------------------------------+----------------------------------------+---------------------------------|");
	}
	if (n==2) printf("|----------------------------------------+----------------------------------------+---------------------------------|");
	if (n==3) printf("|-------------------------------------------------------------------------------------------------------------------|");
}
