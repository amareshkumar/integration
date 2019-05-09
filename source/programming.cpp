#include "programming.h"

static const int command_max_size = 100;

string programming_questions::Reverse(string str)
{
	size_t uiSize = str.size();

	for (int i = 0; i < uiSize; ++i)
	{
		while (isspace(str[i]) && i < uiSize)
			++i;

		int j = i;
		while ((!isspace(str[j])) && j < uiSize)
			++j;

		int k = i;
		i = j;
		--j;

		while (k < j)
		{
			swap(str[k], str[j]);
			++k;
			--j;
		}
	}
	return str;
}

int programming_questions::max_diff_arr_index(vector<int> array)
{
	static signed int diff = 0;
	unsigned int len = array.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len - i - 1; j++)
		{
			signed int diff1 = array[j + 1] - array[i];

			if (diff < diff1 && (diff1 > 0))
			{
				diff = diff1;
			}
			else
			{
				continue;
			}
		} //end of inner for
	}
	return diff;
}

std::string &programming_questions::reverse(std::string &st, int init, int final)
{
	int lenght = st.size();
	string temp = "";
	for (int i = init; i < final; i++)
	{
		temp[i] = st[i];
		st[i] = st[lenght - final + 1];
		st[lenght - final + 1] = temp[i];
	}
	return st;
}

std::string &programming_questions::reverse_word_wise(std::string &str)
{
	static int position = 0;

	for (int i = position; i < str.size(); i++)
	{
		if ((str[i] == '\t') || (str[i] == ' '))
		{
			reverse(str, position, i);
			position = i;
		}
	}
	return str;
}
