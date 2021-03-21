#include<stdio.h>
#include<string.h>
char user[10];
void Graphic()
{
	int i,j=0;
	printf("\a\n********************************************************************************");
	printf("********************************************************************************\nHi ");
	for( j = 0; j!=strlen(user);++j)
	{for(i=0;i!=100000000;++i);
	printf("%c",user[j]);}
}
int compare(char UserName[],char Password[])
{
	int i=0,j=0,z;
	char name[10];
	char test[10],a[10][10],b[10][10];
	strcpy(test,"#");
	strcat(test,UserName);
	strcpy(UserName,test);
	strcpy(test,"$");
	strcat(test,Password);
	strcpy(Password,test);
	FILE *ac;
	ac=fopen("math.txt","r");
	while(!feof(ac))
	{
		fscanf(ac,"%s",name);
		if (name[0] == '#')
		{
			strcpy(a[i],name);
			++i;
		}
		if (name[0] == '$')
		{
			strcpy(b[j],name);
			++j;
		}
	}
	fclose(ac);
	z=i;
	for(i=0;i<z;++i)
	{
		if(strlen(Password)==strlen(b[i]) && strlen(UserName)==strlen(a[i]) && !strcmp(UserName,a[i]) && !strcmp(Password,b[i]))
			return 1;
	}
	return 0;
}
int SignUpPage()
{
	char Name[10],Password[10],choos;
	printf("\a99) back\n1) Answer the Q\n");
	while(1)
		{
			printf(">>>");
			scanf("%d",&choos);
			if (choos != 1 && choos != 99)
				{
					printf("Eroor!\n");
					continue;
				}
			if(choos == 1)
			{
				printf("Name: ");
				scanf("%s",Name);
				strcpy(user,Name);
				printf("Pass: ");
				scanf("%s",Password);
				FILE *ab;
				ab=fopen("math.txt","a");
				fprintf(ab,"\n#%s $%s",Name,Password);
				fclose(ab);
				return 2;			
			}
			else
				return 99;	
		}
}
int LoginPage()
{
	char UserName[10],Password[10];
	printf("\a99) back\n");
	while(1)
	{
		printf("User Name: ");
		scanf("%s",UserName);
		strcpy(user,UserName);
		if (strlen(UserName)==2 &&!strcmp(UserName,"99"))
			return 99;
		printf("Password: ");
		scanf("%s",&Password);
		if (strlen(Password)==2 &&!strcmp(Password,"99"))
			return 99;
		if(compare(UserName,Password))
		{
			break;
		}
		printf("invalid password!\n");			
	}
	return 1;
	
}
void StartPage()
{
	int num,send;
	printf("\a1) login\n2) singup\n");
	while(1)
	{
		printf(">>> ");
		scanf("%d",&num);	
		if (num ==1 || num==2)
		break;
		else printf("Erorr!\n");
	}	
	if (num==1)
	{
		send = LoginPage();
		if(send == 1)
			return;
		else
			return StartPage();	
	}
	else
	{
		send=SignUpPage();
		if(send == 2)
			return;
		else
			return StartPage();	
	}
	
}
main()
{
	StartPage();
	Graphic();
}
