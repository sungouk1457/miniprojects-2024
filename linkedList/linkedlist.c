/*
	File:linkedlist.c
	Created:24-03-27
	Author:홍승욱
*/
#define _CRT_SECURE_NO_WARNINGS
#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

Book * createBook(int bookid, const char* title, const char* author, int price) {
	Book * newBook = (Book*)malloc(sizeof(Book));
	if (newBook == NULL) {
		printf("메모리 할당에 실패했습니다.");
		exit(1);
	}
	newBook->bookid = bookid;
	strncpy(newBook->title, title, sizeof(newBook->title));
	strncpy(newBook->author, author, sizeof(newBook->author));
	newBook->price = price;
	newBook->isBorrowed = false;
	newBook->next = NULL;
	return newBook;
}

void initializeList(LinkedList* list) {
	list->head = NULL;
	list->size = 0;
}

void addBook(LinkedList * list, int bookid, const char* title, const char* author, int price) {
	Book * newBook = createBook(bookid, title, author, price);
	if (list->head == NULL) {
		list->head = newBook;
	}
	else {
		Book * temp = list->head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newBook;
	}
	list->size++;
}

void deleteBook(LinkedList * list, int bookid) {
	Book * current = list->head;
	Book* prev = NULL;
		while (current != NULL) {
		if (current->bookid == bookid) {
			if (prev == NULL) {
				list->head = current->next;
			}
			else {
				prev->next = current->next;
			}
			free(current);
			list->size--;
			printf("도서가 삭제되었습니다.\n");
			return;
		}
		prev = current;
		current = current->next;
		}
		printf("해당 ID의 도서를 찾을 수 없습니다.\n");
}

void printBooks(LinkedList* list) {
	Book* current = list->head;
	if (current == NULL) {
		printf("출력할 도서가 없습니다.\n");
		return;
	}
	printf("도서 목록\n");
	while (current != NULL) {
		printf("도서ID: %d, 제목: %s, 저자: %s, 가격: %d\n", current->bookid, current->title, current->author, current->price);
		current = current->next;
	}
}

void searchBooktitle(LinkedList* list, const char* title) {
	Book* current = list->head;
	int found = 0;
	printf("검색 결과:\n");
	while (current != NULL) {
		if (strcmp(current->title, title) == 0) {
			printf("도서 ID: %d, 제목: %s, 저자: %s, 가격: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
		}
		current = current->next;
	}
	if (!found) {
		printf("해당 제목의 도서를 찾을 수 없습니다.\n");
	}
}

void searchBookid(LinkedList* list, int id) {
	Book* current = list->head;
	int found = 0;
	printf("검색 결과:\n");
	while (current != NULL) {
		if (current->bookid == id) {
			printf("도서 ID: %d, 제목: %s, 저자: %s, 가격: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
			break;
		}
		current = current->next;
	}
	if (!found) {
		printf("해당 ID의 도서를 찾을 수 없습니다.\n");
	}
}

void searchBookauthor(LinkedList* list, const char* author) {
	Book* current = list->head;
	int found = 0;
	printf("검색 결과:\n");
	while (current != NULL) {
		if (strcmp(current->author, author) == 0) {
			printf("도서 ID: %d, 제목: %s, 저자: %s, 가격: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
		}
		current = current->next;
	}
	if (!found) {
		printf("해당 저자의 도서를 찾을 수 없습니다.\n");
	}
}

void freeList(LinkedList * list) {
	Book * current = list->head;
	while (current != NULL) {
		Book * temp = current;
		current = current->next;
		free(temp);
	}
	list->head = NULL;
	list->size = 0;
}

void borrowBook(LinkedList* list, int bookid) {
	Book* current = list->head;
	while (current != NULL) {
		if (current->bookid == bookid) {
			if (current->isBorrowed) {
				printf("해당 도서는 이미 대여 중입니다.\n");
			}
			else {
				current->isBorrowed = true; 
				printf("도서가 대여되었습니다.\n");
			}
			return;
		}
		current = current->next;
	}
	printf("해당 ID의 도서를 찾을 수 없습니다.\n");
}

void returnBook(LinkedList* list, int bookid) {
	Book* current = list->head;
	while (current != NULL) {
		if (current->bookid == bookid) {
			if (current->isBorrowed) {
				current->isBorrowed = false;
				printf("도서가 반납되었습니다.\n");
			}
			else {
				printf("해당 도서는 대여되지 않았습니다.\n");
			}
			return;
		}
		current = current->next;
	}
	printf("해당 ID의 도서를 찾을 수 없습니다.\n");
}

