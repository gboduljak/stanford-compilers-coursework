class C {
	a : Int <- ~(3);
	b : Object;

	init(x : Int, y : Bool) : C {
           {
		a <- x;
		b <- y;
		self;
           }
	};
};

Class Main inherits C {

	main():C {
	  {
		init(3, false);
	  	(new SELF_TYPE);
	  }
	};
}; 