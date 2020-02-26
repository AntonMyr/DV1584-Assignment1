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
  Node elseifTemp;
  Node chunkTemp;

#line 66 "binary.tab.cc" // lalr1.cc:413


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
#line 133 "binary.tab.cc" // lalr1.cc:479

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
      case 29: // stream
      case 30: // chunk
      case 31: // block
      case 32: // stat
      case 33: // forStat
      case 34: // ifStat
      case 35: // elseifList
      case 36: // elseBlock
      case 37: // functioncall
      case 38: // args
      case 39: // explist
      case 40: // prefixexp
      case 41: // varlist
      case 42: // String
      case 43: // var
      case 44: // exp
      case 45: // expression
      case 46: // term
      case 47: // circumflex
      case 48: // factor
      case 49: // number
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
      case 29: // stream
      case 30: // chunk
      case 31: // block
      case 32: // stat
      case 33: // forStat
      case 34: // ifStat
      case 35: // elseifList
      case 36: // elseBlock
      case 37: // functioncall
      case 38: // args
      case 39: // explist
      case 40: // prefixexp
      case 41: // varlist
      case 42: // String
      case 43: // var
      case 44: // exp
      case 45: // expression
      case 46: // term
      case 47: // circumflex
      case 48: // factor
      case 49: // number
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
      case 29: // stream
      case 30: // chunk
      case 31: // block
      case 32: // stat
      case 33: // forStat
      case 34: // ifStat
      case 35: // elseifList
      case 36: // elseBlock
      case 37: // functioncall
      case 38: // args
      case 39: // explist
      case 40: // prefixexp
      case 41: // varlist
      case 42: // String
      case 43: // var
      case 44: // exp
      case 45: // expression
      case 46: // term
      case 47: // circumflex
      case 48: // factor
      case 49: // number
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
#line 76 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("stream", ""); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); 
  root = yylhs.value.as< Node > (); 
  }
#line 618 "binary.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 81 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
    root = yylhs.value.as< Node > ();
}
#line 628 "binary.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 95 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 636 "binary.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 98 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
  }
#line 644 "binary.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 103 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("block", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  chunkTemp = yylhs.value.as< Node > ();
}
#line 654 "binary.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 108 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = chunkTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  chunkTemp = yylhs.value.as< Node > ();
}
#line 664 "binary.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 115 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("assignment", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 674 "binary.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 120 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 682 "binary.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 123 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 690 "binary.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 126 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 698 "binary.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 130 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("for", "");
  Node assignmentNode = Node("assignment", yystack_[6].value.as< std::string > ());
  assignmentNode.children.push_back(Node("var", yystack_[7].value.as< std::string > ()));
  assignmentNode.children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(assignmentNode);
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 712 "binary.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 139 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("for", "");
  Node assignmentNode = Node("assignment", yystack_[8].value.as< std::string > ());
  assignmentNode.children.push_back(Node("var", yystack_[9].value.as< std::string > ()));
  assignmentNode.children.push_back(yystack_[7].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(assignmentNode);
  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 727 "binary.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 152 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 737 "binary.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 157 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 748 "binary.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 163 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[5].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[3].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 760 "binary.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 170 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("if", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[4].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
}
#line 771 "binary.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 178 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("elseif", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 781 "binary.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 183 "binary.yy" // lalr1.cc:859
    {
  // Sätt in en temp variabel
  yylhs.value.as< Node > () = yystack_[4].value.as< Node > ();
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 792 "binary.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 191 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("else", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
}
#line 801 "binary.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 197 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("functioncall", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 811 "binary.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 204 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("args", ""); 
  yylhs.value.as< Node > ().children.push_back(yystack_[1].value.as< Node > ());
  }
#line 820 "binary.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 208 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("args", "");
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 829 "binary.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 214 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("explist", ""); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ()); 
    expListTemp = yylhs.value.as< Node > ();
  }
#line 839 "binary.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 219 "binary.yy" // lalr1.cc:859
    {
      yylhs.value.as< Node > () = expListTemp;
      yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
      expListTemp = yylhs.value.as< Node > ();
  }
#line 849 "binary.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 226 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 857 "binary.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 229 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[1].value.as< Node > ();
  }
#line 865 "binary.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 234 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("varlist", "");
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  varListTemp = yylhs.value.as< Node > ();
}
#line 875 "binary.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 239 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = varListTemp;
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  varListTemp = yylhs.value.as< Node > ();
}
#line 885 "binary.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 246 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("string", yystack_[0].value.as< std::string > ());
  }
