#include <stdio.h>
#include <string.h>
#include <ctype.h>
int arr[100],l,temp[100],done[100];
void Permutate(int i)
{
	int j,prev=-1;
	if(i==l)
	{
		for(j=0;j<l;j++)
		{
			if(temp[j]&1)
			  printf("%c",((temp[j]-1)/2)+'a');
			else
			  printf("%c",(temp[j]/2)+'A');
		}
		printf("\n");
		return;
	}
	for(j=0;j<l;j++)
	 if(!done[j] && arr[j]!=prev)
	 {
	 	done[j]=1;
	 	temp[i] = arr[j];
	 	prev = arr[j];
	 	Permutate(i+1);
	 	done[j]=0;
	 }
	 
}
int main()
{
	int n,i,c,prev;
	char s[100];
	scanf("%d",&n);
	gets(s);
	memset(done,0,sizeof(int)*100);
	while(n--)
	{
		gets(s);
		l = strlen(s);
		for(i=0;i<l;i++)
		{
			if(islower(s[i]))
			  arr[i] = (2*(s[i]-'a'))+1;
			else
			  arr[i] = (2*(s[i]-'A'));
		}
		c=0;
		prev=-1;
		memset(temp,0,sizeof(int)*52);
		for(i=0;i<l;i++)
		  temp[arr[i]]++;
		for(i=0;i<52;i++)
		 while(temp[i]--)
		 {
		 	arr[c++] = i;
		 }
		for(i=0;i<l;i++)
	 	{
	 	 if(arr[i]!=prev)
	 	 {
	 	    done[i]=1;
	 	    temp[0] = arr[i];
	 	    prev = arr[i];
	 	    Permutate(1);
	 	    done[i]=0;
	 	}
	    }
	}
	return 0;
}


