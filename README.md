# ConsoleApplication1
Write a lexical analyzer for the programming language described as follows.

Comments and White Spaces
The language allows only line comments. Line comments start with the character sequence ## and stop at the end with ##. White spaces in the program including tabs, newline and horizontal spaces are ignored.

Keywords
The following are the reserved words in PL and it cannot be used as identifiers. The language is case sensitive.
Get	Put	If	Then	Else	fi
Repeat	Until	Continue	Break	Del	Int
String	Main	Return	Decl	Enddecl	Close
Open					

Operators and Delimiters
The following are the operators and delimiters
(	)	{	}	[	]	/	*	+	-	^
>	<	>=	<=	!=	==	;	=	&&	||	@

Identifiers
Identifiers are names of variables and user-defined functions. Identifiers should start with an upper-case alphabet followed by a sequence of zero or more digits. Examples of valid identifiers
X
B17
D0002

Integer Values
An integer literal is a sequence of digits representing an integer. Negative integers are represented with a negative sign preceding the sequence of digits. Positive integers might[not] be preceded by + sign. Examples of integer literals
8
-800
+55
-3000004

Real Values
A real value is a sequence of one or more digits, followed by period, followed by a sequence of one or more digits. Negative reals are represented with a negative sign. Positive integers might[not] be preceded by + sign. Examples of real literals
8.0
-800.1234567
+55.000
3000004.0

String Values
Any sequence of characters enclosed within @ signs are considered as string literals. For example, @abs    ****90=@ is a valid string.

Write a C/C++ or Java program that takes the name of the text file containing the source code and divides the code into tokens. Your program should output the sequence of tokens contained in the input file and their locations (row and column) into an output text file. Each token should be printed on a separate line in the output file. For string, integer, real and identifier literals, the output should include both the type of the token and the lexeme in the code.

For an example, if the input file contains
## this is an example##

Decl
Int Sum= -50.45;
String N1= @abc@;
Enddecl

the output file should contain the list of tokens:
Decl row=1, col=1
Int row=2, col=1
Identifier, lexeme= Sum row=2, col=5
= row=2, col=8
Real_Value, lexeme= -50.45 row=2, col=9
; row=2, col=14
String row=3, col=1
Identifier, lexeme= N1 row=3, col=8
= row=3, col=10
String_Value, lexeme=abc row=3, col=11
; row=3, col=16
Enddecl row=4, col=1

Your lexical analyzer should keep reading from input file until either it reaches the end of the input file or until an invalid token is reached. In such case, your program should output the list of valid tokens before the error and the location of the error. For example, if the input file contains
Decl
Int Sum8= -50;

The output file should contain
Decl row=1, col=1
Int row=2, col=1
Error: invalid identifier row=2, col=5

