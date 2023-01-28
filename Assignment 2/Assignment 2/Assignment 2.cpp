#include<iostream>
#include<string>
using namespace std;
#define Max 10

int Find_length(char S1[], int& len1);
void Create_String(char S1[], int& len1) {

	int size = 500;
	int i = 0;
	try
	{
		cin.ignore();
		cin.getline(S1, size);
		Find_length(S1, len1);
		if (len1 > Max) {
			throw i;
		}

	}
	catch (int i)
	{
		cout << "Plz enter less then " << Max << " Characters" << endl;

	}

}
int Find_length(char S1[], int& len1) {
	len1 = 0;
	while (S1[len1] != NULL)
	{
		len1++;
	}

	return len1;
}
void display(char S1[], char S2[]) {
	cout << "First String: " << S1 << endl;
	cout << "Second String: " << S2 << endl;


}
int Merge(char S1[], char S2[], char S3[], int& len1, int& len2) {

	len1 = 0;
	len2 = 0;
	S3[len2] = NULL;
	while (S1[len1] != NULL)
	{
		S3[len1] = S1[len1];
		len1++;
	}
	len2 = len1 + 1;
	S3[len1] = ' ';

	len1 = 0;

	while (S2[len2] != NULL)
	{
		S3[len2] = S2[len1];
		len1++;
		len2++;
	}
	S3[len2] = NULL;
	return S3[Max];
}
void Search(char S1[], char S2[], int& len1, int &len2, bool &found)
{
	len1 = 0;
	len2 = 0;
	int i = Find_length(S2, len1);
	int j = 0;
	len1 = 0;
	found = false;
	while (S1[len1] != NULL)
	{
		if (S2[len2] == S1[len1]) {
			while (S2[len2!=NULL])
			{
				if (S2[len2] == S1[len1]) {
					j++;
				}

				else {
					
					break;
				}
			len1++;
			len2++;
			
			}
			break;
		}
		len1++;

		
	}
	if (i == j)
	{
		
		cout << "String "<< S2 <<" found in array " << S1 << endl;
	}
	else
	{
		
		cout << "string not found in array "<<S1 << endl;
	}

	
}
void Delete(char S1[],char find[],int &len1, int &len2) {
	len1 = 0;
	len2 = 0;
	int size = 500;
	int i = Find_length(S1,len1);
	len1 = 0;
	cout << "Enter string you want to Delete: ";
	cin.ignore();
	cin.getline(find, size);
	int t = Find_length(find, len1);
	len1 = 0;
	int j = 0;
	while (S1[len1]!=NULL)
	{
		if (S1[len1] == find[len2]) {
			for (int t = len1; t < i; t++) {
				S1[t] = S1[t + 1];
			}
			len2++;
			len1--;
			j++;
		}
		


		len1++;
	}
	if (j!=t) {
		cout << "String not found in any array" << endl;
	}
	else if(j==t) {
		cout<<"New String: " << S1 << endl;

	}
}
void Compare(char S1[],char S2[], int&len1,int &len2) {
	len1 = 0;
	len2 = 0;
	bool equal = true;
	len1 = Find_length(S1,len1);
	len2 = Find_length(S2, len2);
	if (len1 != len2) {
		cout << "Two strings are not equal" << endl;
	}
	else if (len1 == len2) {
		len1 = 0;
		len2 = 0;
		while (S1[len1]!=NULL && equal==true)
		{
			if (S1[len1] != S2[len1]) {
				equal = false;
				break;
			}
			else
			{
				len1++;
			}
		}
		if (equal == true) {
			cout << "Strings are equal" << endl;
		
		}
		else
		{
		
			cout << "Strings are not equal" << endl;
		}
		
	}
}
void copyString(char S1[],int &len1) {
	len1 = 0;
		char Copy[Max];
	while (S1[len1]!=NULL)
	{
		Copy[len1] = S1[len1];
		len1++;
	}
	Copy[len1] = NULL;
	cout <<"String is coppied: "<< Copy << endl;
}
void subString(char S1[],char sub[], int& len1) {
	len1 = 0;
	int pos;
	int N = 0;
	int i = Find_length(S1, len1);
	cout << "Enter the position from which you want to extract the string: ";
	cin >> pos;

	pos = pos - 1;
	if (pos > 0 && pos < len1) {
		
		cout << "Enter the number of characters you want to extract: ";
		cin >> N;
		N = pos + N;
		if (N > pos && N < len1) {
			len1 = 0;
			while (N > pos)
			{
				sub[len1] = S1[pos];
				pos++;
				len1++;

			}
			sub[len1] = NULL;
			cout << sub << endl;
		}
		else {
			cout << "Enter N greater then " << pos << " but less than " << len1 << endl;
		}
	}
	else {
		cout << "Plz enter position within the range" << endl;
	}
	
}
int Space(char S1[], int& len1) {
	len1 = 0;
	while (S1[len1] != NULL)
	{
		if (S1[len1] == ' ') {
			S1[len1] = S1[len1 - 1];
		}
		len1++;
	}
	S1[len1] = NULL;
	return S1[Max];
}
int lowerCase(char palin[], char Lower[], int& len1) {
	len1 = 0;
	while (palin[len1] !=NULL)
	{
		if (palin[len1] >= 'A' && palin[len1] <= 'Z')
		{

			Lower[len1] = palin[len1]+32;

		}
		else {

			Lower[len1] = palin[len1];
		}
		len1++;
	}

	Lower[len1] = NULL;

	return Lower[Max];
}
int Reverse(char palin[], char reve[], int &len1) {
	lowerCase(palin, reve, len1);
	Space(palin, len1);
	int i = Find_length(palin, len1);
	i = i - 1;
	int j = 0;
	while (i>=0)
	{
		reve[j] = palin[i];
		j++;
		i--;
	}
	reve[j] = NULL;
	return reve[Max];
}
void palindrame(char palin[], char reve[], char Lower[], int& len1) {
	bool count = true;
	lowerCase(palin, Lower, len1);
	Space(palin, len1);
	Reverse(reve, palin, len1);
	
	len1 = 0;
	int i = Find_length(palin, len1);
	len1 = 0;
	int j = Find_length(reve, len1);
	len1 = 0;
	if (i = j) {
		while (palin[len1]!=NULL)
		{
			if (palin[len1] == reve[len1]) {

				count = true;
			}
			else {
				count = false;
				break;
			}

			len1++;
		}
	}
	else {
		cout << "Not a palindrome" << endl;
	}
	if (count == true) {
		cout << "String is a Palindrome" << endl;
	}
	else {
		cout << "String is not a plaindrome" << endl;
	}

}


