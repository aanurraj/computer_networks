#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char data[20],f[20],received[20];
	int red[20],error[20];
	int cl,d,i,rc,l,x=0,count,q,j,o,sum=0,k,s=0,er=0,flag=0,ersum=0,h=0,p=0;
	printf("Enter the data : ");
	scanf("%s",data);
	d=strlen(data);
	cl=(d/2)+1;
	for(i=0;i<cl;i++)
	{
		if(pow(2,i)>=d+i+1)
		{
			break;
		}
		rc=i;

	}
	for(i=0;i<=rc;i++)
	{
		l=pow(2,i);
		red[i]=l;
		f[l-1]='0';
	}
	count=d+rc;
	for(i=1;i<=count;i++)
	{
		if(f[i]!='0')
		{
			f[i]=data[x];
			x++;
		}
	}
	for(i=0;i<=rc;i++)
	{
		o=red[i];
		o--;
		for(j=o;j<=count;(j=j+2*red[i]))
		{
			for(k=j;k<j+red[i];k++)
			{
				if(f[k]=='1')
				{
					sum++;
				}
			}

			
		}
        q=red[i];
        if(sum%2!=0)
        {
        	f[q-1]='1';
        }
        sum=0;
	}
	printf("The transmitted data is : %s\n",f);
	printf("Enter the received data : ");
	scanf("%s",received);
	for(i=0;i<=rc;i++)
	{
		l=pow(2,i);
		red[i]=l;
		f[l-1]='0';
	}
	count=d+rc;
	for(i=1;i<=count;i++)
	{
		if(f[i]!='0')
		{
			f[i]=data[x];
			x++;
		}
	}
	for(i=0;i<=rc;i++)
	{
		o=red[i];
		o--;
		for(j=o;j<=count;(j=j+2*red[i]))
		{
			for(k=j;k<j+red[i];k++)
			{
				if(received[k]=='1')
				{
					sum++;
				}
			}	
		}
		q=red[i];
        if(sum%2!=0)
        {
        	flag=1;
        	error[er]=1;
        	er++;
        }
        else
        {
        	error[er]=0;
        	er++;
        }
        sum=0;
	}
	if(flag==1)
	{
		
		for(i=0;i<=rc;i++)
		{
			l=pow(2,i);
			if(error[h]==1)
			{
				ersum+=l;
			}
			h++;
		}
		printf("The Error is at position %d of data %s\n",ersum,received);
		if(received[ersum-1]=='1')
		{
			received[ersum-1]='0';
		}
		else
		{
			received[ersum-1]='1';
		}
		printf("The corrected data is : %s\n",received);
	}
	else
	{
		printf("No Error\n");
	}
	return 0;
}