(*Picard Colas --- Groupe TP5 ---- TP N°4*)
type 'a liste = vide | cons of 'a * 'a liste;;
type 'a arbre = V | N of 'a * 'a arbre * 'a arbre;;

let tete = function cons(x, y) -> x
	| vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
	| vide -> failwith "impossible";;

let rec inserer = fun element l -> if l = vide then cons (element, vide)
	else if element < tete l then cons (element, l)
		else cons(tete l, inserer element (suite l));;

(*Question 1*)
(*méthode deux*)
let rec total_vendu_un = function l -> if l = vide then 0
	else fst(tete l) + total_vendu_un(suite l);;

(*méthode trois*)

let rec total_vendu_deux = function V-> 0
	|N(el, ag, ad) -> fst(el) + total_vendu_deux ag + total_vendu_deux ad;;

(*Question 2*)

(*Méthode Une*)

let ajouter_vente_un = function (x , l) -> cons(x, l);;

(*Méthode Deux*)

let ajouter_vente_deux = function (x, l) -> inserer x l;;
