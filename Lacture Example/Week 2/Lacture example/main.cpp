#include <iostream>
using namespace std;

void display(int&)
{
	cout << "l-value" << endl;
}

void display(int&&) {
	cout << "r-valur" << endl;
}

// class with resources
class Numbers {
	double* m_arr{};
	size_t m_cnt{};
public:
	
	//rule of 5
	Numbers(size_t len) {

		cout << "[" << this << "] Numbers(size_t)\n";
		m_arr = new double[len] {};
		for (auto i = 0; i < len; i++)
		{
			m_arr[i] = 0.5 * i;
			m_cnt = len;
		}
	}
	Numbers(const Numbers& other)  /*:m_arr{}*/
	{

		m_arr = nullptr;
		// TODO: initialize all the attributes that are used in assingment operator
		*this = other;
	}

	//B.move assignment operator
	Numbers& operator=(Numbers&& other)  noexcept{

		//1. check for self assingment
		if (this != &other) {

			//2. clean-up
			delete[] m_arr;

			//3. shallow copy
			m_cnt = other.m_cnt;

			//4. move the resource
			m_arr = other.m_arr;

			other.m_arr = nullptr;
		}
		return *this;
	}
	// c. destructor
	~Numbers()
	{
		delete[] m_arr;
	}

	//D. move-constructor
	Numbers(Numbers&& other) noexcept  /*:m_arr{}*/
	{

		//m_arr = nullptr;
		// TODO: initialize all the attributes that are used in assingment operator
		*this = std::move(other);
	}
};

int main()
{
	//l-value references
	//r-value references

	int data = 10;
	int&& refToInt = 10;  // r-value reference

	//compiler will do temporary materialization converstion
	display(10); // r-value will be called 

	display(data); // l-value will be called

	display(refToInt); // l-value will be called

	// it all dependes on the parameter passed can be used further in the code or not 

	display(++data); // l-value will be called because it will be used in further code 

	display(data++); // r-value will be called coz post-fix increament will make a copy of the obj and will do the 
					// WORK in the code and then it will increament and return the copy the obj created 

	display(data + 5); // r-value will be called

	display(data += 5); // l-value will be called

}