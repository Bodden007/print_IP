/**
* @file
* @author Bodden007
* @version 1.0
*/

#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
#include <tuple>

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
/**
*@brief outputs to the console
*@param val when the types match int8_t, int16_t, int32_t, int64_t
*/
print_ip(T val)
{
	size_t buf = sizeof(T);///<number of bits in the type
/**
*@brief switch type selection
*/
	switch (buf)
	{
	/**
	*@param case_1 type selection int8_t
	*/
	case 1: {
		std::cout << unsigned(val) << std::endl;
		break;
	}
	 /**
	*@param case_2 type selection int16_t
	*/
	case 2: {
		std::cout << '0' << '.' << val << std::endl;
		break;
	}
	/**
	*@param case_4 type selection int32_t
	*/
	case 4: {
		int a, b, c;
		val = 127001;
		c = val % 10;
		b = val / 10 % 10;
		a = val / 100 % 10;

		std::cout << val / 1000 << '.' << a << '.' << b << '.' << c << std::endl;
		break;
	}
	/**
	*@param case_8 type selection int64_t
	*/
	case 8: {
		std::vector <int> vec{123, 45, 67, 89, 101, 112, 131, 41};
		for (bool isFirst(true); int& i:vec)
		{
			std::cout << (isFirst ? isFirst = false, "" : ".") << i;
		}
		std::cout << std::endl;
		break;
	}
		
	default:
		break;
	}
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, std::string>::value, void>::type
/**
*@brief outputs to the console in the format std::string
*@param val when the types match std::string
*/
print_ip(T val)
{
	std::cout << val << std::endl;
}

/**
*@brief Template overload function 
*/
template<typename T>
typename std::enable_if<(std::is_same<T, std::vector<int>>::value) || (std::is_same<T, std::list<int>>::value), void>::type
/**
*@brief outputs to the console in the format std::vector<int>
*@param val when the types match std::vector<int>>, std::list<int>>
*/
print_ip(T val)
{
	for (bool isFirst(true); int& i:val)
	{
		std::cout << (isFirst ? isFirst = false, "" : ".") << i;
	}
	std::cout << std::endl;
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, std::tuple<int, int, int, int>>::value, void>::type
/**
*@brief outputs to the console in the format std::tuple<int,int,int,int>
*@param val when the types match std::tuple
*/
print_ip(T val)
{
	std::cout << get<0>(val) << '.' << get<1>(val) << '.' << get<2>(val) << '.' << get<3>(val) << std::endl;
}

/**
* @brief main function
* @return 0
*/

int main()
{
	/**
	* @param val1 type of variable uint8_t
	*/
	uint8_t val1 = -1;
	/**
	* @param val2 type of variable int16_t
	*/
	int16_t val2 = 0;
	/**
	* @param val3 type of variable int32_t
	*/
	int32_t val3 = 2130706433;
	/**
	* @param val4 type of variable int64_t
	*/
	int64_t val4 = 8875824491850138409;
	/**
	* @param val5 type of variable std::string
	*/
	std::string val5 = "Hello, World!";
	/**
	* @param val6 type of variable std::vector
	*/
	std::vector <int> val6 {100, 200, 300, 400};
	/**
	* @param val7 type of variable std::list
	*/
	std::list <int> val7 {400, 300, 200, 100};
	/**
	* @param val8 type of variable std::make_tuple
	*/
	std::tuple <int, int, int, int> val8;
	val8 = std::make_tuple(123, 456, 789, 0);

	/**
	* @brief print_ip overloaded function
	* @param val1 uint8_t
	*/
	print_ip(val1);
	/**
	* @brief print_ip overloaded function
	* @param val2 uint16_t
	*/
	print_ip(val2);
	/**
	* @brief print_ip overloaded function
	* @param val3 uint32_t
	*/
	print_ip(val3);
	/**
	* @brief print_ip overloaded function
	* @param val4 uint64_t
	*/
	print_ip(val4);
	/**
	* @brief print_ip overloaded function
	* @param val5 std::string
	*/
	print_ip(val5);
	/**
	* @brief print_ip overloaded function
	* @param val6 std::vector <int>
	*/
	print_ip(val6);
	/**
	* @brief print_ip overloaded function
	* @param val7 std::list <int>
	*/
	print_ip(val7);
	/**
	* @brief print_ip overloaded function
	* @param val8 std::make_tuple
	*/
	print_ip(val8);

	return 0;
}