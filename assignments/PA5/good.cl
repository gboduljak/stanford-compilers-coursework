class C inherits IO {
	a : Int;
	b : Bool;
	cd : D;

	init(x : Int, y : Bool) : C {
           {
		a <- x;
		b <- y;
		out_int(x);
		out_int(a);
		self;
           }
	};
};

class D inherits C {
	d : Bool;
};

class E inherits D {
	e : String;
};

class F {

};

Class Main inherits C {
	main():C {
	  (new C).init(1,true)
	};
};