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

int  main()
{
	LinkedList bookList;
	initializeList(&bookList);
	while (true) {
		printf("****�޴�****\n");
		printf("1. ��������\n");
		printf("2. �����˻�\n");
		printf("3. ��������\n");
		printf("4. �������\n");
		printf("5. �����뿩\n");
		printf("6. �����ݳ�\n");
		printf("0. ����\n");
		printf("************\n");
		printf("�޴� ���� >> ");
		int choice = 0;
		scanf("%d", &choice);

		if (choice == 1) {
			int id;
			char title[100];
			char author[100];
			int price;
			printf("����� ���� ���� �Է�:\n");
			printf("����ID: ");
			scanf("%d", &id);
			printf("��������: ");
			scanf("%s", title);
			printf("��������: ");
			scanf("%s", author);
			printf("��������: ");
			scanf("%d", &price);
			addBook(&bookList, id, title, author, price);
			printf("���� �߰� �Ϸ�\n");
		}
		else if (choice == 2) {
			int searchnum = 0;
			printf("�˻� ��� ����\n");
			printf("1. ���� ID�� �˻�\n");
			printf("2. ���� �������� �˻�\n");
			printf("3. ���� ���ڷ� �˻�\n");
			printf("���ϴ� �۾��� ����: ");
			scanf("%d", &searchnum);

			if (searchnum == 1) {
				int id;
				printf("�˻��� ������ ID �Է�: ");
				scanf("%d", &id);
				searchBookid(&bookList, id);
			}
			else if (searchnum == 2) {
				char title[100];
				printf("�˻��� ������ ���� �Է�: ");
				scanf("%s", title);
				searchBooktitle(&bookList, title);
			}
			else if (searchnum == 3) {
				char author[100];
				printf("�˻��� ������ ���� �Է�: ");
				scanf("%s", author);
				searchBookauthor(&bookList, author);
			}
			else {
				printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
			}
			int borrowChoice;
			printf("�뿩�� ������ ã�ҽ��ϴ�. �뿩�Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�): ");
			scanf("%d", &borrowChoice);
			if (borrowChoice == 1) {
				int bookid;
				printf("�뿩�� ������ ID�� �Է�: ");
				scanf("%d", &bookid);
				borrowBook(&bookList, bookid);
			}
		}

		else if (choice == 3) {
			int id;
			printf("������ ������ ID�� �Է�: ");
			scanf("%d", &id);
			deleteBook(&bookList, id);
		}
		else if (choice == 4) {
			printBooks(&bookList);
		}
		else if (choice == 5) {
			int id;
			printf("�뿩�� ������ ID�� �Է�: ");
			scanf("%d", &id);
			borrowBook(&bookList, id);
		}
		else if (choice == 6) {
			int id;
			printf("�ݳ��� ������ ID�� �Է�: ");
			scanf("%d", &id);
			returnBook(&bookList, id);
		}
		else if (choice == 0) {
			printf("���α׷� ����\n");
			break;
		}
		else {
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}
		while (getchar() != '\n');
	}
	freeList(&bookList);
	return 0;
}