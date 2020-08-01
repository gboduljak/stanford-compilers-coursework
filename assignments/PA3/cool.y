/*
*  cool.y
*              Parser definition for the COOL language.
*
*/
%{
  #include <iostream>
  #include "cool-tree.h"
  #include "stringtab.h"
  #include "utilities.h"
  
  extern char *curr_filename;
  
  
  /* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
  for the location of tokens */
    
    extern int node_lineno;          /* set before constructing a tree node
    to whatever you want the line number
    for the tree node to be */
      
      
      #define YYLLOC_DEFAULT(Current, Rhs, N)         \
      Current = Rhs[1];                             \
      node_lineno = Current;
    
    
    #define SET_NODELOC(Current)  \
    node_lineno = Current;
    
    /* IMPORTANT NOTE ON LINE NUMBERS
    *********************************
    * The above definitions and macros cause every terminal in your grammar to 
    * have the line number supplied by the lexer. The only task you have to
    * implement for line numbers to work correctly, is to use SET_NODELOC()
    * before constructing any constructs from non-terminals in your grammar.
    * Example: Consider you are matching on the following very restrictive 
    * (fictional) construct that matches a plus between two integer constants. 
    * (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):
    
    plus_consts	: INT_CONST '+' INT_CONST 
    
    * where INT_CONST is a terminal for an integer constant. Now, a correct
    * action for this rule that attaches the correct line number to plus_const
    * would look like the following:
    
    plus_consts	: INT_CONST '+' INT_CONST 
    {
      // Set the line number of the current non-terminal:
      // ***********************************************
      // You can access the line numbers of the i'th item with @i, just
      // like you acess the value of the i'th exporession with $i.
      //
      // Here, we choose the line number of the last INT_CONST (@3) as the
      // line number of the resulting expression (@$). You are free to pick
      // any reasonable line as the line number of non-terminals. If you 
      // omit the statement @$=..., bison has default rules for deciding which 
      // line number to use. Check the manual for details if you are interested.
      @$ = @3;
      
      
      // Observe that we call SET_NODELOC(@3); this will set the global variable
      // node_lineno to @3. Since the constructor call "plus" uses the value of 
      // this global, the plus node will now have the correct line number.
      SET_NODELOC(@3);
      
      // construct the result node:
      $$ = plus(int_const($1), int_const($3));
    }
    
    */
    
    
    
    void yyerror(char *s);        /*  defined below; called for each parse error */
    extern int yylex();           /*  the entry point to the lexer  */
    
    /************************************************************************/
    /*                DONT CHANGE ANYTHING IN THIS SECTION                  */
    
    Program ast_root;	      /* the result of the parse  */
    Classes parse_results;        /* for use in semantic analysis */
    int omerrs = 0;               /* number of errors in lexing and parsing */
    %}
    
    /* A union of all the types that can be the result of parsing actions. */
    %union {
      Boolean boolean;
      Symbol symbol;
      Program program;
      Class_ class_;
      Classes classes;
      Feature feature;
      Features features;
      Formal formal;
      Formals formals;
      Case case_;
      Cases cases;
      Expression expression;
      Expressions expressions;
      char *error_msg;
    }
    
    /* 
    Declare the terminals; a few have types for associated lexemes.
    The token ERROR is never used in the parser; thus, it is a parse
    error when the lexer returns it.
    
    The integer following token declaration is the numeric constant used
    to represent that token internally.  Typically, Bison generates these
    on its own, but we give explicit numbers to prevent version parity
    problems (bison 1.25 and earlier start at 258, later versions -- at
    257)
    */
    %token CLASS 258 ELSE 259 FI 260 IF 261 IN 262 
    %token INHERITS 263 LET 264 LOOP 265 POOL 266 THEN 267 WHILE 268
    %token CASE 269 ESAC 270 OF 271 DARROW 272 NEW 273 ISVOID 274
    %token <symbol>  STR_CONST 275 INT_CONST 276 
    %token <boolean> BOOL_CONST 277
    %token <symbol>  TYPEID 278 OBJECTID 279 
    %token ASSIGN 280 NOT 281 LE 282 ERROR 283
    
    /*  DON'T CHANGE ANYTHING ABOVE THIS LINE, OR YOUR PARSER WONT WORK       */
    /**************************************************************************/
    
    /* Complete the nonterminal list below, giving a type for the semantic
    value of each non terminal. (See section 3.6 in the bison 
    documentation for details). */
    
    /* Declare types for the grammar's non-terminals. */
    %type <program> program
    %type <classes> class_list
    %type <class_> class
    
    /* You will want to change the following line. */
    %type <feature> feature
    %type <features> features
    %type <formal> formal
    %type <formals> formals
    %type <case_> branch
    %type <cases> branches
    %type <expression> expression
    %type <expression> block_expression
    %type <expressions> block_expressions
    %type <expressions> arguments_expressions
    %type <expression> dispatch_expression
    %type <expression> let_expression
    %type <expression> let_assign
    %type <feature> method_declaration
    %type <feature> attribute_declaration

    %right ASSIGN
    %precedence NOT
    %nonassoc '<' '=' LE
    %left '+' '-'
    %left '*' '/'
    %precedence ISVOID
    %precedence '~'
    %precedence '@'
    %precedence '.'
    %%
    /* 
    Save the root of the abstract syntax tree in a global variable.
    */
    program	: class_list	
            { 
              @$ = @1; 
              ast_root = program($1); 
            }
    ;
    
    class_list  : 
                class
                { 
                  @$ = @1; 
                  $$ = single_Classes($1);
                }
                | class_list class
                { 
                  @$ = @2; 
                  $$ = append_Classes($1,single_Classes($2)); 
                }
    ;
    
    class : 
          CLASS TYPEID '{' features '}' ';'
          {
            @$ = @6;
            $$ = class_($2,idtable.add_string("Object"),$4, stringtable.add_string(curr_filename)); 
          }
          | CLASS TYPEID INHERITS TYPEID '{' features '}' ';'
            { 
              @$ = @8;
              $$ = class_($2,$4,$6,stringtable.add_string(curr_filename)); 
            }
          | error ';' {  }
    ;
    
    features  : 
              {
                $$ = nil_Features();
              }
              | feature 
              {
                @$ = @1; 
                $$ = single_Features($1);
              }
              | features feature 
              {
                @$ = @2; 
                $$ = append_Features($1, single_Features($2));
              }
    ;

    feature : 
            method_declaration ';'
            {
                @$ = @2;
                $$ = $1;
            }
            | attribute_declaration ';'
            {
              @$ = @2;
              $$ = $1;
            }
            | error ';' {  }
    ;

    method_declaration  : 
                        OBJECTID '(' formals ')' ':' TYPEID '{' expression '}'
                        {
                          @$ = @9;
                          $$ = method($1, $3, $6, $8);
                        }
                        ;
    
    attribute_declaration : 
                          OBJECTID ':' TYPEID
                          {
                            @$ = @3;
                            $$ = attr($1, $3, no_expr());
                          }
                          | OBJECTID ':' TYPEID ASSIGN '{' expression '}'
                          {
                            @$ = @7;
                            $$ = attr($1, $3, $6);
                          }
                          | OBJECTID ':' TYPEID ASSIGN expression
                          {
                            @$ = @5;
                            $$ = attr($1, $3, $5);
                          }
    ;

    formals :
            {
              $$ = nil_Formals();
            }
            | formal 
            {
              @$ = @1;
              $$ = single_Formals($1);
            }
            |
            formals ',' formal 
            {
              @$ = @2; 
              $$ = append_Formals($1,single_Formals($3)); 
            }
    ;

    formal  : 
            OBJECTID ':' TYPEID 
            {
              @$ = @3;
              $$ = formal($1, $3);
            }
    ;

    expression  : 
                OBJECTID ASSIGN expression 
                {
                  @$ = @3;
                  $$ = assign($1, $3);
                }
                | dispatch_expression 
                {
                  @$ = @1;
                  $$ = $1;
                }
                | LET let_expression 
                {
                  @$ = @2;
                  $$ = $2;
                }
                | IF expression THEN expression
                {
                  @$ = @4;
                  $$ = cond($2,$4, no_expr());
                }
                | IF expression THEN expression ELSE expression FI
                {
                  @$ = @4;
                  $$ = cond($2,$4,$6);
                }
                | WHILE expression LOOP expression POOL
                {
                  @$ = @5;
                  $$ = loop($2, $4);
                }
                | '{' block_expressions '}'
                {
                  @$ = @2;
                  $$ = block($2);
                }
                | CASE expression OF branches ESAC
                {
                  @$ = @5;
                  $$ = typcase($2, $4);
                }
                | NEW TYPEID 
                {
                  @$ = @2;
                  $$ = new_($2);
                }
                | ISVOID expression 
                {
                  @$ = @2;
                  $$ = isvoid($2);
                }
                | expression '+' expression
                {
                  @$ = @3;
                  $$ = plus($1, $3);
                }
                | expression '-' expression
                {
                  @$ = @3;
                  $$ = sub($1, $3);
                }
                | expression '*' expression
                {
                  @$ = @3;
                  $$ = mul($1, $3);
                }
                | expression '/' expression
                {
                  @$ = @3;
                  $$ = divide($1, $3);
                }
                | '~' expression
                {
                  @$ = @2;
                  $$ = neg($2);
                }
                | NOT expression {
                  @$ = @2;
                  $$ = comp($2);
                }
                | expression LE expression
                {
                  @$ = @3;
                  $$ = leq($1, $3);
                }
                | expression '<' expression
                {
                  @$ = @3;
                  $$ = lt($1, $3);
                }
                | expression '=' expression
                {
                  @$ = @3;
                  $$ = eq($1, $3);
                }
                | '(' expression ')'
                {
                  @$ = @2;
                  $$ = $2;
                }
                | INT_CONST 
                {
                  @$ = @1;
                  $$ = int_const($1);
                }
                | STR_CONST
                {
                  @$ = @1;
                  $$ = string_const($1);
                }
                | BOOL_CONST 
                {
                  @$ = @1;
                  $$ = bool_const($1); 
                }
                | OBJECTID 
                {
                  @$ = @1;
                  $$ = object($1); 
                }
    ;

    block_expressions : 
                      block_expression 
                      {
                        @$ = @1;
                        $$ = single_Expressions($1);
                      }
                      | block_expressions block_expression 
                      {
                        @$ = @2;
                        $$ = append_Expressions($1,single_Expressions($2));
                      }
                      | error ';' { yyerrok; }
    ;

    block_expression  : 
                      expression ';' 
                      {
                        $$ = $1;
                      }
    ;

    branches  : 
              branch 
              {
                @$ = @1;
                $$ = single_Cases($1);
              }
              | branches branch 
              {
                @$ = @2;
                $$ = append_Cases($1, single_Cases($2));
              }
    ;

    branch  : 
            OBJECTID ':' TYPEID DARROW expression ';'
            {
              @$ = @6;
              $$ = branch($1, $3, $5);
            }
    ;

    arguments_expressions : 
                          ',' expression 
                          {
                            @$ = @1;
                            $$ = single_Expressions($2);
                          }
                          | arguments_expressions ',' expression
                          {
                            @$ = @3;
                            $$ = append_Expressions($1, single_Expressions($3));
                          }
    ;

    let_expression  : 
                    OBJECTID ':' TYPEID let_assign IN expression 
                    {
                      @$ = @6;
                      $$ = let($1, $3, $4, $6);
                    }
                    | OBJECTID ':' TYPEID let_assign ',' let_expression
                    {      
                      @$ = @6;
                      $$ = let($1, $3, $4, $6);
                    }
                    | error ',' { yyerrok; }
    ;

    let_assign  :
                {
                  $$ = no_expr();
                }
                | ASSIGN expression 
                {
                  @$ = @2;
                  $$ = $2;
                }
    ;

    dispatch_expression : 
                        OBJECTID '(' ')'
                        {
                          @$ = @3;
                          $$ = dispatch(object(idtable.add_string("self")), $1, nil_Expressions());
                        }
                        | OBJECTID '(' expression ')'
                        {
                          @$ = @3;
                          $$ = dispatch(object(idtable.add_string("self")), $1, single_Expressions($3));
                        }
                        | OBJECTID '(' expression arguments_expressions  ')'
                        {
                          @$ = @3;
                          $$ = dispatch(object(idtable.add_string("self")), $1, append_Expressions(single_Expressions($3), $4));
                        }
                        | expression '.' OBJECTID '(' ')'
                        { 
                          @$ = @5;
                          $$ = dispatch($1, $3, nil_Expressions());
                        }
                        | expression '.' OBJECTID '(' expression ')'
                        {
                          @$ = @6;
                          $$ = dispatch($1, $3, single_Expressions($5));
                        }
                        | expression '.' OBJECTID '(' expression arguments_expressions ')'
                        {
                          @$ = @7;
                          $$ = dispatch($1, $3, append_Expressions(single_Expressions($5), $6));
                        }
                        | expression '@' TYPEID '.' OBJECTID '(' ')'
                        {
                          @$ = @7;
                          $$ = static_dispatch($1, $3, $5, nil_Expressions());
                        }
                        | expression '@' TYPEID '.' OBJECTID '(' expression ')'
                        {
                          @$ = @8;
                          $$ = static_dispatch($1, $3, $5, single_Expressions($7));
                        }
                        | expression '@' TYPEID '.' OBJECTID '(' expression arguments_expressions ')'
                        {
                          @$ = @9;
                          $$ = static_dispatch($1, $3, $5, append_Expressions(single_Expressions($7), $8));
                        }
    ;

    /* end of grammar */
    %%
    
    /* This function is called automatically when Bison detects a parse error. */
    void yyerror(char *s)
    {
      extern int curr_lineno;
      
      cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
      << s << " at or near ";
      print_cool_token(yychar);
      cerr << endl;
      omerrs++;
      
      if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
    }
    
    