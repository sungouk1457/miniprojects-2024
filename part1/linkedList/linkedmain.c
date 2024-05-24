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

int  main()
{
	LinkedList bookList;
	initializeList(&bookList);
	while (true) {
		printf("****메뉴****\n");
		printf("1. 도서구입\n");
		printf("2. 도서검색\n");
		printf("3. 도서삭제\n");
		printf("4. 도서출력\n");
		printf("5. 도서대여\n");
		printf("6. 도서반납\n");
		printf("0. 종료\n");
		printf("************\n");
		printf("메뉴 선택 >> ");
		int choice = 0;
		scanf("%d", &choice);

		if (choice == 1) {
			int id;
			char title[100];
			char author[100];
			int price;
			printf("등록할 도서 정보 입력:\n");
			printf("도서ID: ");
			scanf("%d", &id);
			printf("도서제목: ");
			scanf("%s", title);
			printf("도서저자: ");
			scanf("%s", author);
			printf("도서가격: ");
			scanf("%d", &price);
			addBook(&bookList, id, title, author, price);
			printf("도서 추가 완료\n");
		}
		else if (choice == 2) {
			int searchnum = 0;
			printf("검색 방법 선택\n");
			printf("1. 도서 ID로 검색\n");
			printf("2. 도서 제목으로 검색\n");
			printf("3. 도서 저자로 검색\n");
			printf("원하는 작업을 선택: ");
			scanf("%d", &searchnum);

			if (searchnum == 1) {
				int id;
				printf("검색할 도서의 ID 입력: ");
				scanf("%d", &id);
				searchBookid(&bookList, id);
			}
			else if (searchnum == 2) {
				char title[100];
				printf("검색할 도서의 제목 입력: ");
				scanf("%s", title);
				searchBooktitle(&bookList, title);
			}
			else if (searchnum == 3) {
				char author[100];
				printf("검색할 도서의 저자 입력: ");
				scanf("%s", author);
				searchBookauthor(&bookList, author);
			}
			else {
				printf("잘못된 입력입니다. 다시 선택하세요.\n");
			}
			int borrowChoice;
			printf("대여할 도서를 찾았습니다. 대여하시겠습니까? (1: 예, 0: 아니오): ");
			scanf("%d", &borrowChoice);
			if (borrowChoice == 1) {
				int bookid;
				printf("대여할 도서의 ID를 입력: ");
				scanf("%d", &bookid);
				borrowBook(&bookList, bookid);
			}
		}

		else if (choice == 3) {
			int id;
			printf("삭제할 도서의 ID를 입력: ");
			scanf("%d", &id);
			deleteBook(&bookList, id);
		}
		else if (choice == 4) {
			printBooks(&bookList);
		}
		else if (choice == 5) {
			int id;
			printf("대여할 도서의 ID를 입력: ");
			scanf("%d", &id);
			borrowBook(&bookList, id);
		}
		else if (choice == 6) {
			int id;
			printf("반납할 도서의 ID를 입력: ");
			scanf("%d", &id);
			returnBook(&bookList, id);
		}
		else if (choice == 0) {
			printf("프로그램 종료\n");
			break;
		}
		else {
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}
		while (getchar() != '\n');
	}
	freeList(&bookList);
	return 0;
}