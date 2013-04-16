(*Colas PICARD ---- Groupe de TP1 ---- TP N° 5*)

(*Déclarations de la liste*)
type 'a liste =vide | cons of  'a* 'a liste;;

let tete = function cons(x, y) -> x
    | vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
    |vide -> failwith "impossible";;

(*Declaration de char2str*)

let char2str = function car -> make_string 1 car;;

(*Déclaration de fonctions de lecture de fichier *)

let lire_car =function nom ->
    let canal=open_in nom in
        let rec lirea =function  () -> 
        try let a = input_char canal in 
            cons (a ,lirea ())  with
    End_of_file -> begin close_in canal;vide end
    in  lirea ();;


(*déclaration des fonctions de traitement de la liste obtenue après lecteur*)

let is_sep = function  ` ` | `\n` -> true
    | _ -> false;;

let is_sepu = function `+` | `-` | `*` | `(` | `)` -> true
    | _  -> false;;

let rec saute_terme = function vide -> vide
    | cons(car, reste) as l -> if is_sep car or is_sepu car then l
    else saute_terme reste;;

let rec premier_terme = function vide -> ""
    |cons(car ,reste) -> if is_sep car or is_sepu car then ""
    else char2str car ^ premier_terme reste;;

let rec analyselex = function vide->vide
    |cons (car,reste) as l -> if is_sep car then
    analyselex reste
        else if is_sepu car then
            cons(char2str car, analyselex reste)
            else cons(premier_terme l , analyselex (saute_terme l));;

type terme = po|pf|op of string| entier of int;;

let ch2terme = function
    "(" -> po
    |")" -> pf
    |("+"|"-"|"*"|"/") as ope -> op ope
    |v ->entier (int_of_string v);;

let rec trans = fun f vide -> vide
    | f (cons(tete, reste)) -> cons((f tete), (trans f reste));;

let op2fun = function op "+" -> prefix +
    |op "-" -> prefix -
    |op "*" -> prefix *
    |op "/" -> prefix /
    | _ -> failwith "impossible";;

let valeur = fun (op o as ope) (entier v1) (entier v2) -> ((op2fun ope) v1 v2)
    | _ _ _ -> failwith "erreur dans la fonction valeur";;

let reduire = function cons(t2, cons (ope, cons( t1, reste))) -> cons( entier(valeur ope t1 t2), reste)
    |_ -> failwith "erreur";;


let rec calculer = fun vide (cons(entier v, vide)) -> v
    | (cons(po, reste)) pile -> calculer reste pile
    | (cons(pf, reste)) pile -> calculer reste (reduire pile)
    | (cons(t, reste)) pile -> calculer reste (cons(t, pile))
    | _ _ -> failwith "erreur dans la fonction  calculer" ;;

let calculer_ebp = function ebp -> calculer ebp vide;;

let rec saute_exp = function cons((entier v), reste) -> reste
    | cons((op ope), reste) -> saute_exp(saute_exp(reste))
	| _ -> failwith "erreur";;

let rec reduire_inv = function cons(ope, cons(t1, cons(t2, reste))) -> cons(entier (valeur ope t1 t2), reste)
	| _ -> failwith "erreur dans reduire in";;

let rec calcul_inv = fun vide (cons(entier v, vide)) -> v
	| (cons(op ope, reste)) pile -> calcul_inv reste (reduire_inv (cons (op ope, pile)))
	| (cons(e, reste)) pile -> calcul_inv reste (cons(e, pile))
	| _ _ -> failwith "erreur dans calculer expressio inverse";;


(*Question 1*)

let lecture= function nom -> (trans ch2terme (analyselex(lire_car nom)));;


calcul_inv (lecture "expinv.txt") vide;;

(**)
(*Question 2*)


(*declaration des types et fonctions pour arbres*)

type 'a arbre = V | N of 'a * 'a arbre * 'a arbre;;

let reduire_arbre = fun ope (cons(a1, cons(a2, reste))) -> cons( N( op ope, a2, a1), reste)
	| _ _ -> failwith "erreur dans reduire l arbre";;

let rec arbre_synt = fun vide (cons(a, vide)) -> a
	| (cons(op ope, reste)) pile -> arbre_synt reste (reduire_arbre ope pile)
	| (cons(e, reste)) pile -> arbre_synt reste (cons( N(e, V, V), pile))
	| _ _ -> failwith "erreur fabrication arbre";;

arbre_synt (lecture "expinv.txt") vide;;

