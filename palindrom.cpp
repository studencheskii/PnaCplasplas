#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

bool IsPalindromLoop(std::string);
bool IsPalindrom(std::string);
void DeleteSpace(std::string&);
std::vector<std::string> PalindromFilter(std::vector<std::string>, int);

int main()
{
	std::cout << IsPalindromLoop("Madam") << std::endl;
	std::cout << IsPalindromLoop("Not New York, Roy went on") << std::endl;
	std::cout << IsPalindromLoop("gentelman") << std::endl;
	std::cout << IsPalindromLoop("A man, a plan a canal-Panama") << std::endl;
	std::cout << IsPalindromLoop("Was it a car or a cat I saw?") << std::endl;
	std::cout << std::endl;
	std::cout << IsPalindrom("Madam") << std::endl;
	std::cout << std::endl;
	std::cout << IsPalindrom("Not New York, Roy went on") << std::endl;
	std::cout << std::endl;
	std::cout << IsPalindrom("gentelman") << std::endl;
	std::cout << std::endl;
	std::cout << IsPalindrom("A man, a plan a canal-Panama") << std::endl;
	std::cout << std::endl;
	std::cout << IsPalindrom("Was it a car or a cat I saw?") << std::endl;
	std::cout << std::endl;

	std::vector<std::string> words;
	words.push_back("Deed");
	words.push_back("Nun");
	words.push_back("Noon");
	words.push_back("Level");
	words.push_back("Nine");
	words.push_back("Solos");
	words.push_back("Losos");
	words.push_back("Peep");
	words.push_back("Pele");
	words.push_back("Shahs");
	words.push_back("Sagas");
	words.push_back("Malayalam");
	words.push_back("Django");
	words.push_back("Madam I'm Adam");
	words.push_back("Able was I ere I saw Elba");
	words.push_back("A man, a plan a canal-Panama");
	words.push_back("Live not on evil");
	words.push_back("Groove");
	words.push_back("Was it a car or a cat I saw?");
	words.push_back("Solomon");
	words.push_back("Pull up if I pull up");
	words.push_back("Some men interpret nine memos");
	words.push_back("Not New York, Roy went on");
	words.push_back("Niagara o roar again");
	words.push_back("Yawn a more Roman way");
	words.push_back("abacaba");
	words.push_back("aba");
	words.push_back("weew");
	words.push_back("bro");
	words.push_back("code");

	std::cout << "Before call PalindromFilter:\n" << std::endl; 
	for(auto palindrom : words)
	{
		std::cout << palindrom << std::endl;
	}
	std::vector<std::string> palindroms= PalindromFilter(words,4);
	std::cout << "\nAfter call PalindromFilter:\n" << std::endl;
	for(auto palindrom : palindroms)
	{
		std::cout << palindrom << std::endl;
	}


	return 0;
}

bool IsPalindromLoop(std::string str)
{
	bool result = true;
	std::transform(str.begin(),str.end(),str.begin(),tolower);
	DeleteSpace(str);
	for(int i = 0, j = str.length() - 1; i != j && j > 0; i++, j--)
	{
		if(str[i] != str[j])
		{
			result = false;
		}
	}
	return result;
}

bool IsPalindrom(std::string str)
{
	bool result;
	std::transform(str.begin(),str.end(),str.begin(),tolower);
	int size = str.length();

	if(str.empty() || size == 1)
	{
		result = true;
	}
	else
	{
		DeleteSpace(str);
		int index = size / 2;
		std::string left;
		std::string right;
		left = str.substr(0,index);
		reverse(str.begin(),str.end());
		right = str.substr(0,index);
		result = (left == right);
	}
	return result;
}

void DeleteSpace(std::string &str)
{
	for(auto i = 0; i < str.length(); i++)
	{
		if(!isalnum(str[i]))
		{
			str.erase(str.find(str[i--]),1);
		}
	}
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
	std::vector<std::string> palindroms;
	for(auto iter = words.begin(); iter != words.end(); ++iter)
	{
		if(IsPalindromLoop(*iter) && iter->length() >= minLength )
		{
			palindroms.push_back(*iter);
		}
	}
	return palindroms;
}

bool IsTrueEnter(std::vector<std::string> strings)
{
	bool result = true;
	if(strings.size() <= 100)
	{
		for(auto str : strings)
		{
			if(str.length() > 100)
			{
				result = false;
				break;
			}
		}
	}
	else 
	{
		result = false;
	}
	return result;
}