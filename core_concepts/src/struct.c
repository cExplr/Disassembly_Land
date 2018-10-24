#include<stdio.h>

struct s1{
	int x;
	int y;
};

int main(){

	struct s1 ex;
	ex.x = 14;
	ex.y = 20;
	printf("ex.x => %d, ex.y => %d\n",ex.x, ex.y);

	return 0;
}
