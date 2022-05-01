#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#include <chrono>
#include<thread>

/* funciton definitions used in program*/

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
/* start of main program */

int main()
{
	std::ifstream hexfile("encrypted.txt");
	std::vector<std::string> line_in_file;
	if(hexfile.is_open())
	{
		std::string line;
		int count = 1;
		
		while(hexfile >> line)
		{	//printf("line %d string is: ",count);
			//std::cout << line << "\n\n";
			line_in_file.push_back(line);
			
			count++;
			
		}
		hexfile.close();
	}
	
	// from this point i have all my hex string in a vecto.
	
	std::vector<std::string> ascii_of_hex;
	for(std::string hex_str : line_in_file )
	{
		ascii_of_hex.push_back(hex_to_ascii(hex_str));
	}
	
	
			  
	
	
	std::cout << "Results after xored with brute force method:\n"; 
	
	
	std::vector<std::string> xor_bit_str;
	for(int i = 0; i < 256; i++ )
	{
		for(int j = 0; j < ascii_of_hex.size();j++)
		{
			xor_bit_str.push_back(xor_key(ascii_of_hex[i],j));
		}
			
	}
	
	std::vector<std::string> message_result;
	for(std::string binary_str : xor_bit_str)
	{
		message_result.push_back(bin_to_ascii(binary_str));
	}
	
	std::cout << "number of strings after tryin all 256 single byte key on all 327 strings:\n" << message_result.size() << "\n";
	
	for( int i =0; i < message_result.size(); i++ )
	{
		printf("message decrypted with single byte with all 256 bytes with message %d:\n", i);
		
		std::cout << message_result[i] << "\n\n";
	}

	return 0;
	
}
