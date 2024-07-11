#include <stdio.h>
void main()
{
	int a[20],page[10],recent[10],r,f,flag=0,put=0,miss=0,i,j,k=0,c=0,loc,min;
	printf("enter the number of references in reference string:");
	scanf("%d",&r);
	printf("\n enter the reference string");
	for(i=0;i<r;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nenter the number of frames");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		page[i]=-1;
		recent[i]=-1;
	}
	printf("PAGE REPLCEMENTS \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<f;j++)
		{
			if(a[i]==page[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			if(c<f)
			{
				page[c]=a[i];
				recent[c]=i;
				c++;
			}
			else
			{
				min=recent[0];
				loc=0;
				for(j=1;j<f;j++)
				{
					if(recent[j]<min)
					{
						min=recent[j];
						loc=j;
					}
				}
				page[loc]=a[i];
				recent[loc]=i;
			}
			mis++;
		}
		else
		{
			recent[j]=i;
			flag=0;
		}
		printf("current frame:");
		for(j=0;j<f;j++)
		{
			printf("%d\t",page[j]);
		}
		printf("\n");
	}
	printf("PAGE FAULT=%d",miss);
}
