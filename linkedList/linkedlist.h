#pragma once
/*
	File:linkedlist.c
	Created:24-03-27
	Author:È«½Â¿í
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Book {
	int bookid;
	char title[100];
	char author[100];
	int price;
	bool isBorrowed;
	struct Book* next;
} Book;

typedef struct LinkedList {
	Book* head;
	int size;

}LinkedList;

Book* createBook(int bookid, const char* title, const char* author, int price);
	

void initializeList(LinkedList* list);
void addBook(LinkedList* list, int bookid, const char* title, const char* author, int price);
void deleteBook(LinkedList* list, int bookid);

void printBooks(LinkedList* list);

void searchBooktitle(LinkedList* list, const char* title);

void searchBookid(LinkedList* list, int id);

void searchBookauthor(LinkedList* list, const char* author);

void freeList(LinkedList* list);

void borrowBook(LinkedList* list, int bookid);

void returnBook(LinkedList* list, int bookid);