//
//  tool_debug.hpp
//  AlgorithmsNotbookTest
//
//  Created by 王哲 on 2021/2/1.
//

#ifndef tool_debug_hpp
#define tool_debug_hpp

#include <stdio.h>
#include <string>
extern std::string CHAPTER;
extern std::string TYPEOFFILE;
void inputRedirection(std::string inputFile);//文件重定向root为input文件夹
void printIntArrary(int *arrary, int length);//打印数组
void copyIntArrary(int *from,int * to,int length);//复制数组
#endif /* tool_debug_hpp */
