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
typename std::enable_if<std::is_same<T, uint8_t>::value, void>::type
/**
*@brief outputs to the console
*@param val when the types match uint8_t
*/
choice(T val)
{
	std::cout << unsigned(val) << std::endl;
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, int16_t>::value, void>::type
/**
*@brief outputs to the console in the format 0.0
*@param val when the types match int16_t
*/
choice(T val)
{
	std::cout << '0' << '.' << val << std::endl;
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, int32_t>::value, void>::type
/**
*@brief division by remainder and outputs to the console in the format 127.0.0.1
*@param val when the types match int32_t
*/
choice(T val)
{
	/**
	*@param a the numbers of the first block
	*@param b numbers of the second block
	* @param c numbers of the third block
	*/
	int a, b, c;
	val = 127001;
	c = val % 10;
	b = val / 10 % 10;
	a = val / 100 % 10;

	std::cout << val / 1000 << '.' << a << '.' << b << '.' << c << std::endl;
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, int64_t>::value, void>::type
/**
*@brief Output to the vector console in the format 123.45.67.89.101.112.131.41
*@param val when the types match int64_t
* @param vec vector <int>
*/
choice(T val)
{
	std::vector <int> vec{123, 45, 67, 89, 101, 112, 131, 41};

	for (bool isFirst(true); int& i:vec)
	{
		std::cout << (isFirst ? isFirst = false, "" : ".") << i;
	}
	std::cout << std::endl;
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
choice(T val)
{
	std::cout << val << std::endl;
}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<(std::is_same<T, std::vector<int>>::value) || (std::is_same<T, std::list<int>>::value), void>::type
/**
*@brief outputs to the console in the format std::vector<int>
*@param val when the types match std::vector<int>>
*/
choice(T val)
{
	for (bool isFirst(true); int& i:val)
	{
		std::cout << (isFirst ? isFirst = false, "" : ".") << i;
	}
	std::cout << std::endl;
}

///**
//*@brief Template function
//*/
//template<typename T>
//typename std::enable_if<std::is_same<T, std::list<int>>::value, void>::type
///**
//*@brief outputs to the console in the format std::list<int>
//*@param val when the types match std::list<int>>
//*/
//choice(T val)
//{
//	for (bool isFirst(true); int& i:val)
//	{
//		std::cout << (isFirst ? isFirst = false, "" : ".") << i;
//	}
//	std::cout << std::endl;
//}

/**
*@brief Template function
*/
template<typename T>
typename std::enable_if<std::is_same<T, std::tuple<int, int, int, int>>::value, void>::type
/**
*@brief outputs to the console in the format std::tuple<int,int,int,int>
*@param val when the types match std::tuple
*/
choice(T val)
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
	uint8_t val1 = 255;
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
	* @brief choice overloaded function
	* @param val1 uint8_t
	*/
	choice(val1);
	/**
	* @brief choice overloaded function
	* @param val2 uint16_t
	*/
	choice(val2);
	/**
	* @brief choice overloaded function
	* @param val3 uint32_t
	*/
	choice(val3);
	/**
	* @brief choice overloaded function
	* @param val4 uint64_t
	*/
	choice(val4);
	/**
	* @brief choice overloaded function
	* @param val5 std::string
	*/
	choice(val5);
	/**
	* @brief choice overloaded function
	* @param val6 std::vector <int>
	*/
	choice(val6);
	/**
	* @brief choice overloaded function
	* @param val7 std::list <int>
	*/
	choice(val7);
	/**
	* @brief choice overloaded function
	* @param val8 std::make_tuple
	*/
	choice(val8);

	return 0;
}