// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "binary.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 5 "binary.yy" // lalr1.cc:413

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

#line 68 "binary.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 135 "binary.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 45: // stream
      case 46: // chunk
      case 47: // laststat
      case 48: // block
      case 49: // stat
      case 50: // funcbody
      case 51: // parlist
      case 52: // namelist
      case 53: // funcname
      case 54: // repeatStat
      case 55: // forStat
      case 56: // ifStat
      case 57: // elseifList
      case 58: // elseBlock
      case 59: // functioncall
      case 60: // args
      case 61: // explist
      case 62: // prefixexp
      case 63: // tableconstructor
      case 64: // fieldlist
      case 66: // field
      case 67: // varlist
      case 68: // String
      case 69: // var
      case 70: // exp
      case 71: // expression
      case 72: // term
      case 73: // circumflex
      case 74: // factor
      case 75: // number
      case 76: // bool
      case 77: // name
        value.move< Node > (that.value);
        break;

      case 3: // PLUS
      case 4: // EQUALS
      case 5: // SEMI
      case 6: // MINUS
      case 7: // INTEGER
      case 8: // FLOAT
      case 9: // STAR
      case 10: // SLASH
      case 11: // OPENP
      case 12: // CLOSEP
      case 13: // COMMA
      case 14: // CIRCUMFLEX
      case 15: // NEWL
      case 16: // Name
      case 17: // STRING
      case 18: // DOT
      case 19: // FOR
      case 20: // DO
      case 21: // END
      case 22: // IF
      case 23: // ELSE
      case 24: // ELSEIF
      case 25: // THEN
      case 26: // MODULO
      case 27: // EQ
      case 28: // CURLYO
      case 29: // CURLYC
      case 30: // BRACKETO
      case 31: // BRACKETC
      case 32: // LENGTHOP
      case 33: // REPEAT
      case 34: // UNTIL
      case 35: // GREATER
      case 36: // LESS
      case 37: // FALSE
      case 38: // TRUE
      case 39: // FUNCTION
      case 40: // COLON
      case 41: // VARARG
      case 42: // RETURN
      case 43: // BREAK
      case 65: // fieldsep
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 45: // stream
      case 46: // chunk
      case 47: // laststat
      case 48: // block
      case 49: // stat
      case 50: // funcbody
      case 51: // parlist
      case 52: // namelist
      case 53: // funcname
      case 54: // repeatStat
      case 55: // forStat
      case 56: // ifStat
      case 57: // elseifList
      case 58: // elseBlock
      case 59: // functioncall
      case 60: // args
      case 61: // explist
      case 62: // prefixexp
      case 63: // tableconstructor
      case 64: // fieldlist
      case 66: // field
      case 67: // varlist
      case 68: // String
      case 69: // var
      case 70: // exp
      case 71: // expression
      case 72: // term
      case 73: // circumflex
      case 74: // factor
      case 75: // number
      case 76: // bool
      case 77: // name
        value.copy< Node > (that.value);
        break;

      case 3: // PLUS
      case 4: // EQUALS
      case 5: // SEMI
      case 6: // MINUS
      case 7: // INTEGER
      case 8: // FLOAT
      case 9: // STAR
      case 10: // SLASH
      case 11: // OPENP
      case 12: // CLOSEP
      case 13: // COMMA
      case 14: // CIRCUMFLEX
      case 15: // NEWL
      case 16: // Name
      case 17: // STRING
      case 18: // DOT
      case 19: // FOR
      case 20: // DO
      case 21: // END
      case 22: // IF
      case 23: // ELSE
      case 24: // ELSEIF
      case 25: // THEN
      case 26: // MODULO
      case 27: // EQ
      case 28: // CURLYO
      case 29: // CURLYC
      case 30: // BRACKETO
      case 31: // BRACKETC
      case 32: // LENGTHOP
      case 33: // REPEAT
      case 34: // UNTIL
      case 35: // GREATER
      case 36: // LESS
      case 37: // FALSE
      case 38: // TRUE
      case 39: // FUNCTION
      case 40: // COLON
      case 41: // VARARG
      case 42: // RETURN
      case 43: // BREAK
      case 65: // fieldsep
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 45: // stream
      case 46: // chunk
      case 47: // laststat
      case 48: // block
      case 49: // stat
      case 50: // funcbody
      case 51: // parlist
      case 52: // namelist
      case 53: // funcname
      case 54: // repeatStat
      case 55: // forStat
      case 56: // ifStat
      case 57: // elseifList
      case 58: // elseBlock
      case 59: // functioncall
      case 60: // args
      case 61: // explist
      case 62: // prefixexp
      case 63: // tableconstructor
      case 64: // fieldlist
      case 66: // field
      case 67: // varlist
      case 68: // String
      case 69: // var
      case 70: // exp
      case 71: // expression
      case 72: // term
      case 73: // circumflex
      case 74: // factor
      case 75: // number
      case 76: // bool
      case 77: // name
        yylhs.value.build< Node > ();
        break;

      case 3: // PLUS
      case 4: // EQUALS
      case 5: // SEMI
      case 6: // MINUS
      case 7: // INTEGER
      case 8: // FLOAT
      case 9: // STAR
      case 10: // SLASH
      case 11: // OPENP
      case 12: // CLOSEP
      case 13: // COMMA
      case 14: // CIRCUMFLEX
      case 15: // NEWL
      case 16: // Name
      case 17: // STRING
      case 18: // DOT
      case 19: // FOR
      case 20: // DO
      case 21: // END
      case 22: // IF
      case 23: // ELSE
      case 24: // ELSEIF
      case 25: // THEN
      case 26: // MODULO
      case 27: // EQ
      case 28: // CURLYO
      case 29: // CURLYC
      case 30: // BRACKETO
      case 31: // BRACKETC
      case 32: // LENGTHOP
      case 33: // REPEAT
      case 34: // UNTIL
      case 35: // GREATER
      case 36: // LESS
      case 37: // FALSE
      case 38: // TRUE
      case 39: // FUNCTION
      case 40: // COLON
      case 41: // VARARG
      case 42: // RETURN
      case 43: // BREAK
      case 65: // fieldsep
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 106 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("stream", ""); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); 
  root = yylhs.value.as< Node > (); 
  }
