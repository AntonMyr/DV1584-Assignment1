	%skeleton "lalr1.cc" 
%defines
%define api.value.type variant
%define api.token.constructor
%code{
  unsigned int total = 0;
 #include <list> 
 #include <string>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  Node root;
  Node expListTemp;
  Node varListTemp;
  Node fieldListTemp;
  Node namelistTemp;
  Node elseifTemp;
  Node chunkTemp;
}

%code requires{
  #include "Node.h"
}

%type <Node> stream
%type <Node> expression
%type <Node> term
%type <Node> factor
%type <Node> number
%type <Node> var
%type <Node> functioncall
%type <Node> circumflex
%type <Node> args
%type <Node> prefixexp
%type <Node> explist
%type <Node> varlist
%type <Node> stat
%type <Node> chunk
%type <Node> String
%type <Node> exp
%type <Node> forStat
%type <Node> block
%type <Node> ifStat
%type <Node> elseifList
%type <Node> elseBlock
%type <Node> field
%type <Node> fieldlist
%type <Node> tableconstructor
%type <Node> repeatStat
%type <Node> bool
%type <Node> funcbody
%type <Node> parlist
%type <Node> namelist
%type <Node> funcname
%type <Node> name
%type <Node> laststat
%type <std::string> fieldsep

%token <std::string> PLUS
%token <std::string> EQUALS
%token <std::string> SEMI
%token <std::string> MINUS
%token <std::string> INTEGER
%token <std::string> FLOAT
%token <std::string> STAR
%token <std::string> SLASH
%token <std::string> OPENP
%token <std::string> CLOSEP
%token <std::string> COMMA
%token <std::string> CIRCUMFLEX
%token <std::string> NEWL
%token <std::string> Name
%token <std::string> STRING
%token <std::string> DOT
%token <std::string> FOR
%token <std::string> DO
%token <std::string> END
%token <std::string> IF
%token <std::string> ELSE
%token <std::string> ELSEIF
%token <std::string> THEN
%token <std::string> MODULO
%token <std::string> EQ
%token <std::string> CURLYO
%token <std::string> CURLYC
%token <std::string> BRACKETO
%token <std::string> BRACKETC
%token <std::string> LENGTHOP
%token <std::string> REPEAT
%token <std::string> UNTIL
%token <std::string> GREATER
%token <std::string> LESS
%token <std::string> FALSE
%token <std::string> TRUE
%token <std::string> FUNCTION
%token <std::string> COLON
%token <std::string> VARARG
%token <std::string> RETURN
%token <std::string> BREAK
%token ENDF 0 "end of file"
%%

/*
  Byt ut functioncall mot expression ifall du vill att något ska funka
*/

stream: chunk { 
  $$ = Node("stream", ""); 
  $$.children.push_back($1); 
  root = $$; 
  }
  | stream chunk  {
    $$ = $1;
    $$.children.push_back($2);
    root = $$;
}
;

chunk: stat { 
  $$ = $1;
  }
  | chunk laststat {
    $$ = $1;
    $$.children.push_back($2);
  }
  | laststat {
    $$ = $1;
  }
  | chunk SEMI {
    $$ = $1;
  }
  ;

laststat: RETURN {
  $$ = Node("return", "");
}
| RETURN explist {
  $$ = Node("return", "");
  $$.children.push_back($2);
}
| BREAK {
  $$ = Node("break", "");
}
;

block: chunk {
  $$ = Node("block", "");
  $$.children.push_back($1);
  chunkTemp = $$;
}
| block chunk {
  $$ = chunkTemp;
  $$.children.push_back($2);
  chunkTemp = $$;
}
;

stat: varlist EQUALS explist {
    $$ = Node("assignment", $2);
    $$.children.push_back($1);
    $$.children.push_back($3);
  }
  | functioncall {
    $$ = $1;
  }
  | forStat {
    $$ = $1;
  }
  | ifStat {
    $$ = $1;
  } 
  | repeatStat {
    $$ = $1;
  } 
  | FUNCTION funcname funcbody {
    $$ = Node("function", "");
    $$.children.push_back($2);
    $$.children.push_back($3);
  }
  ; 

