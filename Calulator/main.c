#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// CONSTANTS AND MAKROS
#define MAX_CALCULATE_AREA 1000

typedef enum {
	TOKEN_NUMBER,
	TOKEN_OPERATOR,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_UNDEFINED,
	TOKEN_END
} TokenType;

typedef union {
	double number;
	char op;
} TokenValue;

typedef struct {
	TokenType type;
	TokenValue value;
} Token;


// FUNCTİON DECLARİTİON
char* get_buffer(char* target, size_t size);
void clear_string(char* target, size_t size);
void print_string_by_chars(char* target);
void clear_whitespace(char* target);
char* get_calculable_input(char* target, size_t size);
size_t tokenize(const char* input, Token* tokens, size_t max_tokens);
void print_tokenized_input(Token* tokens, size_t max_token);

// MAİN FUNCTİON
int main() {
	char temp[MAX_CALCULATE_AREA];
	Token token[50];
	get_calculable_input(temp,sizeof(temp));
	tokenize(temp,token,50);
	print_tokenized_input(token, 50);
	return 0;
}

char* get_buffer(char* target,size_t size) {
	if (target == NULL) {
		return NULL;
	}
	if (fgets(target, (int) size, stdin) == NULL) {
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

void clear_string(char* target, size_t size) {
	if (target == NULL || size == 0) {
		return;
	}
	size_t i = 0;
	while (i < size) {
		target[i] = '\0';
		i++;
	}
}

void print_string_by_chars(char* target) {
	if (target == NULL) {
		return;
	}
	size_t i = 0;
	printf("{ ");
	while (target[i] != '\0') {
		printf("'%c', ",target[i]);
		i++;
	}
	printf("'\\0' }");
}

void clear_whitespace(char* target) {
	if (target == NULL) {
		return;
	}
	const char* r = target;
	char* w = target;

	while (*r != '\0') {
		if (*r != ' ' && *r != '\t' && *r != '\n') {
			*w = *r;
			w++;
		}
		r++;
	}
	*w = '\0';
}
char* get_calculable_input(char* target, size_t size) {
	get_buffer(target, size);
	clear_whitespace(target);
	return target;
}

size_t tokenize(const char* input, Token* tokens, size_t max_tokens) {
	if (input == NULL || tokens == NULL || max_tokens == 0) {
		return 0;
	}

	const char* r = input;
	size_t while_cycle = 0;
	while (*r != '\0') {
		if (while_cycle >= max_tokens - 1) {
			break;
		}
		
		if (isdigit((unsigned char)*r) || *r == '.') {
			char* end_ptr;

			tokens[while_cycle].type = TOKEN_NUMBER;
			// strtod r'den başlar, tüm sayıyı okur ve bitiş adresini end_ptr'ye yazar
			tokens[while_cycle].value.number = strtod(r, &end_ptr);

			// Eğer sadece tek başına '.' girilmişse ve sayı okunamadıysa (end_ptr ilerlemediyse)
			if (r == end_ptr) {
				tokens[while_cycle].type = TOKEN_UNDEFINED;
				tokens[while_cycle].value.op = *r;
				r++;
			}
			else {
				r = end_ptr; // Okuma adresini sayının bittiği yere atlatıyoruz
			}

			while_cycle++;
			continue; // r zaten ilerlediği için döngünün sonundaki r++ çalışmamalı
		}

		else if (*r == '(') {
			tokens[while_cycle].type = TOKEN_LPAREN;
			tokens[while_cycle].value.op = '(';
		}
		else if (*r == ')') {
			tokens[while_cycle].type = TOKEN_RPAREN;
			tokens[while_cycle].value.op = ')';
		}
		else if (*r == '+') {
			tokens[while_cycle].type = TOKEN_OPERATOR;
			tokens[while_cycle].value.op = '+';
		}
		else if (*r == '-') {
			tokens[while_cycle].type = TOKEN_OPERATOR;
			tokens[while_cycle].value.op = '-';
		}
		else if (*r == '*') {
			tokens[while_cycle].type = TOKEN_OPERATOR;
			tokens[while_cycle].value.op = '*';
		}
		else if (*r == '/') {
			tokens[while_cycle].type = TOKEN_OPERATOR;
			tokens[while_cycle].value.op = '/';
		}
		else {
			tokens[while_cycle].type = TOKEN_UNDEFINED;
			tokens[while_cycle].value.op = *r;
		}
		while_cycle++;
		r++;
	}
	tokens[while_cycle].type = TOKEN_END;
	tokens[while_cycle].value.op = '\0';
	return while_cycle;
}

void print_tokenized_input(Token* tokens,size_t max_tokens) {
	if (tokens == NULL || max_tokens == 0) {
		return;
	}

	printf("Token |      Type       | Value\n");
	for (size_t i = 0; i < max_tokens; i++) {
		if (tokens[i].type == TOKEN_END) {
			break;
		}
		printf("  %zu     ", i);
		switch (tokens[i].type) {
			case TOKEN_NUMBER:
				printf("TOKEN_NUMBER");
				break;
			case TOKEN_OPERATOR:
				printf("TOKEN_OPERATOR");
				break;
			case TOKEN_LPAREN: 
				printf("TOKEN_LPAREN");
				break;
			case TOKEN_RPAREN: 
				printf("TOKEN_RPAREN");
				break;
			case TOKEN_UNDEFINED: 
				printf("TOKEN_UNDEFINED");
				break;
			default:
				break;
		}
		if (tokens[i].type == TOKEN_NUMBER) {
			printf("     %f\n", tokens[i].value.number);
		}
		else {
			printf("     %c\n", tokens[i].value.op);
		}
		
	}
}