#line 893 "binary.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 251 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = Node("var", yystack_[0].value.as< std::string > ());
  }
#line 901 "binary.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 254 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("var", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 911 "binary.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 261 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 919 "binary.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 264 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 927 "binary.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 267 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 935 "binary.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 270 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
  }
#line 943 "binary.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 275 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 953 "binary.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 280 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 963 "binary.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 285 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 973 "binary.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 290 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 981 "binary.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 294 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 991 "binary.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 299 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1001 "binary.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 304 "binary.yy" // lalr1.cc:859
    {
  yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
  yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ()); 
  yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1011 "binary.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 309 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();
    }
#line 1019 "binary.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 313 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1025 "binary.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 314 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1035 "binary.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 319 "binary.yy" // lalr1.cc:859
    {
    yylhs.value.as< Node > () = Node("binop", yystack_[1].value.as< std::string > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[2].value.as< Node > ());
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1045 "binary.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 326 "binary.yy" // lalr1.cc:859
    { 
  yylhs.value.as< Node > () = yystack_[0].value.as< Node > (); 
  }
#line 1053 "binary.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 329 "binary.yy" // lalr1.cc:859
    { 
    yylhs.value.as< Node > () = Node("unary", yystack_[1].value.as< std::string > ()); 
    yylhs.value.as< Node > ().children.push_back(yystack_[0].value.as< Node > ());
  }
#line 1062 "binary.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 333 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = yystack_[0].value.as< Node > ();}
#line 1068 "binary.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 336 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("int", yystack_[0].value.as< std::string > ());}
#line 1074 "binary.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 337 "binary.yy" // lalr1.cc:859
    { yylhs.value.as< Node > () = Node("float", yystack_[0].value.as< std::string > ());}
#line 1080 "binary.tab.cc" // lalr1.cc:859
    break;


#line 1084 "binary.tab.cc" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -65;

  const signed char parser::yytable_ninf_ = -49;

  const short int
  parser::yypact_[] =
  {
      46,   142,   -65,     5,   142,    20,   -65,    28,   -65,   -65,
     -65,    72,    13,    36,   154,   -65,   -65,   -65,   -65,     1,
     -65,   -65,    -6,    10,    15,   -65,    31,   -65,    42,    22,
     -65,   -65,   -65,   142,    66,   -65,   -65,   142,    66,    40,
     -65,   -65,   154,   154,   154,   154,   154,   154,   154,   142,
      46,   -10,   -65,    40,    41,    47,    41,    15,    15,    15,
     -65,    15,    15,    40,   -65,    56,   -65,    32,   -65,   142,
     142,   -65,    46,   142,   -65,   113,    52,   -65,   107,    46,
      73,   -65,   142,    64,   -65,   142,    46,    46,    77,   -65,
      90,    59,    46,    46,    46,   -65,    46,   135,   -65
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,    31,     0,     0,     0,     2,     4,    10,    11,
       9,     0,     0,    26,     0,    51,    52,    30,    36,    35,
      34,    26,     0,    33,    40,    44,    45,    50,     0,     0,
       1,     3,     5,     0,     0,    21,    23,     0,     0,    48,
      49,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,    32,     8,    29,    37,    38,    39,
      41,    42,    43,    47,    46,     0,     6,     0,    22,     0,
       0,    14,     0,     0,     7,     0,     0,    25,     0,    20,
       0,    15,     0,     0,    17,     0,     0,     0,     0,    16,
       0,     0,    18,     0,     0,    12,    19,     0,    13
  };

  const signed char
  parser::yypgoto_[] =
  {
     -65,   -65,     9,   -64,   -65,   -65,   -65,   -65,    49,    62,
     -65,    91,    70,   -65,    33,     0,    60,   -65,    79,   -65,
     -13,   -65
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     5,    66,    67,     7,     8,     9,    75,    76,    10,
      35,    51,    11,    12,    20,    21,    52,    23,    24,    25,
      26,    27
  };

  const signed char
  parser::yytable_[] =
  {
      13,    40,    68,    69,   -48,    13,    41,   -48,    79,     6,
     -48,   -48,    33,    42,    31,   -48,    43,    37,    17,    34,
      30,    28,    91,    92,    45,    46,    38,   -48,   -48,    96,
      97,     1,    60,    32,    54,    64,     2,    44,    56,     3,
     -28,    47,     4,     1,    36,    48,    49,    50,     2,   -28,
      13,     3,    36,    71,     4,    72,    73,     1,    34,   -26,
      69,    22,     2,    18,    29,     3,    18,    13,     4,    70,
       1,    19,    13,    84,    19,     2,    74,     1,     3,    13,
      95,     4,     2,    33,    39,    89,    13,    13,    74,    17,
      34,    13,    13,    13,    13,    18,    13,    13,    87,    18,
      74,    74,    93,    19,    53,    74,    74,    19,    53,    65,
      94,    18,    39,    39,    39,    39,    39,    39,    63,    19,
      85,    57,    58,    59,    83,    61,    62,    86,    55,    77,
      78,    18,    18,    80,    81,    18,    72,    82,     0,    19,
      19,     0,    88,    19,    18,    90,     1,    18,    14,    15,
      16,     2,    19,     1,     3,    19,    98,     4,     2,    17,
      14,    15,    16,     0,     0,     1,     0,     0,     0,     0,
       2
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    14,    12,    13,     3,     5,    12,     6,    72,     0,
       9,    10,    11,     3,     5,    14,     6,     4,    17,    18,
       0,    16,    86,    87,     9,    10,    13,    26,    27,    93,
      94,    11,    45,     5,    34,    48,    16,    27,    38,    19,
       4,    26,    22,    11,    11,    14,     4,    25,    16,    13,
      50,    19,    19,    21,    22,    23,    24,    11,    18,    18,
      13,     1,    16,     1,     4,    19,     4,    67,    22,    13,
      11,     1,    72,    21,     4,    16,    67,    11,    19,    79,
      21,    22,    16,    11,    14,    21,    86,    87,    79,    17,
      18,    91,    92,    93,    94,    33,    96,    97,    25,    37,
      91,    92,    25,    33,    34,    96,    97,    37,    38,    49,
      20,    49,    42,    43,    44,    45,    46,    47,    48,    49,
      13,    42,    43,    44,    75,    46,    47,    20,    37,    69,
      70,    69,    70,    73,    21,    73,    23,    24,    -1,    69,
      70,    -1,    82,    73,    82,    85,    11,    85,     6,     7,
       8,    16,    82,    11,    19,    85,    21,    22,    16,    17,
       6,     7,     8,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      16
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    11,    16,    19,    22,    29,    30,    32,    33,    34,
      37,    40,    41,    43,     6,     7,     8,    17,    37,    40,
      42,    43,    44,    45,    46,    47,    48,    49,    16,    44,
       0,    30,     5,    11,    18,    38,    42,     4,    13,    40,
      48,    12,     3,     6,    27,     9,    10,    26,    14,     4,
      25,    39,    44,    40,    43,    39,    43,    46,    46,    46,
      48,    46,    46,    40,    48,    44,    30,    31,    12,    13,
      13,    21,    23,    24,    30,    35,    36,    44,    44,    31,
      44,    21,    24,    36,    21,    13,    20,    25,    44,    21,
      44,    31,    31,    25,    20,    21,    31,    31,    21
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    28,    29,    29,    30,    30,    31,    31,    32,    32,
      32,    32,    33,    33,    34,    34,    34,    34,    35,    35,
      36,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    43,    43,    44,    44,    44,    44,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    47,    48,    48,
      48,    49,    49
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     2,     1,     2,     3,     1,
       1,     1,     9,    11,     5,     6,     7,     6,     4,     5,
       2,     2,     3,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     1,     3,     3,     1,     2,
       1,     1,     1
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
  "ELSE", "ELSEIF", "THEN", "MODULO", "EQ", "$accept", "stream", "chunk",
  "block", "stat", "forStat", "ifStat", "elseifList", "elseBlock",
  "functioncall", "args", "explist", "prefixexp", "varlist", "String",
  "var", "exp", "expression", "term", "circumflex", "factor", "number", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    76,    76,    81,    95,    98,   103,   108,   115,   120,
     123,   126,   130,   139,   152,   157,   163,   170,   178,   183,
     191,   197,   204,   208,   214,   219,   226,   229,   234,   239,
     246,   251,   254,   261,   264,   267,   270,   275,   280,   285,
     290,   294,   299,   304,   309,   313,   314,   319,   326,   329,
     333,   336,   337
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
#line 1438 "binary.tab.cc" // lalr1.cc:1167
#line 340 "binary.yy" // lalr1.cc:1168
