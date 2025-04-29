#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

string low(string s)
{
	for (int i = 0;i < s.length() && s[i] >= 'A' && s[i] <= 'Z';i++)
	{
		s[i] = tolower(s[i]);
	}

	return s;

}

vector<string> split(string text)
{
	vector<string> words;
	string word;
	for (int i = 0;i < text.length();i++)
	{
		if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!')
		{
			if (word != "")
			{
				words.push_back(low(word));
				word = "";
			}
		}
		else
		{
			word += text[i];
		}
	}

	return words;

}
		
int main()
{
	ifstream file("text.txt");

	if (!file.is_open())
	{
		cout << "Eroare la deschidere";
		exit(1);
	}

	string text = "", line;
	while (getline(file, line))
	{
		text += line + " ";
	}
	file.close();
	
	vector<string> words = split(text);

	map<string, int> wordCount;

	for (int i = 0;i < words.size();i++)
	{
		wordCount[words[i]]++;
	}

	struct Compare {
		bool operator()(pair<string, int> a, pair<string, int>b)
		{
			if (a.second < b.second)
				return true;
			else
				if (a.second > b.second)
					return false;
				else
					if (a.first < b.first)
						return false;
					else
						return true;
		}
	};

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

	for (map<string, int>::iterator it = wordCount.begin(); it!=wordCount.end();it++)
	{
		pq.push(make_pair(it->first, it->second));
	}

	while (!pq.empty())
	{
		pair<string, int> word = pq.top();
		pq.pop();
		cout << word.first << " => " << word.second << endl;
	}

	return 0;
}