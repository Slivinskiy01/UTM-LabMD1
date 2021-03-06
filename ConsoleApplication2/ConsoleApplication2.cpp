// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include <conio.h>
# include <math.h>
# include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int MI[100][100], MS[100][100], n, m, k;
struct node {
	int v;
	node *next;
	node(int x, node * t) { v = x; next = t; }
};
typedef node *lnk;
lnk adj[100];
void FMI()
{
	printf("Matritsa Intidentnosti\n  ");
	for (int i = 0; i<n; i++) {
		printf("vvedite %d  stroku\n", i + 1);
		for (int j = 0; j<m; j++)
			scanf_s("%d", &MI[i][j]);
	}
}
void FMS()
{
	printf("Matrita Smejnosti\n ");
	for (int i = 0; i<n; i++) {
		printf("vvedite %d stroku\n", i + 1);
		for (int j = 0; j<n; j++)
			scanf_s("%d", &MS[i][j]);
	}
}
void FSS()
{
	int tmp;
	printf("Spisok Smejnosti\n ");
	for (int i = 0; i<n; i++) {
		printf("vvedit vershinu sviazanui s %d\n", i + 1);
		printf("%d: ", i + 1);
		scanf_s("%d", &tmp);
		while (tmp) {
			adj[i] = new node(tmp - 1, adj[i]);
			scanf_s("%d", &tmp);
		}
	}
}
void FMSvSS()
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (MS[i][j])
				adj[i] = new node(j, adj[i]);
}
void FSSvMI()
{
	int m = 0;
	for (int i = 0; i<n; i++) {
		lnk tmp = adj[i];
		while (tmp) {
			MI[m][i] = -1;
			MI[m++][tmp->v] = 1;
			tmp = tmp->next;
		}
	}
}
void FMIvMS()
{
	int i, j, k, l;
	for (i = 0; i<m; i++) {
		for (j = 0; j<n; j++) {
			if (MI[i][j] == -1) k = j;
			if (MI[i][j] == 1) l = j;
		}
		MS[k][l] = 1;
	}
}
void printm()
{
	printf("Matritsa Intidentnosti\n");
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++)
			printf("%2d ", MI[i][j]);
		printf("\n");
	}
	printf("Matritsa Smejnosti\n");
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			printf("%2d ", MS[i][j]);
		printf("\n");
	}
	printf("\n\tspisok smeznosti\n");
	for (int i = 1; i <= n; i++) {
		printf("%d : ", i);
		lnk tmp = adj[i - 1];
		while (tmp) {
			printf("%d ", tmp->v + 1);
			tmp = tmp->next;
		}
		printf("0\n");
	}
}
void main()
{
	printf("Vvedi kol-vo ver6in i Dug\n");
	scanf_s("%d%d", &n, &m);
	printf("Sposob vvoda\n1.Matritsa Intidentnosti\n2.Matritsa Smejnosti\n3.Spisok Smejnosti\n");
	scanf_s("%d", &k);

	switch (k) {
		case 1:	FMI(); 	FMIvMS();	FMSvSS(); break;
		case 2:	FMS();	FMSvSS();	FSSvMI(); break;
		case 3:	FSS();	FSSvMI();	FMIvMS(); break;
	}
	printm();

	_getch();
}