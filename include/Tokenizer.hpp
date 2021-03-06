/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <iostream>
#include "../Library/FileSystemPlusPlus.h"

typedef struct FTokenizer {
public:
	// Comment Lines
	std::string CommentLineBegin = "/>";
	std::string CommentLineEnd = "</";
	std::string SingleCommentLine = "//";
	
	// Brackets
	std::string BracketsBegin = "[";
	std::string BracketsEnd = "]";
	std::string OtherBracketBegin = "(";
	std::string OtherBracketEnd = ")";
	
	// Curly Brackets
	std::string CurlyBracketsBegin = "{";
	std::string CurlyBracketsEnd = "}";

	// Variables
	std::string Var = "var";
	std::string Int = "int";
	std::string String = "string";
	
	// Functions 
	std::string Func = "func";
	std::string Get = "get";
	std::string Input = "input";
	
	// Print
	std::string Print = "print";
	
	// Sign
	std::string RightArrowSign = "->";
	std::string LeftArrowSign = "<-";

	// System Integration
	std::string Exec = "exec";
	std::string System = "system";
	
	// Definitions
	std::string If = "#if";
	std::string Ifdef = "ifdef";
	std::string endif = "endif}";
	std::string Definition = "defin";
	
	std::string Exit = "exit";

	std::string Str = "string";
	std::string ArrowKey = "->";
	std::string LeftArrowKey = "<-";
	
	std::string Whitespace = " ";
} Tokenizer;

#endif // TOKENIZER_HPP
