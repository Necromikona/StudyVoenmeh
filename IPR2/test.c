#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>


void main()
{
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);


    unsigned char mas[20]; //��������� ������ ��������
  	int i;
  	puts("������� �������");
  	gets(mas); // ������ ������ �������� 

  for(i=0;mas[i]!='.';i++)
  {
         if (((mas[i]>='a') && (mas[i]<='z')) || ((mas[i]>='�') && (mas[i]<='�'))) //��������� �������� ������� �� �����
             {
            mas[i]-=32; // ����������� � ��������
        }
        else
          if(mas[i]>='�' && mas[i]<='�')
            {
           mas[i]-=80;
             }
}
        printf("\n%s\n",mas);
        //getchar ();

}