/* @author 
	Augie Winanda F 
	*/

#include <stdio.h>
#include <string.h>

char user[5][100], pass[5][100], userlog[100], passlog[100], passbar[100];
int pilih, n = 0;
char lagi;

void reg();
void login();
void update(int x);

int main()
{
	fflush(stdin);
	printf("\n>>>>>MENU<<<<<\n");
	printf("1. Register\n");
	printf("2. Login\n");
	printf("3. Exit\n");
	printf("Pilihan anda : ");
	scanf("%i", &pilih);

	switch(pilih)
	{
	case 1:
		reg();
		break;
	case 2:
		login();
		break;
	case 3:
		return 0;
		break;
	default:

		break;
	}

	return 0;
}

void reg()
{
	if(n == 5)
	{
		printf("\nMELEBIHI BATAS!!!\n");
		main();
	}
	else
	{
		fflush(stdin);
		printf("\n>>>>>REGISTER<<<<<\n");
		printf("Username : ");
		gets(user[n]);
		printf("Password : ");
		gets(pass[n]);
		n++;
		printf("\nRegister lagi ? (y/n) ");
		scanf("%c", &lagi);
		if(lagi == 'y' || lagi == 'Y')
		{
			reg();
		}
		else
		{
			main();
		}
	}
}

void login()
{
	if(n == 0)
	{
		printf("Silahkan Register Dahulu\n");
		main();
	}
	else
	{
		fflush(stdin);
		printf("\n>>>>>LOGIN<<<<<\n");
		printf("User : ");
		gets(userlog);
		printf("Pass : ");
		gets(passlog);
		for(int i = 0 ; i < n ; i++)
		{
			if(strcmp(user[i], userlog) == 0)
			{
				if(strcmp(pass[i], passlog) == 0)
				{
					printf("SELAMAT DATANG, %s", user[i]);
					printf("\n\nUpdate Password ? (y/n) ");
					scanf("%c", &lagi);
					if(lagi == 'y' || lagi == 'Y')
					{
						update(i);
						break;
					}
					else
					{
						main();
						break;
					}
					break;
				}
				else
				{
					printf("Password Salah!!!\n");
					main();
					break;
				}
			}
			else
			{
				continue;
			}
		}
	}
}

void update(int x)
{
	fflush(stdin);
	printf("Password baru : ");
	gets(passbar);
	strcpy(pass[x], passbar);
	printf("Password berhasil update :)\n");
	main();
}
