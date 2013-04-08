(*Picard Colas --- Groupe TP5 ---- TP N°4*)
type 'a liste = vide | cons of 'a * 'a liste;;
type 'a arbre = V | N of 'a * 'a arbre * 'a arbre;;

(*déclaration de fonctions diverses pour listes et arbres*)
let tete = function cons(x, y) -> x
	| vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
	| vide -> failwith "impossible";;

let rec inserer = fun element l -> if l = vide then cons (element, vide)
	else if fst(element) < fst(tete l) then cons (element, l)
		else cons(tete l, inserer element (suite l));;

let rec inserer_arbre = fun el V -> N(el, V, V)
	|el(N(r, ag, ad)) -> if fst(el) <= fst(r) then N(r, (inserer_arbre el ag), ad)
	else N(r, ag, (inserer_arbre el ad));;

let rec ajouter = fun l1 l2 -> if l1 = vide then l2
	else cons(tete l1,(ajouter (suite l1) l2));;

(*déclaration de fonction issues du tp3 pour répondre à la question quatre*)

(*Question 1*)
(*méthode deux*)
let rec total_vendu_un = function l -> if l = vide then 0
	else snd(tete l) + total_vendu_un(suite l);;

(*méthode trois*)

let rec total_vendu_deux = function V-> 0
	|N(el, ag, ad) -> snd(el) + total_vendu_deux ag + total_vendu_deux ad;;

(*Question 2*)

(*Méthode Une*)

let ajouter_vente_un = function (x , l) -> cons(x, l);;

(*Méthode Deux*)

let ajouter_vente_deux = function (x, l) -> inserer x l;;

(*Méthode trois*)

let ajouter_vente_trois = fun x bananier-> (inserer_arbre x bananier);;

(*Question 3*)

let rec transposition = function V -> vide
	|N(el, ag, ad) -> (inserer el (ajouter (transposition ag) (transposition ad)));;

(*Question Quatre*)

let compteur_arbre = function poirier -> fst(q4(q2(transposition(poirier))));;