int main() {
	int  Len1 = 0, Len2 = 0, Len3 = 0;
	char s1[Max];
	char s2[Max];
	char s3[Max];
	char find1[Max];
	char Sub[Max];
	char Search_1[Max];

	bool found = true;
	int choice;
	do
	{
		cout << "\n-->Press 1 to Create a strings\n-->Press 2 to find length of the strings\n-->Press 3 to display the strings" <<
			"\n-->Press 4 to Merge\n-->Press 5 to Search\n-->Press 6 to Delete\n-->Press 7 to copy the string\n-->Press 8 to Extract sub string" <<
			"\n-->Press 9 Palindrome\n-->Press 10 to compare\n-->Press 11 To Exit"<<endl;
		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "--Press 1 for First Name\n-->Press 2 for the Second Name " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				do
				{
					cout << "Enter First Name: ";
					Create_String(s1, Len1);

				} while (Len1 > Max);
				s1[Len1] = NULL;
				break;
					
			}
			case 2: {
				do
				{
					cout << "Enter Second Name: ";
					Create_String(s2, Len1);

				} while (Len1 > Max);
				s2[Len1] = NULL;
				break;
			case 3: {
				break;
			}
			}
			default:
				cout << "Plz enter the valid number" << endl;
				break;
			}		

			break;
		}
		case 2: {
			Find_length(s1, Len1);
			cout << "Length of string 1: " << Len1 << endl;
			Find_length(s2, Len1);
			cout << "Length of string 2: " << Len1 << endl;

			break;
		}
		case 3: {
			display(s1, s2);
			break;
		}
		case 4: {
			Merge(s1, s2,s3, Len1,Len2);
			cout << s3 << endl;
			break;
		}
		case 5: {
			cout << "Search: ";
			cin.ignore();
			cin.getline(Search_1, Max);
			Search(s1,Search_1, Len1, Len2, found);
			Search(s2, Search_1, Len1, Len2, found);
			Merge(s1, s2, s3, Len1, Len2);
			Search(s3, Search_1, Len1, Len2, found);
			

			break;
		}
		case 6: {
			cout << "-->Press 1 To Delete from the First String\n-->Press 2 To Delete fromt the Second String" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				Delete(s1, find1, Len1, Len2);
				break;
			}
			case 2: {
				Delete(s2, find1, Len1, Len2);
				break;
			}
			default:
				break;
			}
			
			break;
		}
		case 7: {
			copyString(s1, Len1);
			break;
		}
		case 8: {
			cout << "\n-->Press 1 to Extract from Frist String\n-->Press 2 to Extract from Second String" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:{
				subString(s1, Sub, Len1);
				break;
			}
			case 2: {
				subString(s2, Sub, Len1);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 9: {
			char palin[Max];
			char reve[Max];
			char Lower[Max];
			cout << "Enter a string: ";
			cin.ignore();
			cin.getline(palin, Max);
			
			palindrame(palin,reve,Lower, Len1);
			break;
		}
		case 10: {
			Compare(s1, s2, Len1,Len2);
			break;
		}
		case 11: {
			return 0;
		}
		default:
			break;
		}

	} while (choice!=11);

}