(*Cours : fonction diverses*)

let is_moi = function
    "paul" -> true
    | _ -> false;;


(*let upper = function
    'a' ..'z' as minuscule ->
        char_of_int (int_of_char*)

(*
Cours de Lundi 8 avril
*)

(*Analyse syntaxique*)

(*Fonctions is_sep et is_sepu*)

let is_sep = function ' ' | '\n' -> true
    | _ -> false;;

let is_sepu = function '+' | '-' | '*' | '(' | ')' -> true
    | _  -> false;;

(*
Définition des types de termes
*)
type terme = po|pf|op of string| entier of int;;

let ch2terme = function
    "(" -> po
    |")" -> pf
    |("+"|"-"|"*"|"/") as ope -> op ope
    |v ->entier (int_of_string v);;

let rec trans = fun f vide -> vide
    | f (cons(tete, reste)) -> cons((f tete), (trans f reste));;

let calculer_ebp = function ebp -> calculer ebp vide;;

let rec calculer = fun vide (cons(entier v, vide)) -> v
    | (cons(po, reste)) pile -> calculer reste pile
    | (cons(pf, reste)) pile -> calculer reste (reduire pile)
    | (cons(t, reste)) pile -> calculer reste (cons(t, pile))
    | _ _ -> failwith "erreur calculer" ;;

let reduire = function cons(t2, cons (ope cons( t1, reste))) -> cons(valeur ope t1 t2, reste)
    |_ -> failwith "erreur";;

let valeur = fun (op o as ope) (entier v1) (entier v2) ->
    entier ((op2fun ope) v1 v2)
    | _ _ _ -> failwith "erreur";;

let op2fun = function op "+" -> prefix +
    |op "-" -> prefix -
    |op "*" -> prefix *
    |op "/" -> prefix /
    | _ -> failwith "impossible";;

let rec arbre_synt = function
    cons(entier v, reste) -> N(entier v, V, V) | cons(po, reste) -> 
        let ope = operateur (saute_ebp reste) and debd = saute_ope (saute_ebp reste) in 
            N (ope, (arbre_synt reste), (arbre_synt debg))
    | _ -> failwith "impossible -> erreur";;

(*Fonction annexes*)

let saute_pf = function cons(pf, reste) -> reste
    | _ -> failwith "erreur";;

let saute_ope = function cons(op _, reste) -> reste
    | _ -> failwith "erreur";;

let operateur = function cons(op ope as x, reste) -> x
    | _ -> failwith "erreur";;

let rec saute_ebp = function vide -> vide 
    | cons ((entier _ ), reste) -> reste
    | cons (po, reste) -> saute_pf (saute_ebp (saute_ope (saute_ebp reste)))
    | _ -> failwith ->"erreur";;





(*
Exercices
*)
(*36°*)
let rec q36 =  function V -> vide
    | N(el, V, V) -> cons( el, vide)
    | N(el, ag, ad) -> (ajoute (q36 ag) (q36 ad));;

(*37°*)

let rec q37 = fun a s-> q37aux a 0 s;;

let rec q37aux = fun V  _ _-> vide
    |(N(el, ag, ad)) d s -> let val = d + snd(el) in if val > s then vide
        else  cons(el, (ajoute (q37aux ag val s) (q37aux ad val s)));;

(*38°*)

let q38 = fun a s -> q38aux a 0 s vide;;

let rec q38aux = fun V _ _ l -> l
    |(N(el, ag, ad)) d s l -> let val d + snd(el) in if val > seuil then l
        else cons(el, (q38aux ag val s (q38aux ad val s l)));;


(*33°*)

let rec somme_noeud = fun  V _ -> 0
    |(N(el, ag, ad)) d -> let val = snd(el) + d in 
