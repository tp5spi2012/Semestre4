(*
        Picard Colas  -- TP1
    Programmation Fonctionnelle
*)


(*
        Question 9°
*)

let rec puissance = function (x, n) ->
    if n = 0 then x
        else if n mod 2 = 0 then x *. puissance(x, n/2)
            else x *. puissance(x*.x, (n-1)/2);;
(*
---------------Question 11°---------------
*)
let rec cnp = function (n, p) ->
    if n > p && p > 0 then cnp(n-1, p) + cnp(n-1, p-1)
        else 1;;



(*
--------Question 12°---------
*)

(*
            1 -a
*)

let rec somme = function(n, f) ->
    if n = 0 then f 0
        else f(n* n) +. somme(n-1, f);;

(*
            1 - b
*)

let f9 = function x ->
    somme(30, function x -> 2.0 *. sin(float_of_int x));;

(*
            2 - a
*)

let rec sommeTerm = function (n, f, res) ->
    if n = 0 then res +. f 0
        else sommeTerm (n-1, f, res +. f(n));;

(*
------------2 - b--------------
*)

sommeTerm (15, (function a -> cos(float_of_int a) +. float_of_int a), 0.);;


(*
------------Question 14----------
*)

let rec suiv = function n ->
    if n/10 = 0  then n*n
        else (n mod 10) * (n mod 1) + suiv(n/10);;
(*
------------Question 15------------
*)
let rec q15 = function n ->
    if n = 1 or n = 4 then 0
        else 1 + q15(suiv(n));;

(*
-----------Question 17------------
*)

let abs = function x ->
    if x >= 0.0 then x
        else x *.(-1.0);;

let rec bissection = function (l, h, f) ->
    let m = (l + h)/2 in
    if abs(f(m)) < 0.001 then m
        else if f(m) < 0.001 then bissection(m, h, f)
            else bissection(h, m, f);;
