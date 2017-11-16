#include<stdio.h>
#include<math.h>
#define cmp_dest 7
#define cmp_compa1 10
#define cmp_compa0 18
#define cmp_jmp 7
struct compa0
{
	char operation[4];
	char opcode[7];
};
struct compa1
{
	char operation[4];
	char opcode[7];
};
struct dest
{
	char operation[4];
	char opcode[4];
};
struct jmp
{
	char operation[4];
	char opcode[4];
};
int numberconvert(char a[]);
void convertbinary(int a);
void compjumpdest(char a[]);

int main()
{
	FILE *a, *d;
	FILE *test;
	test= fopen("add.hack","a");
	char b[100], c[100], hold[18];
	int i;
	printf("Enter the full name of the file\n::");
	scanf("%s", c);
	if ((a = fopen( c, "r")) == NULL)//open asm file
	{
		puts("file not found");
	}
	else//start open file
	{
		
		for (i = 0; c[i] != '.'; i++)
		{
			c[i] = c[i];
		}
		c[i + 1] = 'h';
		c[i + 2] = 'a';
		c[i + 3] = 'c';
		c[i + 4] = 'k';
		c[i + 5] = '\0';
		d = fopen(c, "a");//create hack file
		fclose(d);//close the hack file
		fscanf(a, "%s", b);		//scan from file
		while (!feof(a))
		{	
			//if the first scan shows @
			if(b[0] == '@')
			{
				if(isdigit(b[1])) //do for every intiger after @
				{
					convertbinary(numberconvert(b));
					//puts("");
				}
				else //do for every predifine intiger or user input intiger
				{
					///////////////////do for @fish/@cat/ect
				}
			}
			else//do for comp, dest n jump
			{
				compjumpdest(b);
			}
			fscanf(a, "%s", b);		//scan from file
			puts("");
		}//end main while
	
		puts("");
		fclose(a);
		fclose(test);
	}//end if else
}
int numberconvert(char a[])
{
	char b = '0';
	int c = 0, i = -1, d = 0, e = 0;
	for (c = 0; a[c] != '\0'; c++)
	{
		a[c] = a[c + 1];
		//printf("%c", a[c]);
	}
	while (a[i] != '\0')
	{
		i++;
	//	printf("i = %d\n", i);
	}
	i--;
	if(i == 2)
	{
		e += 1;
	}
	for (c = 0; a[c] != '\0'; c++)
	{
		while (b != a[c])
		{
			b = b + 1;
			d++;
		}
		e = e + (d * pow(10, i));
	//	printf("e = %d\n", e);
		i--;
		b = '0';
		d = 0;
	}
	
	return e;
}
void convertbinary(int a)
{
	FILE *test;
	test= fopen("add.hack","a");
	int b[16] = {0};
	int i = 0;
	for (i = 0; i <= 15; i++)
	{
		b[i] = a % 2;
		a = a / 2;
//		printf("i before = %d\n", i);
	}
//	printf("\n\ni middle = %d\n\n", i);
	for (i = 15; i >= 0; i--)
	{
		fprintf(test,"%d", b[i]);
		printf("%d", b[i]);
		//printf("i after = %d\n", i);
	}
	fprintf(test,"\n", b[i]);

}
void compjumpdest(char a[])
{
	FILE *test;
	test= fopen("add.hack","a");
	char destination[5], jumpcom[10], eqsemi;
	int i, j = 0;
	for (i = 0; a[i] != '\0'; i++)
	{
		//for comp
		if (a[i] == '=')
		{
			eqsemi = a[i];
			i++;
			for (j = i; a[j] != '\0'; j++)
			{
				jumpcom[j - i] = a[j];
			}
			jumpcom[j - i] = '\0';
			break;
		}//end for comp
		//for jump
		else if (a[i] == ';')
		{
			eqsemi = a[i];
			i++;
			for (j = i; a[j] != '\0'; j++)
			{
				jumpcom[j - i] = a[j];
			}
			jumpcom[j - i] = '\0';
			break;
		}//end for jump
		//for dest
		destination[i] = a[i];
	}//end loop
	destination[i - 1] = '\0';
	//printf("%s", destination);
	//printf("%c", eqsemi);
	//printf("%s\n", jumpcom);
	
	struct dest gobdest[cmp_dest] = {{"M", "001"}, {"D", "010"}, {"MD", "011"}, {"A", "100"}, {"AM", "101"}, {"AD", "110"}, {"AMD", "111"}};
	struct compa1 gobcompa1[cmp_compa1] = {{"M", "110000"}, {"!M", "110001"}, {"-M", "110011"}, {"M+1", "110111"}, {"M-1", "110010"}, {"D+M", "000010"}, {"D-M", "010011"}, {"M-D", "000111"}, {"D&M", "000000"}, {"D|A", "010101"}};
	struct compa0 gobcompa0[cmp_compa0] = {{"0", "101010"}, {"1", "111111"}, {"-1", "111010"}, {"D", "001100"}, {"A", "110000"}, {"!D", "001101"}, {"!A", "110001"}, {"-D", "001111"}, {"-A", "110011"}, {"D+1", "011111"}, {"A+1", "110111"}, {"D-1", "001110"}, {"A-1", "110010"}, {"D+A", "000010"}, {"D-A", "010011"}, {"A-D", "000111"}, {"D&A", "000000"}, {"D|A", "010101"}};
	struct jmp gobjmp[cmp_jmp] = {{"JGT", "001"}, {"JEQ", "010"}, {"JGE", "011"}, {"JLT", "100"}, {"JNE", "101"}, {"JLE", "110"}, {"JMP", "111"}};
	int k;
	if (eqsemi == '=')
	{
		for (i = 0; i < cmp_dest; i++)
		{
		//	printf("compare between %s and %s for dest\n", gobdest[i].operation, destination);
			if (strcmp(gobdest[i].operation, destination) == 0)
			break;
		}
		for (j = 0; j < cmp_compa0; j++)
		{
		//	printf("compare between %s and %s if k = 0\n", gobcompa0[j].operation, jumpcom);
			if (strcmp(gobcompa0[j].operation, jumpcom) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k != 1)
		{
		//	printf("compare between %s and %s if k = 1\n", gobcompa1[j].operation, jumpcom);
			for (j = 0; j < cmp_compa1; j++)
			{
				if (strcmp(gobcompa1[j].operation, jumpcom) == 0)
				{
					k = 2;
					break;
				}
			}
		}
		printf("111%d%s%s000", k - 1, k - 1? gobcompa1[j].opcode : gobcompa0[j].opcode, gobdest[i].opcode);
		fprintf(test,"111%d%s%s000", k - 1, k - 1? gobcompa1[j].opcode : gobcompa0[j].opcode, gobdest[i].opcode);
		fprintf(test,"\n");
	} 
	else if (eqsemi == ';')
	{
		for (i = 0; i < cmp_compa0; i++)
		{
			//printf("Compare %s with %s, opcode = %s i is %d\n", gobcompa0[i].operation, destination, gobcompa0[i].opcode, i);
			if (strcmp(gobcompa0[i].operation, destination) == 0)
			{
				k = 1;
				break;
			}
		}
		if (k != 1)
		{
			for (i = 0; i < cmp_compa1; i++)
			{
				if (strcmp(gobcompa1[i].operation, destination) == 0)
				{
					k = 2;
					break;
				}
			}
		}
		
		for (j = 0; j < cmp_jmp; j++)
		{
			if (strcmp(gobjmp[j].operation, jumpcom) == 0)
			{
				break;
			}
		}
		printf("111%d%s000%s", k - 1, k - 1? gobcompa1[i].opcode : gobcompa0[i].opcode, gobjmp[j].opcode);
		fprintf(test,"111%d%s%s000", k - 1, k - 1? gobcompa1[j].opcode : gobcompa0[j].opcode, gobdest[i].opcode);
		fprintf(test,"\n");
	}
//	fprintf(test,"\n");
//	fclose(test);
}
