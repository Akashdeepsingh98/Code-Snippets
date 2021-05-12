#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

class Node
{
public:
	char value;
	int priority;
	map<char, Node *> children;
	int gp; //greatest priority seen yet
	Node(char value, int priority)
	{
		this->value = value;
		this->priority = priority;
		this->gp = priority;
	}
};

class Trie
{
public:
	Node *root;
	Trie()
	{
		this->root = new Node(0, -1);
	}

	void insert(string &s, int priority)
	{
		Node *curnode = this->root;
		for (int i = 0; i < s.size() - 1; i++)
		{
			if (curnode->children.find(s[i]) == curnode->children.end())
			{
				curnode->children[s[i]] = new Node(s[i], -1);
			}
			if (curnode->gp < priority)
			{
				curnode->gp = priority;
			}
			curnode = curnode->children[s[i]];
		}
		if (curnode->gp < priority)
		{
			curnode->gp = priority;
		}
		if (curnode->children.find(s.back()) == curnode->children.end())
		{
			curnode->children[s.back()] = new Node(s.back(), priority);
		}
		else
		{
			curnode->children[s.back()]->priority = priority;
		}
		if (curnode->gp < priority)
		{
			curnode->gp = priority;
		}
	}

	int query(string &s)
	{
		Node *curnode = this->root;
		for (int i = 0; i < s.size(); i++)
		{
			if (curnode->children.find(s[i]) == curnode->children.end())
			{
				return -1;
			}
			curnode = curnode->children[s[i]];
		}
		int maxval = -1;
		this->dfs(curnode, maxval);
		return maxval;
	}

	void dfs(Node *curnode, int &maxval)
	{
		if (curnode->priority > maxval)
		{
			maxval = curnode->priority;
		}

		if (curnode->gp < maxval)
		{
			return;
		}

		for (auto it = curnode->children.begin(); it != curnode->children.end(); it++)
		{
			this->dfs(it->second, maxval);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	Trie *mytrie = new Trie();
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		string s;
		int priority;
		cin >> s;
		cin >> priority;
		mytrie->insert(s, priority);
		getline(cin, s);
	}
	for (int i = 0; i < q; i++)
	{
		string s;
		getline(cin, s);
		cout << mytrie->query(s) << '\n';
	}
	return 0;
}