/*
	File:file.c
	Created:24-03-13
	Author:ȫ�¿�
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#define MAX_LEN 100

void main()
{
	char mid[] = "abc123";
	char mpw[] = "1234";
	char id[20];
	char pw[20];
	printf("ID�Է� > ");
	scanf("%s", &id);
	printf("PW�Է� > ");
	scanf("%s", &pw);
	printf("=======================\n");
	if (strcmp(id, mid) == 0 && strcmp(pw, mpw) == 0) {
		int fd;
		char str[MAX_LEN];

		fd = open("myinfo.txt", O_RDONLY);
		if(read(fd, str, sizeof(str)) < 0) printf("read error");
		printf("%s\n", str);
		
		close(fd);
	}
	else {
		printf("�α��� ����");
	}
