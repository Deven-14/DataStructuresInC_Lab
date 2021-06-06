#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str=(char*)malloc(300*sizeof(char));
	FILE *fp;
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{
		perror("Error opening file\n");
		exit(1);
	}
	//fgets(str,200,fp);//accept only one continous line
	int i=0;
	char ch;
	while((ch=fgetc(fp))!=EOF)
		str[i++]=ch;
	str[i]='\0';
	if(str==NULL)
	    exit(1);
	printf("The text is:\n");
	printf("%s\n",str);
	int count_c=0,count_w=0,count_l=0;
	/*i=0;
	while(str[i]!='\0')
	{
		while(str[i]!='\n' && str[i]!='\0')
		{
			while(str[i]!='.')
			{
				while(str[i]!=' ' && str[i]!='.'){//spaces are not counted as characters
					count_c++;
					i++;
				}
				if(str[i]==' ')
					i++;
				count_w++;
			}
			count_l++;
			i++;
			if(str[i]==' ')
				i++;
		}
		if(str[i]=='\n')
			i++;
	}
	*/
	int len=strlen(str);
	for(i=0;i<len;++i)
	{
		count_c++;
		if(str[i]=='\n'){
			count_w++;
			count_l++;
		}
		if(str[i]==' ')
			count_w++;
	}
	if(count_c>0){//for last word
		count_w++;
		count_l++;
	}
	printf("The number of characters(including \\n and whitespaces)=%d, words=%d, line=%d\n",count_c,count_w,count_l);
	free(str);
	fclose(fp);	
	return 0;
}
