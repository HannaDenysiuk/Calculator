#include "Header.h"
//calculator
int main()
{
	int c, e;
	cout << "list of proposed actions\t+ - * / ( )\nif you want stop this programm - enter \"stop\"\n";
	char* exp = new char[200];
	char p[5] = "stop" ;
	do{
		c = 0; e = 0;
	cout << "enter your arithmetic expressions\n";
	cin.clear();
	cin.getline(exp, 100);
	if (strcmp(exp,p) == 0)
	    return 0;
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if ((int)exp[i] < 39 || (int)exp[i]>57|| (int)exp[i]==44)
			e++;
		c = scob(exp);
	}
	if (c != 0 || e != 0)
		continue;
	cout << "equal\t" << str(exp) << endl;
	} while (c != 0||e!=0|| strcmp(exp, p) != 0);
	return 0;
}