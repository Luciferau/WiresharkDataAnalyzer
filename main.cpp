#define _CRT_SECURE_NO_WARINIGS 
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
 


int main(void)	
{
	char line[1024] = { '\0' };
	char ip[16] = { '\0' };
	FILE * pFile = NULL;
	int count = 0;
	printf("please input you file name £º\n",line); 
	scanf("%s", line);
	printf("you input file name is£º%s \n start to search friend ip \n",line); 
	pFile = fopen(line, "r");
	if (pFile == NULL) {
		printf("Fiel open error£¡ \n \n    reason£º%s \n \n", strerror(errno));
		system("pause");
		return 0;
	}
	else
	{
		
		printf("files open successed \n");
		Sleep(2000);
		system("cls");
		system("color a");
	}

	while (!feof(pFile)) {
		fgets(line,1024, pFile);

		if (strstr(line, "Len=72") && strstr(line, "UDP	114")) {//114
			
			if (count < 3)
			{
				int no = 0;
				char time[16] = { '\0' };
				char myIP[32] = { '\0' };
				char friendIP[32] = { '\0' };
				sscanf(line, "%d %s %s %s *", &no, time, myIP, friendIP);

				if (strncmp(friendIP, "192", 4) == 0 || strncmp (friendIP,"10.",3) == 0)
				{
					continue;
	
				}
				count++;
				printf("Your IP is£º%s \n \n  Your friends IP is£º%s \n \n", myIP, friendIP);

			}
		}
	}
	fclose(pFile);
	getchar();
 


	return 0;
}