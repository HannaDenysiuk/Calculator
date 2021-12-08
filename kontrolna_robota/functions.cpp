#include "Header.h"

int scob(char* mass)
{
	stack <char> st;
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if ((mass[i] >= '0' || mass[i] <= '9' || mass[i] == '.') && mass[i + 1] == '(')
			return 1;
		if ( mass[i + 1] == ')'&&(mass[i+1] >= '0' || mass[i+1] <= '9' || mass[i+1] == '.'))
			return 1;
		if (mass[i] == '(')
			st.push(mass[i]); 
		if (mass[i] == ')' && st.empty())
			st.push(mass[i]);
		if (mass[i] == ')' && st.top() == '(')
			st.pop();
	}
	if(st.empty())
	return 0;
	else 
	return 1;
}

char* perevod(double a)
{
	char* tmp = new char[100];
	FILE* fp = fopen("newfile.txt", "w+");
    fprintf(fp, "%f",a);
	fclose(fp);
	fp=fopen("newfile.txt", "r");
	fscanf(fp, "%s", tmp);
	fclose(fp);
	return tmp;
}

float str(char*mass)
{
	int k = 0,c=0;
	char* arr = new char[50];
	double* num = new double[50];
	char* tmp1 = new char[200];
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if(mass[i]=='(')
			k = i+1;
		if (mass[i] == ')')
		{
			strcpy(tmp1, mass);
			c = i + 1;
			int h = 0;
			for (int j = k; mass[j] != ')'; h++, j++)
				arr[h] = mass[j];
			arr[h] = '\0';
			char tmp[50];
			float t = rezult2(arr, num);
			strcpy(tmp, perevod(t));
			k--;
			for (int p = 0; tmp[p] != '\0'; p++, k++)
				mass[k] = tmp[p];
			k--;
			for (; tmp1[c] != '\0'; k++,c++)
					mass[k] = tmp1[c];
			mass[k] = '\0';
				i = 0; k = 0; c = 0;
		}
	}
	return rezult2(mass, num);
}

int  rozbir(char*& mass,double*& num)
{
	int k=0,j=0,h=0;
	char* arr = new char[200]{ '\0' };
	char* znak = new char[30];
	
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if (mass[i] >= '0'&& mass[i] <= '9' || mass[i] == '.')
		{
			arr[k] = mass[i];
		    k++;
	    }
		else
		{
			znak[j] = mass[i];
			j++;
			if (arr[0]!= '\0') {
				num[h] = atof(arr);
				h++;
				for (int l = 0; l < k; l++)
					arr[l] = '\0';
				k = 0;
			}
		}
	}
	if (arr[0] != '\0') {
		num[h] = atof(arr);
		h++;
	}
	znak[j] = '\0';
	strcpy(mass, znak);
	return h;
}

int rezult(char*& mass, double*& num)
{
	int h=rozbir(mass, num);
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if (mass[i] == '*')
		{
			num[i] *=num[i + 1];
			for (int j = i + 1; j < h - 1; j++)
				num[j] = num[j + 1];
			h--;
			for (int k = i; mass[k] != '\0'; k++)
				mass[k] = mass[k + 1];
			i--;
		}
		if (mass[i] == '/')
		{
			num[i] /= num[i + 1];
			for (int j = i + 1; j < h - 1; j++)
				num[j] = num[j + 1];
			h--;
			for (int k = i; mass[k] != '\0'; k++)
				mass[k] = mass[k + 1];
			i--;
		}
	}
	return h;
}

double rezult2(char*& mass, double*& num)
{
	int h = rezult(mass, num);
	for (int i = 0; mass[i] != '\0'; i++)
	{
		if (mass[i] == '+')
		{
			num[i] += num[i + 1];
			for (int j = i + 1; j < h - 1; j++)
				num[j] = num[j + 1];
			h--;
			for (int k = i; mass[k] != '\0'; k++)
				mass[k] = mass[k + 1];
			i--;
		}
		if (mass[i] == '-')
		{
			num[i] -= num[i + 1];
			for (int j = i + 1; j < h - 1; j++)
				num[j] = num[j + 1];
			h--;
			for (int k = i; mass[k] != '\0'; k++)
				mass[k] = mass[k + 1];
			i--;
		}
	}
	return num[0];
}