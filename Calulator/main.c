#include <stdio.h>
#include <stdint.h>
#include <string.h>

char* get_buffer(char* target, int32_t size);
void clear_string(char* target,uint32_t size);
void print_string_by_chars(char* target);


typedef enum {
	TOKEN_NUMBER,
	TOKEN_OPERATOR,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_END
} TokenType;

typedef union {
	double number;  // Sayı ise bu 8 bayt kullanılır
	char operator;  // İşlem ise sadece ilk 1 baytı kullanılır
} TokenValue;

typedef struct {
	TokenType type;   // Paketin türü (Sayı mı, İşlem mi?)
	TokenValue value; // Ortak bellek alanı
} Token;

int main() {
	char temp[50];
	Token token[1];
	get_buffer(temp, sizeof(temp));
	print_string_by_chars(temp);
	return 0;
}

char* get_buffer(char* target,int32_t size) {
	if (fgets(target, size, stdin) == NULL) {
		clear_string(target,size);
		return NULL;
	}
	char* p = strchr(target, '\n');

	if (p != NULL) {
		*p = '\0';
	}
	else {
		int32_t c;
		while ((c = getchar()) != EOF && c != '\n' && c != '\0');
	}
	return target;
}

void clear_string(char* target,uint32_t size) {
	size_t i = 0;
	while (i < size) {
		target[i] = '\0';
		i++;
	}
}

void print_string_by_chars(char* target) {
	size_t i = 0;
	printf("{ ");
	while (target[i] != '\0') {
		printf("'%c', ",target[i]);
		i++;
	}
	printf("'\\0' }");
}

void clear_spaces(char* target) {
	char* read = target;
	char* write = target;


}