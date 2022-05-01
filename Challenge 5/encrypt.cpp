#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#include <chrono>
#include<thread>
/* function definiton */
std::string hex_to_ascii(std::string & hex_str)
{
	
	std::string temp_str{""};
	for(size_t i = 0; i < hex_str.length(); i+=2)
	{
		std::string hex_tuple = hex_str.substr(i,2);
		char ch = std::stoul(hex_tuple, nullptr,16);
		temp_str += ch;
		
	}	
	return temp_str;
	
}

std::string xor_multi_key(std::string & a, std::string key ) // a hhere is the input string ins ascii to xor bitwise
{
	int i = 0, k = 0;
	std::string output_str{""};
	while (i < a.size())
	{		
		std::string temp_str = (std::bitset<8>(a[i]) ^ std::bitset<8>(key[k])).to_string();
				output_str += temp_str;
		
		i++;
		k++;
		if(k > 2)
		{
			k = 0;
		}
	}
	return output_str;
}

std::string bin_to_ascii(std::string & bin_str) // binary to ascii conversion
{
	std::string output_str{""};
	for(size_t i =0;i<bin_str.length();i+=8)
	{
		std::string temp_str = bin_str.substr(i,8);
		char ch = std::stoul(temp_str,nullptr,2);
		
		output_str += ch;
	}
	return output_str;
}

std::string ascii_to_bin(std::string & ascii_str)
{
	std::string output_str{""};
	for(char ch : ascii_str)
	{
		std::string temp_bin_str{""};
		temp_bin_str = std::bitset<8>(ch).to_string(); 
		output_str += temp_bin_str;
	}
	return output_str;
}

std::string xor_key(std::string & a, int  key )
{
	
	std::string output_str{""};
	for (char ch : a)
	{
		
		std::string temp_str = (std::bitset<8>(ch) ^ std::bitset<8>(key)).to_string();
		output_str += temp_str;
	}
	return output_str;
}

std::vector<int> bin_to_hex(std::string encrypted_str)
{std::vector<int> temp_vec;
 for(int i = 0; i < encrypted_str.length(); i+=4)
	{
        
		int temp_num = std::stoi(encrypted_str.substr(i,4),nullptr,2);
		temp_vec.push_back(temp_num);

		
	}
    return temp_vec;
}
/* start of main program */
int main()
{
    std::string str_to_encrypt1{"Burning 'em, if you ain't quick and nimble"};
    std::string str_to_encrypt2{"I go crazy when I hear a cymbal"};
    std::string encrypted_str1{xor_multi_key(str_to_encrypt1,"ICE")};
    std::string encrypted_str2{xor_multi_key(str_to_encrypt2,"ICE")};
    std::string ascii_of_encrypt1{bin_to_ascii(encrypted_str1)};
    

    std::vector<int> hex_str1{bin_to_hex(encrypted_str1)};
    std::vector<int> hex_str2{bin_to_hex(encrypted_str2)};   
    
    std::cout << "our XOR resultant hex string: " << std::endl;
	for(int num : hex_str1)
	{
		printf("%x",num);
	}
    std::cout << '\n';
    for(int num : hex_str2)
	{
		printf("%x",num);
	} 
	std::cout << '\n';
}
