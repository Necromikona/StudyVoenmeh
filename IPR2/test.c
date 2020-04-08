#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>


void main()
{
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);


    unsigned char mas[20]; //объ€вл€ем массив символов
  	int i;
  	puts("¬ведите символы");
  	gets(mas); // вводим строку символов 

  for(i=0;mas[i]!='.';i++)
  {
         if (((mas[i]>='a') && (mas[i]<='z')) || ((mas[i]>='а') && (mas[i]<='п'))) //провер€ем введЄнные символы на буквы
             {
            mas[i]-=32; // преобразуем в строчные
        }
        else
          if(mas[i]>='р' && mas[i]<='€')
            {
           mas[i]-=80;
             }
}
        printf("\n%s\n",mas);
        //getchar ();

}