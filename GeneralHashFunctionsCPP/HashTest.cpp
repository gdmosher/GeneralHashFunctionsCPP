/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include "GeneralHashFunctions.h"

int main(int argc, char* argv[])
{
//   std::string key = "abcdefghijklmnopqrstuvwxyz1234567890";
   std::string key = "\
	   Then out spake brave Horatius,\n\
	   The Captain of the Gate :\n\
	   To every man upon this earth\n\
	   Death cometh soon or late.\n\
	   And how can man die better\n\
	   Than facing fearful odds,\n\
	   For the ashes of his fathers,\n\
	   And the temples of his gods.\n";
   std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
   std::cout << "By Arash Partow - 2002        " << std::endl;
   std::cout << "Key: "                          << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << std::endl;
   std::cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << std::endl;
   std::cout << "10. BP-Hash Function Value:   " << BPHash(key)   << std::endl;
   std::cout << "11. AP-Hash Function Value:   " << APHash(key)   << std::endl;


   BloomFilter bf(1300);// pass m in constructor, k=9 // = new(BloomFilter(1300));

   bf.add("Hello");
   bf.add("Goodbye");
   for (int i = 0; i < 98; i++) {		// n will be 98 + 2 = 100
	   bf.add(key += "1");
   }
   bf.possiblyContains("Hello");
   bf.possiblyContains("Goodbye");
   bf.possiblyContains(key);
   bf.possiblyContains("Junk");


   system("Pause");

   return true;
}
