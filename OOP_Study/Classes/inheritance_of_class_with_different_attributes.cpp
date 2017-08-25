class Check
{
private:
	int a;

protected:
	int b, c;
	void set_a(int x)
	{
		a = x;
	}

public:
	void set_b(int y)
	{
		b = y;
	}

	void set_c(int z)
	{
		c = z;
	}
};


class Quiz : private Check <=> class Quiz{
private:
...
	int a;
	int b,c;
	void set_a(){...}
	void set_b(){...}
	void set_c(){...}	
public:
...
};

class Quiz : protected Check <=> class Quiz{
private:
	int a;

protected:
	int b,c;
	void set_a(){...}
	void set_b(){...}
	void set_c(){...}	

public:
...
};

class Quiz : public Check <=> class Quiz{
private:
	int a;
	...

protected:
	int b, c;
	void set_a(int x)
	{
		a = x;
	}
	...

public:
	void set_b(int y)
	{
		b = y;
	}

	void set_c(int z)
	{
		c = z;
	}
	...
};

class Quiz : Check <=> class Quiz{ //here private is by deafult attribute for inheritance
private:

protected:

public:
};