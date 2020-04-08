/*Дана строка символов до точки. Записать слова этой строки в обратном порядке*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>



size_t find( const char *s, char c ){
	size_t i = 0;
	while ( s[i] && s[i] != c ) 
		i++;
	return i;
}   

char * reverse( char *s, size_t n ){
	for ( size_t i = 0; i < n / 2; i++ ){
		char c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}
	return s;
}

int main(void) {
	char s[200];
	printf("Введите предложение\n");
	gets(s);
	size_t n = find( s, '.' );
	reverse( s, n );
	for ( size_t i = 0; i != n; ){
		while ( s[i] == ' ' || s[i] == '\t' ) 
			i++;
		if ( i != n ){
			size_t j = i;
			while ( ++i != n && s[i] != ' ' && s[i] != '\t' );
				reverse( s + j, i - j );
		}
	}
	puts( s );
	return 0;
}