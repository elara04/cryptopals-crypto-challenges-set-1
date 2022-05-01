#include<iostream>
#include<string>
#include<bitset>
#include<vector>



int main(int argc, char**argv)
{ std::string hex_str = argv[1];
  
  
  std::string char_hex_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**************** converting hex to ascii **************************/

  std::string ascii_str{""};
   for(size_t i=0;i<hex_str.length(); i+=2 )
    {
      std::string hex_tuple = hex_str.substr(i,2);
      char ch = std::stoul(hex_tuple,nullptr,16);
      ascii_str += ch;
    }
/********************************************************************/
  
  std::cout << "the original message: " << ascii_str << std::endl;
 

/**************** converting ascii to 8 bit binary ******************/

  std::string bin_8{""};
for(size_t i = 0; i<ascii_str.length();i++)
  {

  bin_8 += std::bitset<8>(ascii_str[i]).to_string();


  }
    /******************************************************************/

  



/******************** slicing concatenated binary string to 6 bit chunks **************************/
std::vector<int> index_vec;
for(size_t i = 0; i<bin_8.length(); i+=6)
{
  std::string temp_bit6 = bin_8.substr(i,6);
  index_vec.push_back(std::stoul(temp_bit6,nullptr,2));
 // std::cout << temp_bit6 <<" = " << std::stoi(temp_bit6,nullptr,2) << std::endl;

}
/***************************************************************************************************/

/**************************** indexing decimal to proper character in hex in char_set **************/
std::string base_64{""};
//std::cout << index_vec[0] << std::endl;
for (int i : index_vec)
{
  base_64 += char_hex_set[i];
}
std::cout <<"in base64 the hex string will be:"<< std::endl << base_64 << std::endl;




  return 0;

}
