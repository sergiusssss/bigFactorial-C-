#include <iostream>
#include <vector>

using namespace std;

vector<int> summ(vector<int> first, vector<int> second) 
{
	int length;
	if (first.size() > second.size()) { 
		length = first.size();
		for (int i = second.size(); i < length; i++)
		{
			second.push_back(0);
		}
	}
	else
	{
		length = second.size();
		for (int i = first.size(); i < length; i++)
		{
			first.push_back(0);
		}
	}

	vector<int> sum(length + 1, 0);

	for (int i = 0; i < length; i++)
	{
		sum[i] += first[i] + second[i];
		sum[i + 1] += sum[i] / 10;
		sum[i] = sum[i] % 10;
	}

	if (sum[sum.size() - 1] == 0)
	{
		sum.pop_back();
	}

	return sum;
}
vector<int> proizvedenie(vector<int> first, vector<int> second) {
	vector<int> p;
	vector<int> big;
	vector<int> little;
	if (first.size() > second.size())
	{
		big = first;
		little = second;
	}
	else {
		big = second;
		little = first;
	}

	for (int i = 0; i < little.size(); i++)
	{
		vector<int> num;
		for (int w = 0; w < i; w++)
		{
			num.push_back(0);
		}
		for (int z = 0; z < big.size(); z++)
		{
			num.push_back(big[z] * little[i]);
		}
		if (num[num.size() - 1] / 10>0)
		{
			num.push_back(0);
		}
		for (int j = 0; j < num.size() - 1; j++)
		{
			num[j + 1] += num[j] / 10;
			num[j] = num[j] % 10;
		}
		p = summ(p, num);
	}

	return p;
}

vector<int> factorial(int fac) 
{
	vector<int> fact;
	if (fac == 1) fact.push_back(1);
	else
	{
		vector<int> factL = factorial(fac-1);
		
		vector<int> q;
		q.push_back(fac);

		fact = proizvedenie(q, factL);
	}
	return fact;
}

int main() 
{
	setlocale(0,"");
	start:
	vector<int> q;
	cout << "¬ведите факториал какого числа нужно вычеслить: ";
	int f;
	cin >> f;
	vector<int> w = factorial(f);
	for (int i = w.size() - 1; i >= 0; i--)
	{
		cout << w[i];
	}
	cout << endl;

	char go;
	cout << "’отите посчитать ещЄ раз (Y/N):";
	cin >> go;
	if (go == 'Y' || go == 'y')
	{
		goto start;
	}
	else system("pause");
	return 0;
}
