#include<stdio.h>
int a[50],b[50],i,j,n,f,h,ch,head_pos,final,initial,res;
void fcfs();
void scan();
void cscan();
void main()
{
	do
	{
		int a[50],n;
		printf("1 FCFS\n 2 SCAN\n 3 CSCAN\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:fcfs();
				break;
			case 2: scan();
				break;
			case 3: cscan();
				break;
			
		}
		printf("Tap 1 to continue\n");
		scanf("%d",&f);
	}while(f==1);
}
void fcfs()
{
	        printf("Enter the number of request\n");
		scanf("%d",&n);
		printf("Enter the request in order\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("Requests  are:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		printf("Enter the head start\n");
		scanf("%d",&head_pos);
		initial=head_pos;
		printf("_______Disk traversal_______\n");
		printf("%d->",head_pos);
		for(i=0;i<n;i++)
		{
			final=a[i];
			printf("%d",final);
			if(i!=n-1)
			{
            			printf("->");
            		}
        		if(final>initial)
        		{
            			res+=final-initial;
            		}
            		else
            		{
            		
            			res+=initial-final;
            		}
            		initial=final;
            	}
            	 printf("\n\nTotal head movements=%d cylinders\n",res);
}
void scan()
{
	int n,a[20],head,diff,min=10000,loc=-1;
	int c,st,ed,k,res,val,count=0,x;
	printf("Enter the number of requests:\n");
	scanf("%d",&n);
	printf("Enter the requests in order \n");
	for(int i=0;i<n;i++)
	{
	
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Enter the head position\n");
	scanf("%d",&head);
	printf("Enter the total size of disk:\n");
	scanf("%d",&c);
	st=0;
	ed=c-1;
	printf("\n_________Disk Traversal________\n");
	printf("%d->",head);
	if(head<(ed-head))
	{
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]<head)
			{
				count++;
				x=a[i];
				printf("%d",a[i]);
				if(count!=n)
					printf("->");
			}
		}
		if(count!=n)
		{
			printf("0->");
			x=st;
			for(int i=0;i<n;i++)
			{
				if(a[i]>head)
				{
					count++;
					val=a[i];
					printf("%d",a[i]);
					if(count!=n)
					{
						printf("->");
					}
				}
			}
		}
		if(x==st)
		{
			res=(head-x)+(val-x);
		}
		else
		{
			res=head-x;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>head)
			{
				x=a[i];
				count++;
				printf("%d",a[i]);
				if(count!=n)
				{
				
					printf("->");
				}
			}
		}
		if(count!=n)
		{
			printf("%d->",ed);
			x=ed;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]<head)
				{
					count++;
					val=a[i];
					printf("%d",a[i]);
					if(count!=n)
					{
					
						printf("->");
					}
				}
			}
		}
		if(x==ed)
		{
			res=(x-head)+(x-val);
		
		}
		else
		{
			res=x-head;
		}
	}	
	printf("\n\nTotal head movements=%d cylinders\n",res);
}
void cscan()
{
	int n,a[20],head,diff,min=10000,loc=-1;
	int c,st,ed,k,res,val,count=0,x;
	printf("Enter the number of requests:\n");
	scanf("%d",&n);
	printf("Enter the requests in order\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Enter the head position\n");
	scanf("%d",&head);
	printf("Enter the total size of disk:\n");
	scanf("%d",&c);
	st=0;
	ed=c-1;
	printf("\n_________Disk Traversal_________\n");
	printf("%d->",head);
	if(head<(ed-head))
	{
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]<head)
			{
				count++;
				x=a[i];
				printf("%d",a[i]);
				if(count!=n)
					printf("->");
			}
		}
		if(count!=n)
		{
			printf("%d->%d->",st,ed);
			x=st;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]>head)
				{
					count++;
					val=a[i];
					printf("%d",a[i]);
					if(count!=n)
						printf("->");
				}
			}
		}
		if(x==st)
		{
			res=head+ed+(ed-val);
		}
		else
		{
			res=head-x;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>head)
			{
				x=a[i];
				count++;
				printf("%d",a[i]);
				if(count!=n)
				{
					printf("->");
				}
			}
		}
		if(count!=n)
		{
			printf("%d->%d->",ed,st);
			x=ed;
			for(int i=0;i<n;i++)
			{
				if(a[i]<head)
				{
					count++;
					val=a[i];
					printf("%d",a[i]);
					if(count!=n)
					{
						printf("->");
					}
				}
			}
		}
		if(x==ed)
		{
			res=(ed-head)+ed+val;
		}
		else
		{
			res=x-head;
		}
	}	
	printf("\n\nTotal head movements=%d cylinders\n",res);
}
