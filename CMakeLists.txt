cmake_minimum_required (VERSION 2.6)

project (calculator)

find_package(BISON)
find_package(FLEX)

bison_target(
	CALCULATOR_PARSER calculator.y ${CMAKE_CURRENT_BINARY_DIR}/calculator_parser.c
	DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/calculator_parser.h
)
flex_target(
	CALCULATOR_LEXER calculator.l ${CMAKE_CURRENT_BINARY_DIR}/calculator_lexer.c
	DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/calculator_lexer.h
)
add_flex_bison_dependency(CALCULATOR_LEXER CALCULATOR_PARSER)

add_executable(
	calculator
	src/calculator.c
	${BISON_CALCULATOR_PARSER_OUTPUTS}
	${FLEX_CALCULATOR_LEXER_OUTPUTS}
)