#line 704 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 111 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
    root = yylhs.value.as< Node > ();
}
#line 714 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 118 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 722 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 121 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 731 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 125 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 739 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 128 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
  }
#line 747 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 133 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("return", "");
}
#line 755 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 136 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("return", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 764 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 140 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("break", "");
}
#line 772 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 145 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("block", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  chunkTemp = yylhs.value.as< Node > ();
}
#line 782 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 150 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = chunkTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  chunkTemp = yylhs.value.as< Node > ();
}
#line 792 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 157 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("assignment", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 802 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 162 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 810 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 165 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 818 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 168 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 826 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 171 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 834 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 174 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("function", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 844 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 181 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("funcbody", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 853 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 185 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("funcbody", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 863 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 192 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
}
#line 871 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 194 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("parlist", yystack_[0].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
}
#line 880 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 197 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("parlist", yystack_[0].value.as< std::string > ());
}
#line 888 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 201 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  namelistTemp = yylhs.value.as< Node > ();
}
#line 897 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 205 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = namelistTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  namelistTemp = yylhs.value.as< Node > ();
}
#line 907 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 211 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
}
#line 915 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 213 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("funcname", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 924 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 216 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[2].value.as< Node > ();
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 933 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 222 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("repeat", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 943 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 229 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("for", "");
  Node assignmentNode = Node("assignment", yystack_[6].value.as< std::string > ());
  assignmentNode.children.push_back(yystack_[7].value.as< Node > ());
  assignmentNode.children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(assignmentNode);
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 957 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 238 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("for", "");
  Node assignmentNode = Node("assignment", yystack_[8].value.as< std::string > ());
  assignmentNode.children.push_back(yystack_[9].value.as< Node > ());
  assignmentNode.children.push_back(yystack_[7].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(assignmentNode);
  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 972 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 251 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 982 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 256 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 993 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 262 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 1005 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 269 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 1016 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 277 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("elseif", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 1026 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 282 "binary.yy" // lalr1.cc:859
    {
  // Sätt in en temp variabel
  yylhs.value.as< Node > () = yystack_[4].value.as< Node > ();
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 1037 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 290 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("else", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 1046 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 296 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("functioncall", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1056 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 303 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("args", ""); 
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  }
#line 1065 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 307 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("args", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1074 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 313 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("explist", ""); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); 
    expListTemp = yylhs.value.as< Node > ();
  }
#line 1084 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 318 "binary.yy" // lalr1.cc:859
    {
  std::cout << "->>Here: " << yystack_[0].value.as< Node > ().value << std::endl;
      yylhs.value.as< Node > () = expListTemp;
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      expListTemp = yylhs.value.as< Node > ();
  }
#line 1095 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 326 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1103 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 329 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
  }
#line 1111 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 332 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1119 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 337 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("tableconstructor", "");
}
#line 1127 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 340 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
}
#line 1135 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 345 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("fieldlist", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  fieldListTemp = yylhs.value.as< Node > ();
}
#line 1145 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 350 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = fieldListTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  fieldListTemp = yylhs.value.as< Node > ();

}
#line 1156 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 356 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = fieldListTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  fieldListTemp = yylhs.value.as< Node > ();
}
#line 1166 "binary.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 365 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("assignment", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 1176 "binary.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 369 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("assignment", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 1186 "binary.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 373 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
}
#line 1194 "binary.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 378 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("varlist", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  varListTemp = yylhs.value.as< Node > ();
}
#line 1204 "binary.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 383 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = varListTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  varListTemp = yylhs.value.as< Node > ();
}
#line 1214 "binary.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 390 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("string", yystack_[0].value.as< std::string > ());
  }
