/*
	File:file.c
	Created:24-03-13
	Author:홍승욱
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
	printf("ID입력 > ");
	scanf("%s", &id);
	printf("PW입력 > ");
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
		printf("로그인 실패");
	}
