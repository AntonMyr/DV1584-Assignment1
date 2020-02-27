%top{
  #include "binary.tab.hh"
  #define YY_DECL yy::parser::symbol_type yylex()
  int quoteCounter = 0;
}
%option noyywrap nounput batch noinput

TEXT ([^\n\|;\t $\"])|(\\;)|(\\\\)|(\\\ )|(\\\|)
WORD ([^\n\|;\t ])|(\\\;)|(\\\|)
FUNC_NAMES ("print")
NUMBER ([0-9])
NAME (([a-z]|[A-Z]|_)[0-9]|[a-z]|[A-Z]|_)
DQUOTE (\"(\\.|[^"\\])*\")

  /*" */
%%
  /*FUNC_NAMES { return yy::parser::make_FUNC(yytext);}*/
{DQUOTE} { 
  yytext = yytext + 1; 
  yytext[yyleng - 2] = 0; 
  std::cout << "Dquote: " << yytext << std::endl;
  return yy::parser::make_STRING(yytext);
  }
"for" { 
  
  std::cout << "FOR: " << yytext << std::endl;
  return yy::parser::make_FOR(yytext);}
"do" { 
  std::cout << "DO: " << yytext << std::endl;
  return yy::parser::make_DO(yytext);}
"end" { 
  std::cout << "END: " << yytext << std::endl;
  return yy::parser::make_END(yytext);}

"if" { 
  std::cout << "IF: " << yytext << std::endl;
  return yy::parser::make_IF(yytext);}
"elseif" { 
  std::cout << "ELSEIF: " << yytext << std::endl;
  return yy::parser::make_ELSEIF(yytext);}
"else" { 
  std::cout << "ELSE: " << yytext << std::endl;
  return yy::parser::make_ELSE(yytext);}
"then" { 
  std::cout << "THEN: " << yytext << std::endl;
  return yy::parser::make_THEN(yytext);}
"repeat" { 
  std::cout << "REPEAT: " << yytext << std::endl;
  return yy::parser::make_REPEAT(yytext);}
"until" { 
  std::cout << "UNTIL: " << yytext << std::endl;
  return yy::parser::make_UNTIL(yytext);}
"false" { 
  std::cout << "FALSE: " << yytext << std::endl;
  return yy::parser::make_FALSE(yytext);}
"true" { 
  std::cout << "TRUE: " << yytext << std::endl;
  return yy::parser::make_TRUE(yytext);}
"function" { 
  std::cout << "FUNCTION: " << yytext << std::endl;
  return yy::parser::make_FUNCTION(yytext);}
"return" { 
  std::cout << "RETURN: " << yytext << std::endl;
  return yy::parser::make_RETURN(yytext);}
"break" { 
  std::cout << "BREAK: " << yytext << std::endl;
  return yy::parser::make_BREAK(yytext);}
[0-9]+ { 
  std::cout << "INTEGER: " << yytext << std::endl;
  return yy::parser::make_INTEGER(yytext);}
[0-9]+\.[0-9]+ { return yy::parser::make_FLOAT(yytext);}

"+" { return yy::parser::make_PLUS(yytext);}
"-" { return yy::parser::make_MINUS(yytext);}
"*" { return yy::parser::make_STAR(yytext);}
"/" { return yy::parser::make_SLASH(yytext);}
"(" { 
  std::cout << "OPENP: " << yytext << std::endl;
  return yy::parser::make_OPENP(yytext);}
")" { 
  
  std::cout << "CLOSEP: " << yytext << std::endl;
  return yy::parser::make_CLOSEP(yytext);}
"," { return yy::parser::make_COMMA(yytext);}
"^" { return yy::parser::make_CIRCUMFLEX(yytext);}
([=]=|=[=]) { 
  std::cout << "EQ: " << yytext << std::endl;
  return yy::parser::make_EQ(yytext);}
"=" { 
  std::cout << "EQUALS: " << yytext << std::endl;
  return yy::parser::make_EQUALS(yytext);}
";" { return yy::parser::make_SEMI(yytext);}
":" { return yy::parser::make_COLON(yytext);}
"..." { return yy::parser::make_VARARG(yytext);}
"%" { 
  std::cout << "MODULO: " << yytext << std::endl;
  return yy::parser::make_MODULO(yytext);}
"{" {
  return yy::parser::make_CURLYO(yytext);
}
"}" {
  return yy::parser::make_CURLYC(yytext);
}
"[" {
  return yy::parser::make_BRACKETO(yytext);
}
"]" {
  return yy::parser::make_BRACKETC(yytext);
}
"#" {
  std::cout << "LENGTHOP: " << yytext << std::endl;
  return yy::parser::make_LENGTHOP(yytext);
}
">" {
  std::cout << "GREATER: " << yytext << std::endl;
  return yy::parser::make_GREATER(yytext);
}
"<" {
  std::cout << "LESS: " << yytext << std::endl;
  return yy::parser::make_LESS(yytext);
}
"." { 
  
  std::cout << "DOT: " << yytext << std::endl;
  return yy::parser::make_DOT(yytext);}

 /* "*/
{NAME}* { 
  std::cout << "Name: " << yytext << std::endl;
  return yy::parser::make_Name(yytext);}

  /*"\n"  { return yy::parser::make_NEWL(yytext);}*/ 
  /*

  "|" { return yy::parser::make_PIPE(yytext);}
  {WORD}* { return yy::parser::make_Word(yytext); }
  [\t ]+ { return yy::parser::make_Blank(yytext);}*/
<<EOF>>       return yy::parser::make_ENDF();
%%