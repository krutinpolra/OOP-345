#include <iostream>
using namespace std;

/* R-VALUE REFERENCES
void display(int&) { // this the argument function receiveing, client want it to exist
	cout << "l-value\n";
}

void display(int&&) { // this the argument function receiveing, client don't want it
	cout << "r-value\n";
}
*/

// RULE OF 5

class Numbers {
	double* m_arr{}; // initialization 1
	size_t m_cnt{};
public:
	void display() const
	{
		if (m_arr != nullptr)
		{
			cout << m_arr[0];
			for (auto i = 1u; i < m_cnt; ++i)
				cout << ", " << m_arr[i];
			cout << "\n";
		}
		else
			cout << "Empty!";

	}

	Numbers(size_t len)
	{
		clog << "[" << this << "] Numbers(size_t)\n";
		m_arr = new double[len] {};
		for (auto i = 0; i < len; ++i)
			m_arr[i] = 0.5 * i;
		m_cnt = len;
	}

	// rule of 5
	Numbers(const Numbers& other) : m_arr{} // initialization 2
	{
		clog << "[" << this << "] CC build object from [" << &other << "]\n";
		m_arr = nullptr; // initialization 3 : use any of the three
		// TODO: initialize all attributes that are used in C=
		*this = other;
	}

	Numbers& operator=(const Numbers& other)
	{
		clog << "[" << this << "] C= from [" << &other << "]\n";
		// 1. Check for self-assignment
		if (this != &other)
		{
			// 2. Clean-up
			delete[] m_arr;

			// 3. shallow copy
			m_cnt = other.m_cnt;

			// 4. deep copy
			if (m_cnt != 0)
			{
				m_arr = new double[m_cnt];
				for (int i = 0u; i < m_cnt; ++i)
					m_arr[i] = other.m_arr[i];
			}
			else
				m_arr = nullptr;

		}
		return *this;
	}

	~Numbers()
	{
		clog << "[" << this << "] ~Numbers()\n";
		delete[] m_arr;
	}

	// move constructor
	Numbers(Numbers&& other) noexcept
	{
		clog << "[" << this << "] MC build object from [" << &other << "]\n";
		// TODO: initialize all attributes used by M=
		*this = std::move(other); // If we do not put the move it will call the copy-assignment operator
	}

	// move assignment operator
	Numbers& operator=(Numbers&& other) noexcept // this is just to compiler happy
	{
		clog << "[" << this << "] M= from [" << &other << "]\n";
		// 1. Check for self-assignment
		if (this != &other)
		{
			// 2. Clean-up
			delete[] m_arr;

			// 3. shallow copy
			m_cnt = other.m_cnt;

			// 4. move the resource
			m_arr = other.m_arr;
			other.m_cnt = 0;
			other.m_arr = nullptr;
		}
		return *this;
	}

};

Numbers calculateSomething() {
	Numbers res(3);
	// ...

	return res; // this object dieing
}

int main(int, char**) {

	// l-value References : References to objects that client does need (You can demolish it)
	// r-value References : References to objects that client doesn't need (You can demolish it)

	/* R_VALUE REFERNCES
	int data = 10;
	int&& refToInt = 10;

	display(10); // This will print the r-value
	display(data); // This will print the l-value
	display(refToInt); // this will print the l-value (Don't see the declaration just see this line of code)
	display(++data); // l-value prefix ++, will return the original object after modifications
	display(data++); // r-value postfix ++, will return an object that is about to die
	display(data + 5); // r-value : we don't nees temp value of (data + 5)
	display(data += 5); // l-value : Data variable will continue to exist
	refToInt = 33;
	*/

	Numbers n{ 5 };
	n = calculateSomething(); // Assigning the dieing object to n. This will call the move assignment
	n.display();

	/*Numbers n2 = n;
	n2.display();
	n.display();*/

}