#line 1222 "binary.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 395 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1230 "binary.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 398 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("var", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1240 "binary.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 403 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("index", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  }
#line 1250 "binary.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 410 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 1258 "binary.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 413 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 1266 "binary.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 416 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1274 "binary.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 419 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1282 "binary.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 422 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1292 "binary.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 427 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1302 "binary.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 432 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1312 "binary.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 437 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 1320 "binary.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 442 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1330 "binary.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 447 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1340 "binary.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 452 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 1348 "binary.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 456 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1358 "binary.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 461 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1368 "binary.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 466 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1378 "binary.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 471 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
    }
#line 1386 "binary.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 475 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1392 "binary.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 476 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1402 "binary.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 481 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1412 "binary.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 488 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 1420 "binary.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 491 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("unary", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1429 "binary.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 495 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("unary", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1438 "binary.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 499 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1444 "binary.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 502 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("int", yystack_[0].value.as< std::string > ());}
#line 1450 "binary.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 503 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("float", yystack_[0].value.as< std::string > ());}
#line 1456 "binary.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 506 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("boolean", yystack_[0].value.as< std::string > ());
}
#line 1464 "binary.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 509 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("boolean", yystack_[0].value.as< std::string > ());
}
#line 1472 "binary.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 514 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("name", yystack_[0].value.as< std::string > ());
}
#line 1480 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1484 "binary.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -73;

  const signed char parser::yytable_ninf_ = -82;

  const short int
  parser::yypact_[] =
  {
     390,   113,   -73,     1,   113,   390,     1,   113,   -73,    83,
       7,   -73,   -73,   -73,   -73,   -73,    49,    52,    10,   129,
     -73,    20,   -73,   -73,   -73,   197,     1,   -73,   -73,   -73,
     425,   -73,   -73,   -73,   -11,    50,    -6,   -73,     5,   -73,
     -73,    29,   144,     7,   263,    -5,   -73,    24,    37,   -73,
       7,   -73,   -73,   113,     1,   113,   -73,   -73,   113,   112,
      52,   -73,   -73,   113,    33,   -73,    37,    44,   -73,   -73,
     113,   113,   113,    20,    20,    20,    20,    20,    20,   113,
     390,   113,     7,     6,     1,     1,   -73,   113,    62,   -73,
      82,    24,   134,   216,   -73,   -73,   -73,   304,   113,    37,
      37,    37,    -6,    -6,   -73,    -6,    -6,    52,   -73,    68,
     217,    37,   390,   -73,    59,    28,   -73,   -73,   -73,    37,
     -73,   -73,    86,   -73,    37,   113,   -73,   390,   113,   151,
      75,   336,   390,    16,   113,   273,   390,   182,   -73,   113,
      76,   -73,   -73,   349,   -73,   -73,    37,   113,   390,   390,
     195,   -73,   -73,    71,   365,   390,   390,   390,   -73,   390,
     378,   -73
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,    89,     0,     0,     0,     0,     8,    10,     0,
       2,     6,     4,    17,    15,    16,    14,     0,     0,    44,
      60,     0,    85,    86,    59,     0,     0,    88,    87,    46,
      65,    66,    64,    44,     0,    63,    73,    77,    78,    84,
      70,     0,     0,    11,     0,     0,    26,     9,    42,     1,
       3,     7,     5,     0,     0,     0,    39,    41,     0,     0,
      81,    82,    47,     0,     0,    49,    56,    60,    83,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    18,     0,     0,    61,
       0,    13,    44,     0,    53,    52,    48,    51,     0,    67,
      68,    69,    71,    72,    74,    75,    76,    80,    79,     0,
       0,    29,     0,    23,     0,    21,    24,    27,    28,    43,
      40,    62,     0,    50,    55,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    33,     0,
       0,    35,    19,     0,    22,    25,    54,     0,     0,     0,
       0,    34,    20,     0,     0,    36,     0,     0,    30,    37,
       0,    31
  };

  const short int
  parser::yypgoto_[] =
  {
     -73,   -73,    42,    11,   -72,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -29,    34,   -73,    81,   191,   -73,
     -73,   -73,    14,   -73,   -15,     0,   220,   -73,   250,   -73,
     -10,   -73,   -73,     4
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     9,    43,    11,    44,    12,    86,   114,   115,    45,
      13,    14,    15,   129,   130,    29,    56,    47,    17,    31,
      64,    97,    65,    18,    32,    33,    48,    35,    36,    37,
      38,    39,    40,    20
  };

  const short int
  parser::yytable_[] =
  {
      19,    69,    57,    75,    76,    19,    83,    41,   110,    19,
      46,    61,    51,    84,    58,    57,    70,     2,   112,    78,
      77,    52,     2,    59,    71,    72,    21,    22,    23,    67,
      68,     1,     2,    79,    16,    85,     2,    87,    94,    16,
     131,   133,    10,    16,    19,    57,    95,   113,    98,     7,
       8,    50,    26,    73,    52,   136,    74,   144,    89,    92,
     143,    52,    96,    53,    70,   104,   -46,   -46,   108,    24,
      54,   132,    71,    72,   120,    87,   154,   155,    16,   -46,
      19,   125,    55,    49,   159,   160,    82,   116,   117,   118,
     134,   157,    57,    52,     1,    70,   141,   151,    70,     2,
     140,    67,     3,    71,    72,     4,    71,    72,     0,    70,
      19,   123,    19,   121,    16,     0,     5,    71,    72,    21,
      22,    23,     6,     1,     1,     7,     8,    19,     2,     2,
      24,    19,    19,   -57,    88,     0,    19,   145,   -58,    91,
       0,    25,   -57,    19,    16,    26,    16,   -58,    19,    19,
      27,    28,    82,     0,    19,    19,    19,    19,     0,    19,
      19,    16,     0,     0,     0,    16,    16,     0,     0,    80,
      16,    70,   138,    82,   127,   139,     0,    16,    82,    71,
      72,     0,    16,    16,     0,    82,     0,     0,    16,    16,
      16,    16,    30,    16,    16,    30,    82,    82,    30,     0,
       0,    82,    82,    21,    22,    23,     0,   149,     1,    70,
       0,     0,    60,     2,    24,     0,    30,    71,    72,     0,
     156,    34,    70,     0,    42,    25,    62,    63,     1,    26,
      71,    72,     0,     2,    27,    28,     3,     0,   126,     4,
     127,   128,     0,    70,    30,    66,    30,   122,     0,    30,
       5,    71,    72,     0,    30,     0,     6,     0,     0,     7,
       8,    30,    30,    30,    60,    60,    60,    60,    60,   107,
      30,     0,    30,     0,     1,    90,     0,     0,    30,     2,
       0,     0,     3,    93,     0,     4,   147,     0,    30,    30,
      99,   100,   101,   148,     0,     0,     5,    81,     0,   109,
      70,   111,     6,     0,     0,     7,     8,   119,    71,    72,
      21,    22,    23,     0,     0,     1,    30,    66,   124,    30,
       2,    24,     0,   102,   103,    30,   105,   106,     0,     0,
      30,     0,    25,     0,    63,     0,    26,     0,    30,     0,
       0,    27,    28,     0,     0,   135,     0,     1,   137,     0,
       0,     0,     2,     0,   146,     3,     0,   142,     4,   150,
       1,     0,     0,     0,     0,     2,     0,   153,     3,     5,
     152,     4,     0,     0,     0,     6,     1,     0,     7,     8,
       0,     2,     5,     0,     3,     0,   158,     4,     6,     1,
       0,     7,     8,     0,     2,     0,     0,     3,     5,   161,
       4,     1,     0,     0,     6,     0,     2,     7,     8,     3,
       0,     5,     4,     0,     0,     0,     0,     6,     0,     0,
       7,     8,     0,     5,     0,     0,     0,     0,   -81,     6,
       0,   -81,     7,     8,   -81,   -81,    53,     0,     0,   -81,
       0,     0,    24,    54,     0,     0,     0,     0,     0,     0,
       0,   -81,     0,     0,     0,    55
  };

  const short int
  parser::yycheck_[] =
  {
       0,    12,    17,     9,    10,     5,    11,     3,    80,     9,
       6,    21,     5,    18,     4,    30,    27,    16,    12,    14,
      26,    10,    16,    13,    35,    36,     6,     7,     8,    25,
      26,    11,    16,     4,     0,    40,    16,    13,     5,     5,
     112,    13,     0,     9,    44,    60,    13,    41,     4,    42,
      43,     9,    32,     3,    43,   127,     6,    41,    54,    59,
     132,    50,    29,    11,    27,    75,    17,    18,    78,    17,
      18,    12,    35,    36,    12,    13,   148,   149,    44,    30,
      80,    13,    30,     0,   156,   157,    44,    83,    84,    85,
       4,    20,   107,    82,    11,    27,    21,    21,    27,    16,
     129,    97,    19,    35,    36,    22,    35,    36,    -1,    27,
     110,    97,   112,    31,    80,    -1,    33,    35,    36,     6,
       7,     8,    39,    11,    11,    42,    43,   127,    16,    16,
      17,   131,   132,     4,    53,    -1,   136,   133,     4,    58,
      -1,    28,    13,   143,   110,    32,   112,    13,   148,   149,
      37,    38,   110,    -1,   154,   155,   156,   157,    -1,   159,
     160,   127,    -1,    -1,    -1,   131,   132,    -1,    -1,    25,
     136,    27,    21,   131,    23,    24,    -1,   143,   136,    35,
      36,    -1,   148,   149,    -1,   143,    -1,    -1,   154,   155,
     156,   157,     1,   159,   160,     4,   154,   155,     7,    -1,
      -1,   159,   160,     6,     7,     8,    -1,    25,    11,    27,
      -1,    -1,    21,    16,    17,    -1,    25,    35,    36,    -1,
      25,     1,    27,    -1,     4,    28,    29,    30,    11,    32,
      35,    36,    -1,    16,    37,    38,    19,    -1,    21,    22,
      23,    24,    -1,    27,    53,    25,    55,    31,    -1,    58,
      33,    35,    36,    -1,    63,    -1,    39,    -1,    -1,    42,
      43,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    81,    -1,    11,    55,    -1,    -1,    87,    16,
      -1,    -1,    19,    63,    -1,    22,    13,    -1,    97,    98,
      70,    71,    72,    20,    -1,    -1,    33,    34,    -1,    79,
      27,    81,    39,    -1,    -1,    42,    43,    87,    35,    36,
       6,     7,     8,    -1,    -1,    11,   125,    97,    98,   128,
      16,    17,    -1,    73,    74,   134,    76,    77,    -1,    -1,
     139,    -1,    28,    -1,    30,    -1,    32,    -1,   147,    -1,
      -1,    37,    38,    -1,    -1,   125,    -1,    11,   128,    -1,
      -1,    -1,    16,    -1,   134,    19,    -1,    21,    22,   139,
      11,    -1,    -1,    -1,    -1,    16,    -1,   147,    19,    33,
      21,    22,    -1,    -1,    -1,    39,    11,    -1,    42,    43,
      -1,    16,    33,    -1,    19,    -1,    21,    22,    39,    11,
      -1,    42,    43,    -1,    16,    -1,    -1,    19,    33,    21,
      22,    11,    -1,    -1,    39,    -1,    16,    42,    43,    19,
      -1,    33,    22,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    43,    -1,    33,    -1,    -1,    -1,    -1,     3,    39,
      -1,     6,    42,    43,     9,    10,    11,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    30
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    11,    16,    19,    22,    33,    39,    42,    43,    45,
      46,    47,    49,    54,    55,    56,    59,    62,    67,    69,
      77,     6,     7,     8,    17,    28,    32,    37,    38,    59,
      62,    63,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    70,    46,    48,    53,    77,    61,    70,     0,
      46,     5,    47,    11,    18,    30,    60,    68,     4,    13,
      62,    74,    29,    30,    64,    66,    70,    77,    77,    12,
      27,    35,    36,     3,     6,     9,    10,    26,    14,     4,
      25,    34,    46,    11,    18,    40,    50,    13,    61,    77,
      70,    61,    69,    70,     5,    13,    29,    65,     4,    70,
      70,    70,    72,    72,    74,    72,    72,    62,    74,    70,
      48,    70,    12,    41,    51,    52,    77,    77,    77,    70,
      12,    31,    31,    66,    70,    13,    21,    23,    24,    57,
      58,    48,    12,    13,     4,    70,    48,    70,    21,    24,
      58,    21,    21,    48,    41,    77,    70,    13,    20,    25,
      70,    21,    21,    70,    48,    48,    25,    20,    21,    48,
      48,    21
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    44,    45,    45,    46,    46,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    53,    54,
      55,    55,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    60,    61,    61,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    77
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     2,     3,     1,     1,     1,     1,     3,     4,
       5,     1,     3,     1,     1,     3,     1,     3,     3,     4,
       9,    11,     5,     6,     7,     6,     4,     5,     2,     2,
       3,     1,     1,     3,     1,     3,     1,     2,     3,     1,
       3,     2,     1,     1,     5,     3,     1,     1,     3,     1,
       1,     3,     4,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     3,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUS", "EQUALS", "SEMI",
  "MINUS", "INTEGER", "FLOAT", "STAR", "SLASH", "OPENP", "CLOSEP", "COMMA",
  "CIRCUMFLEX", "NEWL", "Name", "STRING", "DOT", "FOR", "DO", "END", "IF",
  "ELSE", "ELSEIF", "THEN", "MODULO", "EQ", "CURLYO", "CURLYC", "BRACKETO",
  "BRACKETC", "LENGTHOP", "REPEAT", "UNTIL", "GREATER", "LESS", "FALSE",
  "TRUE", "FUNCTION", "COLON", "VARARG", "RETURN", "BREAK", "$accept",
  "stream", "chunk", "laststat", "block", "stat", "funcbody", "parlist",
  "namelist", "funcname", "repeatStat", "forStat", "ifStat", "elseifList",
  "elseBlock", "functioncall", "args", "explist", "prefixexp",
  "tableconstructor", "fieldlist", "fieldsep", "field", "varlist",
  "String", "var", "exp", "expression", "term", "circumflex", "factor",
  "number", "bool", "name", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   106,   106,   111,   118,   121,   125,   128,   133,   136,
     140,   145,   150,   157,   162,   165,   168,   171,   174,   181,
     185,   192,   194,   197,   201,   205,   211,   213,   216,   222,
     229,   238,   251,   256,   262,   269,   277,   282,   290,   296,
     303,   307,   313,   318,   326,   329,   332,   337,   340,   345,
     350,   356,   363,   363,   365,   369,   373,   378,   383,   390,
     395,   398,   403,   410,   413,   416,   419,   422,   427,   432,
     437,   442,   447,   452,   456,   461,   466,   471,   475,   476,
     481,   488,   491,   495,   499,   502,   503,   506,   509,   514
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1931 "binary.tab.cc" // lalr1.cc:1167
#line 518 "binary.yy" // lalr1.cc:1168
