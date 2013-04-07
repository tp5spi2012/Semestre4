(* mccartnay *)

(* Déclaration *)

type 'a liste = vide | cons of 'a * 'a liste;;

type 'a arbre = V | N of 'a * 'a arbre * 'a arbre;;

let tete = function cons(x, y) -> x
    | vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
    | vide -> failwith "impossible";;

(* QUESTION I *)

(* Ensemble 1 *)

let rec compteur = function l ->
    if l = vide
        then 0
    else
        snd(tete l) + compteur(suite l);;

(* Ensemble 2 *)

let rec compteur2 = function V -> 0
    | N(x, ag, ad) -> snd(x) + compteur2(ag) + compteur2(ad);;

(* QUESTION II *)

(* Ensemble 1 *)

let placement1 = function (l,cpl) ->
    if l = vide
        then cons(cpl, vide)
    else
        cons(cpl, suite l);;

(* Ensemble 2 *)

let rec placement2 = function (l,cpl) ->
    if l = vide
        then cons(cpl, vide)
    else if fst(tete l) < fst(cpl)
        then placement2(suite l, cpl)
    else
        cons(cpl, suite l);;

(* Ensemble 3 *)

let rec placement3 = fun cpl V -> N(cpl, V, V)
    | cpl(N(x, ag, ad)) -> if fst(cpl) < fst(x) then N(x, (placement3 cpl ag), ad) else N(x, ag, (placement3 cpl ad));;

(* QUESTION III *)

let rec ajoute = fun e l ->
    if e = vide
    	then f
    else
    	cons(tete e, (ajoute(suite e) f));;

let rec insertion = fun l cpl ->
    if l = vide
    	then cons(cpl, vide)
    else if fst(cpl) < fst(tete l)
    	then cons(cpl, l)
    else
    	cons(tete l, insertion (suite l) cpl);;

let rec transformation = function V -> vide
    | N(cpl, ag, ad) -> (insertion cpl (ajoute(transformation ag) (transformation ad)));;

(* QUESTION IV *)


