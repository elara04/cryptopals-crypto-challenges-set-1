#include<iostream>
#include<string>
#include<bitset>
#include<vector>

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



int main(int argc,char** argv)
{
  std::string hex_str = argv[1];
 
  std::string compare_str{"686974207468652062756c6c277320657965"};
  
  /********************** converting hex to ascii ***********************/
  std::string ascii_str{hex_to_ascii(hex_str)};
 
  /***********************************************************************/	
  
	
	
	/******************* converting the comparsion hex string to ascii ********************/
	
	std::string ascii_comp{hex_to_ascii(compare_str)};
	
	/**************************************************************************************/



	
	/******** bitwise xor with resultant string in binary ***********/
	std::string xor_str{xor_bitwise(ascii_str,ascii_comp)};
 	
	
	/******************************************************************/

	std::cout << "our XOR resultant hex string: " << std::endl;

	/************ converting 8 bit xor binary back into hex **********************/
	 std::vector<int>bin4bt_to_int;
	for(int i = 0; i < xor_str.length(); i+=4)
	{
		int temp_num = std::stoi(xor_str.substr(i,4),nullptr,2);
		bin4bt_to_int.push_back(temp_num);
		
	}
	
	for(int num : bin4bt_to_int)
	{
		printf("%x",num);
	}	
	/*****************************************************************************/
	std::cout << std::endl;	
												

	
	
	
	
	return 0;
}
