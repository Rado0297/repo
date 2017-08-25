#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class String
{
private:
	char* str;
	int len;

public:
	//Constructor
	String();

	//Constructor with one parameter
	String(const char*);

	//Copy constructor
	String(const String&);

	//Operators =
	String& operator=(const String&);
	const char* operator=(const char*);

	//Destructor
	~String();

	int length() const;
	const char* getString() const;

	//Redefined operator
	bool operator==(const String&) const;
	bool operator==(const char*) const;
	bool operator!=(const String&) const;
	bool operator!=(const char*) const;
	bool operator>(const String&) const;
	bool operator>(const char*) const;
	bool operator<(const String&) const;
	bool operator<(const char*) const;
	bool operator>=(const String&) const;
	bool operator>=(const char*) const;
	bool operator<=(const String&) const;
	bool operator<=(const char*) const;
	friend bool operator==(const char*, const String&);
	friend bool operator!=(const char*, const String&);
	friend bool operator>(const char*, const String&);
	friend bool operator<(const char*, const String&);
	friend bool operator>=(const char*, const String&);
	friend bool operator<=(const char*, const String&);

	void print() const
	{
		for (int i = 0; i < len; ++i)
		{
			cout << str[i];
		}
	}
};

String::String()
{
	str = NULL;
	len = 0;
}

String::String(const String& r)
{
	if (r.str)
	{
		str = new char[len + 1];
		if (!str)
		{
			cout << "Error while alocating a memory!\n";
			exit(1);
		}
		strcpy(str, r.str);
		len = r.len;
	}
	else
	{
		str = NULL;
		len = 0;
	}
}

String::String(const char* s)
{
	if (s)
	{
		len = strlen(s);
		str = new char[len+1];
		if (!str)
		{
			cout << "Error while alocating a memory!\n";
			exit(1);
		}
		strcpy(str, s);
	}
	else
	{
		str = NULL;
		len = 0;
	}
}

String::~String()
{
	if (len != 0)
	{
		delete [] str;
	}
}

int String::length() const
{
	return len;
}

const char* String::getString() const
{
	return str;
}

String& String::operator=(const String& r)
{
	if (r.str)
	{
		if (r.str != str)
		{
			len = r.len;
			if (str)
			{
				delete [] str;
			}

			str = new char[len+1];
			if (!str)
			{
				cout << "Error while alocating a memory!\n";
				exit(1);
			}
			strcpy(str, r.str);
		}
	}
	else if (str)
	{
		delete [] str;
		str = NULL;
		len = 0;
	}

	return *this;
}

const char* String::operator=(const char* r)
{
	if (r)
	{
		if (r != str)
		{
			if (str)
			{
				delete [] str;
			}
			len = strlen(r);
			str = new char[len+1];
			if (!str)
			{
				cout << "Error while alocating a memory!\n";
				exit(1);
			}
			strcpy(str, r);
		}
	}

	else if (str)
	{
		delete [] str;
		str = NULL;
		len = 0;
	}

	return str;
}

bool String::operator==(const String& r) const
{
	return !strcmp(str, r.getString());
}

bool String::operator==(const char* r) const
{
	return !strcmp(str, r);
}

bool operator==(const char* s, const String& r)
{
	return !strcmp(s, r.getString());
}

bool String::operator!=(const String& r) const
{
	return strcmp(str, r.getString()) != 0;
}

bool String::operator!=(const char* r) const
{
	return strcmp(str, r) != 0;
}

bool operator!=(const char* s, const String& r)
{
	return strcmp(s, r.getString()) != 0;
}

bool String::operator>(const String& r) const
{
	return strcmp(str, r.getString()) > 0;
}

bool String::operator>(const char* r) const
{
	return strcmp(str, r) > 0;
}

bool operator>(const char* s, const String& r)
{
	return strcmp(s, r.getString()) > 0;
}

bool String::operator<(const String& r) const
{
	return strcmp(str, r.getString()) < 0;
}

bool String::operator<(const char* r) const
{
	return strcmp(str, r) < 0;
}

bool operator<(const char* s, const String& r)
{
	return strcmp(s, r.getString()) < 0;
}

bool String::operator>=(const String& r) const
{
	return strcmp(str, r.getString()) >= 0;
}

bool String::operator>=(const char* r) const
{
	return strcmp(str, r) >= 0;
}

bool operator>=(const char* s, const String& r)
{
	return strcmp(s, r.getString()) >= 0;
}

bool String::operator<=(const String& r) const
{
	return strcmp(str, r.getString()) <= 0;
}

bool String::operator<=(const char* r) const
{
	return strcmp(str, r) <= 0;
}

bool operator<=(const char* s, const String& r)
{
	return strcmp(s, r.getString()) <= 0;
}

int main()
{
	String a("Hello "), b;
	b = a;
	b.print();
	char str1[] = "George!\n";

	b = str1;
	b.print();

	String c("Aneta"), d("Aneta");
	if (c == d)
	{
		cout << "Names are equals!\n";
	}

	else
	{
		cout << "Names aren't equals!\n";
	}

	if (c == "Aneta")
	{
		cout << "Names are equals!\n";
	}
	else
	{
		cout << "Names aren't equals!\n";	
	}

	if ("Aneta" == d)
	{
		cout << "Names are equals!\n";
	}
	else
	{
		cout << "Names aren't equals!\n";	
	}

	String e("Aneta"), f("Anet");
	if (e > f)
	{
		cout << "Name Aneta is longer than name Anet.\n";
	}
	else
	{
		cout << "Name Aneta isn't longer than name Anet.\n";
	}

	if (e > "Anet")
	{
		cout << "Name Aneta is longer than name Anet.\n";
	}
	else
	{
		cout << "Name Aneta isn't longer than name Anet.\n";
	}

	if ("Aneta" > f)
	{
		cout << "Name Aneta is longer than name Anet.\n";
	}
	else
	{
		cout << "Name Aneta isn't longer than name Anet.\n";
	}

	return 0;
}