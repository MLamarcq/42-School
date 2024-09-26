template <typename T>

Array<T>::Array(void)
{
	std::cout << "Array default constructor called" << std::endl;
	this->_array = NULL;
	return ;
}
template <typename T>
Array<T>::Array(unsigned int len) : _len(len)
{
	std::cout << "Array len assignement constructor called" << std::endl;
	try
	{
		if (this->_len == 0)
		{
			throw (std::exception());
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Wrong len, can't create array : " << e.what() << std::endl;
		return ;
	}
	this->_array = new T[this->_len];
	for (unsigned int i = 0; i < this->_len; i++)
	{
		this->_array[i] = 0;
	}
	return ;
}

template <typename T>
Array<T>::Array(Array<T> const &src)
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = src;
	return ;
}
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_len)
	{
		throw (OutOfRangeException());
	}
	return (this->_array[index]);
}

template <typename T>
const T & Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_len)
	{
		throw (OutOfRangeException());
	}
	return (this->_array[index]);
}


template <typename T>
Array<T> & Array<T>::operator=(Array<T> const &rhs)
{
	std::cout << "Copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_len = rhs.size();
		this->_array = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); i++)
		{
			this->_array[i] = rhs[i];
		}
	}
	return (*this);
}


template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array destructor called" << std::endl;
	if (this->_array)
		delete [] this->_array;
	return ;
}

template <typename T>
T *Array<T>::getArray(void) const
{
	return (this->_array);
}

template <typename T>

unsigned int Array<T>::size(void) const
{
	return (this->_len);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return ("Index is out of range !");
}
