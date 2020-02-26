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

/* stream: chunk { 
  $$ = Node("stream", ""); 
  $$.children.push_back($1); 
  root = $$;
  }
  ; */

chunk: stat { 
  $$ = $1;
  }
  | stat SEMI {
    $$ = $1;
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
  ; 
forStat: FOR Name EQUALS exp COMMA exp DO block END {
  $$ = Node("for", "");
  Node assignmentNode = Node("assignment", $3);
  assignmentNode.children.push_back(Node("var", $2));
  assignmentNode.children.push_back($4);
  $$.children.push_back(assignmentNode);
  $$.children.push_back($6);
  $$.children.push_back($8);
}
| FOR Name EQUALS exp COMMA exp COMMA exp DO block END {
  $$ = Node("for", "");
  Node assignmentNode = Node("assignment", $3);
  assignmentNode.children.push_back(Node("var", $2));
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

var: Name { 
  $$ = Node("var", $1);
  }
  | prefixexp DOT var {
    $$ = Node("var", $2);
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
  | functioncall {
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
  | expression EQ term {
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
  | number { $$ = $1;};
;

number : INTEGER { $$ = Node("int", $1);}
  | FLOAT { $$ = Node("float", $1);}
  ;

%%