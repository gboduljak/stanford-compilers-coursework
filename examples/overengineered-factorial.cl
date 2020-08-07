class BinOp {
  operate ( a : Int , b : Int ) : Int {
    a + b
  };
  optype () : String {
    " BinOp "
  };
};
class SumOp inherits BinOp {
  optype () : String {
    " SumOp "
  };
};
class MulOp inherits BinOp {
  optype () : String {
    " MulOp "
  };
  operate ( a : Int , b : Int ) : Int {
    a * b
  };
};
class IntList {
  head : Int ;
  tail : IntList ;
  empty_tail : IntList ; -- Do not assign .
  tail_is_empty () : Bool {
    tail = empty_tail
  };
  get_head () : Int { head };
  set_head ( n : Int ) : Int {
    head <- n
  };
  get_tail () : IntList { tail };
  set_tail ( t : IntList ) : IntList {
    tail <- t
  };
  generate ( n : Int ) : IntList {
    let l : IntList <- New IntList in {
    l . set_head ( n ) ; -- Point A
    if ( n = 1) then
      l . set_tail ( empty_tail )
    else
      l . set_tail ( generate (n -1) )
    fi ;
    l ;
  }
};
};
class Main {
  reduce (result : Int , op : BinOp , l : IntList ) : Int {
    {
      result <- op.operate ( result , l . get_head () );
      if (l.tail_is_empty() = true)
        then result 
      else 
        reduce(result,op,l.get_tail())
      fi;
    }
  };
  main() : Object {
    let op : BinOp <- New MulOp, l : IntList <- New IntList , io : IO <- New IO in {
      l <- l . generate (4) ;
      io . out_int ( self . reduce (1 , op , l ) ) ;
    }
  };
};