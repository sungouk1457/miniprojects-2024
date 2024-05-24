/*
	File:linkedlist.c
	Created:24-03-27
	Author:ȫ�¿�
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
		printf("�޸� �Ҵ翡 �����߽��ϴ�.");
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
			printf("������ �����Ǿ����ϴ�.\n");
			return;
		}
		prev = current;
		current = current->next;
		}
		printf("�ش� ID�� ������ ã�� �� �����ϴ�.\n");
}

void printBooks(LinkedList* list) {
	Book* current = list->head;
	if (current == NULL) {
		printf("����� ������ �����ϴ�.\n");
		return;
	}
	printf("���� ���\n");
	while (current != NULL) {
		printf("����ID: %d, ����: %s, ����: %s, ����: %d\n", current->bookid, current->title, current->author, current->price);
		current = current->next;
	}
}

void searchBooktitle(LinkedList* list, const char* title) {
	Book* current = list->head;
	int found = 0;
	printf("�˻� ���:\n");
	while (current != NULL) {
		if (strcmp(current->title, title) == 0) {
			printf("���� ID: %d, ����: %s, ����: %s, ����: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
		}
		current = current->next;
	}
	if (!found) {
		printf("�ش� ������ ������ ã�� �� �����ϴ�.\n");
	}
}

void searchBookid(LinkedList* list, int id) {
	Book* current = list->head;
	int found = 0;
	printf("�˻� ���:\n");
	while (current != NULL) {
		if (current->bookid == id) {
			printf("���� ID: %d, ����: %s, ����: %s, ����: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
			break;
		}
		current = current->next;
	}
	if (!found) {
		printf("�ش� ID�� ������ ã�� �� �����ϴ�.\n");
	}
}

void searchBookauthor(LinkedList* list, const char* author) {
	Book* current = list->head;
	int found = 0;
	printf("�˻� ���:\n");
	while (current != NULL) {
		if (strcmp(current->author, author) == 0) {
			printf("���� ID: %d, ����: %s, ����: %s, ����: %d\n", current->bookid, current->title, current->author, current->price);
			found = 1;
		}
		current = current->next;
	}
	if (!found) {
		printf("�ش� ������ ������ ã�� �� �����ϴ�.\n");
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
				printf("�ش� ������ �̹� �뿩 ���Դϴ�.\n");
			}
			else {
				current->isBorrowed = true; 
				printf("������ �뿩�Ǿ����ϴ�.\n");
			}
			return;
		}
		current = current->next;
	}
	printf("�ش� ID�� ������ ã�� �� �����ϴ�.\n");
}

void returnBook(LinkedList* list, int bookid) {
	Book* current = list->head;
	while (current != NULL) {
		if (current->bookid == bookid) {
			if (current->isBorrowed) {
				current->isBorrowed = false;
				printf("������ �ݳ��Ǿ����ϴ�.\n");
			}
			else {
				printf("�ش� ������ �뿩���� �ʾҽ��ϴ�.\n");
			}
			return;
		}
		current = current->next;
	}
	printf("�ش� ID�� ������ ã�� �� �����ϴ�.\n");
}

