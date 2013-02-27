(* mccartnay *)


(* Question IX *)

let rec power2 = function (x,n) -> if n = 0 then 1 else if n mod 2 = 0 then power2(x*.x,n/2) else x *. power2(x*.x,(n-1)/2);;

(* Question XI *)

let rec cnp = function (n,p) -> if n = 0 then 1 else p * cnp(p,n-1);;

(* Question XII *)

let rec somme = function (n,f) -> if n = 0 then f0 else f(n*f) +. somme(n-1,f);;
somme(30,(function x -> 2.0*.sin(float_of_int x));;

let rec sommeTerm = function (n,f,res) -> if n = 0 then res+.f0 else sommeTerm(n-1,f,res+.f(int_of_float n));;
sommeTerm(15,(function x -> cos(float_of_int x) + float_of_int x),0);;

(* Question XIV *)

let rec suiv = function n -> if n = 0 then n else suiv(n/10) + (n mod 10) * (n mod 10);;

(* Question XV *)

let rec suivn = function (n,x) -> if n = 1 or n = 4 then x else suivn(suiv(n),x+1);;

(* Question XVII *)

let rec bissexion = function (l,h,f) -> let m = (l+h) /. 2. in if float_of_int abs(f(m)) < 0.001 then m else if f(m) <= 0.001 then bissection((l+h)/2,h,f) else bissection(l,m,f);;
