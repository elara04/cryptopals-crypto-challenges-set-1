#include<iostream>
#include<string>
#include<vector>
#include<bitset>


/* funciton definitions */
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

std::string xor_bitwise(std::string  & a, std::string & b )
{   
	std::string output_str{""};
	for(int i =0; i < a.length();i++ )
	{	
	std::string temp_bit_str = (std::bitset<8>(a[i]) ^ std::bitset<8>(b[i])).to_string();
	output_str += temp_bit_str;
	}
	return output_str;
}

std::string xor_key(std::string & a, int key )
{
	std::string output_str{""};
	for (char ch : a)
	{
		std::string temp_str = (std::bitset<8>(ch) ^ std::bitset<8>(key)).to_string();
		output_str += temp_str;
	}
	return output_str;
}

std::string bin_to_ascii(std::string & bin_str)
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

/* start of the main funciton */


int main(int argc, char** argv)
{
	
	std::string input_hex_str = argv[1];
	std::string input_ascii_str{hex_to_ascii(input_hex_str)};

	
	
	
	for(int i = 0; i<256; i++)
	{
		std::string xor_bit_result{xor_key(input_ascii_str,i)};
		
		std::cout << "decrypted message with key " << i << ": " << bin_to_ascii(xor_bit_result) << std::endl << std::endl;
				
	}
	
	
	
	
	return 0;
}
