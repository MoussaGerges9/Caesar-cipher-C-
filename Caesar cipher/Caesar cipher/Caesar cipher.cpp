#include <iostream>
#include <string>
using namespace std;
int main()
{
	int choice;
	int key;
	int plus;
	string word;

	cout << "choose a number.." << endl;
	cout << "1 = to encrypt the words " << endl;
	cout << "2 = to decrypt the words " << endl;
	cin >> choice;

	cout << "(You can only write small letters and separate between words using '-')\n";
	cout << "Enter the word: ";
	cin >> word;

	cout << "Write a Key: ";
	cin >> key;

	switch (choice)
	{
		case 1:
			for (int y = 0; (word[y] != '\0'); y++)
			{
				if (word[y] == '-')
					word[y] = '1';

				else {
					plus = word[y] + key;
					if (plus > 122)
					{
						word[y] = char(97);
						word[y] = word[y] + (plus - 123);
					}
					else
						word[y] = word[y] + key;
				}

			}
			cout << "the encrypted word is: " << word << endl << endl;
			break;

		case 2:
			for (int y = 0; (word[y] != '\0'); y++)
			{
				if (word[y] == '1')
					word[y] = ' ';

				else {
					plus = word[y] - key;
					if (plus < 97)
					{
						int ddkey = key - (word[y] - 96);
						word[y] = char(122);
						word[y] = word[y] - ddkey;
					}
					else
						word[y] = word[y] - key;
				}
			}
			cout << "the decrypted word is: " << word << endl << endl;
			break;

		default:
			cout << "invalid input";
	}
}