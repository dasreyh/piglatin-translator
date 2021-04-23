#include <iostream>
#include <string>
using namespace std;

string pigLatin(string input) {
	int w = 0;
	string word;
	string vowel = "way";
	string consonants = "ay";

	for (int i = 0; i < input.length(); i++) {
		//checks if word starts with any vowels and then inserts vowel ending.
		if (input[i] == 'a' || input[i] == 'A' || input[i] == 'e' || input[i] == 'E' || input[i] == 'i' || input[i] == 'I' || input[i] == 'o' || input[i] == 'O' || input[i] == 'u' || input[i] == 'U') {
			w = input.find(" ", i);

			input.insert(w, vowel);
			i = w + vowel.length();
		}
		//if word is a consonant then remove first letter and insert it at the end with 'ay'
		else {
			word = input.substr(i, 1);
			input.erase(i, 1);

			w = input.find(" ", i);

			input.insert(w, word);
			input.insert(w + 1, consonants);
			i = w + consonants.length() + 1;
		}
	}
	return input;
}

int main(){
	string input, convertedString;

	//Get the sentance to convert from user.
	cout << "Enter a sentance to convert." << endl;
	getline(cin, input);

	//Add blank space to prevent out of range.
	input.insert(input.length(), " ");

	//Translate and return the converted string.
	convertedString = pigLatin(input);
	cout << "Result: " << convertedString << endl;

	system("Pause");
	return 0;
}

