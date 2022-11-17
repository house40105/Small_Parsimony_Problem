#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	FILE *ptr;
	int count=0;
	char temp;
	char text[]={'A','T','C','G'};
	ptr=fopen("1.txt","r");

	while (!feof(ptr))
	{
		fscanf(ptr,"%c",&temp);
		if(temp=='\n')
			count++;
	}
	count++;
	rewind(ptr);

	char *lable=(char *)malloc(sizeof(char)*count);
	int **idx=(int **)malloc(sizeof(void *)*count);//link
	for(int i = 0; i < count; i++)
	{
		idx[i]=(int *)malloc(sizeof(int *)*3);
		idx[i][0]=-1;idx[i][1]=-1;idx[i][2]=-1;
	}
	int **S=(int **)malloc(sizeof(void *)*count);//A T C G 
	for(int i = 0; i < count; i++)
	{
		S[i]=(int *)malloc(sizeof(int *)*4);
		S[i][0]=0;S[i][1]=0;S[i][2]=0;S[i][3]=0;
	}

	int index=0;
	char c1,c2,c3;
	int t1=0,t2=0,t3=0;
	while (!feof(ptr))
	{
		fscanf(ptr,"%d%c%c%c",&index,&c1,&c2,&c3);
		lable[index]=c2;
		if(t2==1)
		{
			idx[index][2]=t1;
			idx[t1][t3]=index;
			t3++;
		}
		if(t1==index)
			t2=1;
		if(c3=='\n')
		{
			t1++; t2=0; t3=0;
		}
	}

	for(int i=0;i<count;i++)//底
	{
		if(lable[i]!=NULL)
		{
			if(lable[i]=='A')
				S[i][0]=1;
			if(lable[i]=='T')
				S[i][1]=1;
			if(lable[i]=='C')
				S[i][2]=1;
			if(lable[i]=='G')
				S[i][3]=1;
		}
	}
	for(int i=count-1;i>=0;i--)//找聯集
	{
		if(idx[i][0]!=-1)
		{
			for(int j=0;j<4;j++)
			{
				if(S[idx[i][0]][j]==1)
					S[i][j]=1;
			}
		}
		if(idx[i][1]!=-1)
		{
			for(int j=0;j<4;j++)
			{
				if(S[idx[i][1]][j]==1)
					S[i][j]=1;
			}
		}
	}

	for(int i=0;i<count;i++)//找lable
	{
		if(idx[i][2]==-1)
		{
			for(int j=0;j<4;j++)
			{
				if(S[idx[i][0]][j]==1&&S[idx[i][1]][j]==1)
				{
					lable[i]=text[j];
					break;
				}
			}
		}
		else
		{
			for(int j=0;j<4;j++)
			{
				if(S[i][j]==1)
					if(lable[idx[i][2]]==text[j])
					{
						lable[i]=text[j];
						break;
					}
			}
		}
	}
	int total=0;//算分數
	for(int i=0;i<count;i++)
	{
		if(idx[i][0]!=-1)
		{
			if(lable[i]!=lable[idx[i][0]])
				total++;
			if(lable[i]!=lable[idx[i][1]])
				total++;
		}
	}

	FILE *wptr;
	wptr=fopen("output.txt","w");
	for(int i=0;i<count;i++)
	{
		if(idx[i][0]!=-1)
		{
			fprintf(wptr,"%d,%c ",i,lable[i]);
			fprintf(wptr,"%d,%c ",idx[i][0],lable[idx[i][0]]);
			fprintf(wptr,"%d,%c ",idx[i][1],lable[idx[i][1]]);
			fprintf(wptr,"\n");
		}
		else
		{
			fprintf(wptr,"%d,%c \n",i,lable[i]);
		}
	}
	fprintf(wptr,"\n\nTotal score: %d",total);









	for(int i=0;i<count;i++)
	{
		printf("%c,%d %d %d\n",lable[i],idx[i][0],idx[i][1],idx[i][2]);
	}
	printf("\n");
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",S[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<count;i++)
	{
		printf("%c ",lable[i]);
	}
	printf("\nTotal score:%d\n",total);


	fclose(ptr);
	fclose(wptr);
	system("pause");
}