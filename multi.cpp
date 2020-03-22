#include<stdio.h>
#include<conio.h>
#define max 10
#define ity 1000
int w[max][max];
int n;
int p[max];
void indat()
{
	printf("\n\t Multi-Stage Graph \n");
	printf("\n Enter the number of nodes : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		w[i][i] = 0;
		for(int j=i+1;j<n;j++)
		{
			printf("Enter the weight of edge '%c' to '%c': ",65+i,65+j);
			scanf("%d",&w[i][j]);
			w[j][i] = 0;
		}
	}
}
void disdat()
{
	printf("\n The Path adjacent matrix \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("\t %d",w[i][j]);
	}
	fflush(stdin);
}
int findshort(int sr,int dst)
{
	if(sr == dst)
		return 0;
	else
	{
		int tdst, ret = -1;
		int min = ity;
		for(int i=0;i<n;i++)
		{
			if(w[sr][i] != 0)
			{
				ret = 0;
				tdst = w[sr][i]+findshort(i,dst);
				if(min >tdst)
				{
					min = tdst;
					p[sr] = i;
				}
			}
		}	
		if(ret == -1)
			return ity;
		else
	    	return min;
	}
}
void MSG()
{
	char s,d;
	int si,di;
	printf("\nEnter the source and destination node : ");
	scanf("%c %c",&s,&d);
	fflush(stdin);
	si = (int) s-65;
	di = (int) d-65;
	int dist = findshort(si,di);
	if(dist >= ity)
		printf("\n The shortest distance between '%c' and '%c' can't be computed");
	else
	{
		printf("\n The shortest distance between '%c' and '%c' : %d",s,d,dist);
		printf("\n The shortest path : %c",s);
		while(si!=di)
		{
			printf(" %c",65+p[si]);
			si = p[si];
		}
	}
}
int main()
{
	indat();
	disdat();
	MSG();
	return 0;
}
