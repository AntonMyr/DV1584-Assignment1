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
  return yy::parser::make_ELSE(yytext);}
"then" { 
  std::cout << "THEN: " << yytext << std::endl;
  return yy::parser::make_THEN(yytext);}
{NAME}* { 
  std::cout << "Name: " << yytext << std::endl;
  return yy::parser::make_Name(yytext);}
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
"==" { 
  std::cout << "EQ: " << yytext << std::endl;
  return yy::parser::make_EQ(yytext);}
"=" { 
  std::cout << "EQUALS: " << yytext << std::endl;
  return yy::parser::make_EQUALS(yytext);}
";" { return yy::parser::make_SEMI(yytext);}
"%" { 
  std::cout << "MODULO: " << yytext << std::endl;
  return yy::parser::make_MODULO(yytext);}
"." { 
  
  std::cout << "DOT: " << yytext << std::endl;
  return yy::parser::make_DOT(yytext);}

  /*"\n"  { return yy::parser::make_NEWL(yytext);}*/ 
  /*

  "|" { return yy::parser::make_PIPE(yytext);}
  {WORD}* { return yy::parser::make_Word(yytext); }
  [\t ]+ { return yy::parser::make_Blank(yytext);}*/
<<EOF>>       return yy::parser::make_ENDF();
%%