funcbody: OPENP CLOSEP block END {
  $$ = Node("funcbody", "");
  $$.children.push_back($3);
}
| OPENP parlist CLOSEP block END {
  $$ = Node("funcbody", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
}
;

parlist: namelist {
  $$ = $1;
} | namelist COMMA VARARG {
  $$ = Node("parlist", $3);
  $$.children.push_back($1);
} | VARARG {
  $$ = Node("parlist", $1);
};

namelist: name {
  $$ = $1;
  namelistTemp = $$;
} 
| namelist COMMA name {
  $$ = namelistTemp;
  $$.children.push_back($3);
  namelistTemp = $$;
}

funcname: name {
  $$ = $1; 
} | funcname DOT name {
  $$ = Node("funcname", "");
  $$.children.push_back($3);
} | funcname COLON name {
  $$ = $1;
  $$.children.push_back($3);
}
;

repeatStat: REPEAT block UNTIL exp {
  $$ = Node("repeat", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
}
;

forStat: FOR name EQUALS exp COMMA exp DO block END {
  $$ = Node("for", "");
  Node assignmentNode = Node("assignment", $3);
  assignmentNode.children.push_back($2);
  assignmentNode.children.push_back($4);
  $$.children.push_back(assignmentNode);
  $$.children.push_back($6);
  $$.children.push_back($8);
}
| FOR name EQUALS exp COMMA exp COMMA exp DO block END {
  $$ = Node("for", "");
  Node assignmentNode = Node("assignment", $3);
  assignmentNode.children.push_back($2);
  assignmentNode.children.push_back($4);
  $$.children.push_back(assignmentNode);
  $$.children.push_back($6);
  $$.children.push_back($8);
  $$.children.push_back($10);
}
;

// if exp then block {elseif exp then block} [else block] end
ifStat: IF exp THEN block END {
  $$ = Node("if", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
}
| IF exp THEN block elseifList END {
  $$ = Node("if", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
  $$.children.push_back($5);
}
| IF exp THEN block elseifList elseBlock END {
  $$ = Node("if", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
  $$.children.push_back($5);
  $$.children.push_back($6);
}
| IF exp THEN block elseBlock END {
  $$ = Node("if", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
  $$.children.push_back($5);
}
;

elseifList: ELSEIF exp THEN block {
  $$ = Node("elseif", "");
  $$.children.push_back($2);
  $$.children.push_back($4);
}
| elseifList ELSEIF exp THEN block {
  // Sätt in en temp variabel
  $$ = $1;
  $$.children.push_back($3);
  $$.children.push_back($5);
}
;

elseBlock: ELSE block {
  $$ = Node("else", "");
  $$.children.push_back($2);
};


functioncall: prefixexp args{ 
  $$ = Node("functioncall", "");
  $$.children.push_back($1);
  $$.children.push_back($2);
  }
  ;

args: OPENP explist CLOSEP { 
  $$ = Node("args", ""); 
  $$.children.push_back($2);
  }
  | String {
    $$ = Node("args", "");
    $$.children.push_back($1);
  }
  ;

explist: exp { 
    $$ = Node("explist", ""); 
    $$.children.push_back($1); 
    expListTemp = $$;
  }
  | explist COMMA exp {
  std::cout << "->>Here: " << $3.value << std::endl;
      $$ = expListTemp;
      $$.children.push_back($3);
      expListTemp = $$;
  }
  ;

prefixexp: var { 
  $$ = $1;
  }
  | OPENP exp CLOSEP {
    $$ = $2;
  }
  | functioncall {
    $$ = $1;
  }
;

tableconstructor: CURLYO CURLYC {
  $$ = Node("tableconstructor", "");
}
| CURLYO fieldlist CURLYC {
  $$ = $2;
}
;

fieldlist: field {
  $$ = Node("fieldlist", "");
  $$.children.push_back($1);
  fieldListTemp = $$;
}
| fieldlist fieldsep field {
  $$ = fieldListTemp;
  $$.children.push_back($3);
  fieldListTemp = $$;

} 
| fieldlist fieldsep {
  $$ = fieldListTemp;
  $$.children.push_back($1);
  fieldListTemp = $$;
}
;

fieldsep: COMMA | SEMI;

field: BRACKETO exp BRACKETC EQUALS exp {
  $$ = Node("assignment", $4);
  $$.children.push_back($2);
  $$.children.push_back($5);
} | name EQUALS exp {
  $$ = Node("assignment", $2);
  $$.children.push_back($1);
  $$.children.push_back($3);
} | exp {
  $$ = $1;
}
;

varlist: var {
  $$ = Node("varlist", "");
  $$.children.push_back($1);
  varListTemp = $$;
}
| varlist COMMA var {
  $$ = varListTemp;
  $$.children.push_back($3);
  varListTemp = $$;
}
;

String: STRING { 
  $$ = Node("string", $1);
  }
  ;

var: name { 
  $$ = $1;
  }
  | prefixexp DOT name {
    $$ = Node("var", $2);
    $$.children.push_back($1);
    $$.children.push_back($3);
  }
  | prefixexp BRACKETO exp BRACKETC {
    $$ = Node("index", "");
    $$.children.push_back($1);
    $$.children.push_back($3);
  }
  ;

exp: expression { 
  $$ = $1; 
  }
  | String { 
    $$ = $1; 
  }
  | prefixexp {
    $$ = $1;
  }
  | tableconstructor {
    $$ = $1;
  } 
  | exp EQ exp {
    $$ = Node("binop", $2); 
    $$.children.push_back($1); 
    $$.children.push_back($3);
  }
  | exp GREATER exp {
    $$ = Node("binop", $2); 
    $$.children.push_back($1); 
    $$.children.push_back($3);
  }
  | exp LESS exp {
    $$ = Node("binop", $2); 
    $$.children.push_back($1); 
    $$.children.push_back($3);
  }
  | bool {
    $$ = $1;
  }
  ;

expression: expression PLUS term { 
    $$ = Node("binop", $2); 
    $$.children.push_back($1); 
    $$.children.push_back($3);
  }
  | expression MINUS term {
    $$ = Node("binop", $2); 
    $$.children.push_back($1); 
    $$.children.push_back($3);
  }
  | term { 
    $$ = $1; 
  };

term: term STAR factor {
  $$ = Node("binop", $2);
  $$.children.push_back($1); 
  $$.children.push_back($3);
  }
  | term SLASH term {
  $$ = Node("binop", $2);
  $$.children.push_back($1); 
  $$.children.push_back($3);
  }
  | term MODULO term {
  $$ = Node("binop", $2);
  $$.children.push_back($1); 
  $$.children.push_back($3);
  }
  | circumflex { 
    $$ = $1;
    };

circumflex: factor { $$ = $1;}
  | factor CIRCUMFLEX factor {
    $$ = Node("binop", $2);
    $$.children.push_back($1);
    $$.children.push_back($3);
  }
  | factor CIRCUMFLEX prefixexp{
    $$ = Node("binop", $2);
    $$.children.push_back($1);
    $$.children.push_back($3);
  }
  ;

factor: prefixexp{ 
  $$ = $1; 
  }
  | MINUS factor { 
    $$ = Node("unary", $1); 
    $$.children.push_back($2);
  }
  | LENGTHOP name {
    $$ = Node("unary", $1);
    $$.children.push_back($2);
  }
  | number { $$ = $1;};
;

number : INTEGER { $$ = Node("int", $1);}
  | FLOAT { $$ = Node("float", $1);}
  ;

bool: TRUE {
  $$ = Node("boolean", $1);
} 
| FALSE {
  $$ = Node("boolean", $1);
}
;

name: Name {
  $$ = Node("name", $1);
};

%%