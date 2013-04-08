(*Colas PICARD ---- Groupe de TP1 ---- TP N° 5*)

(*Déclarations de la liste*)
type 'a liste =vide | cons of  'a* 'a liste;;

let tete = function cons(x, y) -> x
    | vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
    |vide -> failwith "impossible";;



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

let rec premier_terme = function vide -> " "
    |cons(car ,reste) -> if is_sep car or is_sepu car then " "
    else char2str car ^ premier_terme reste;;

let rec analyselex = function vide->vide
    |cons (car,reste) as l -> if is_sep car then
    analyselex reste
        else if is_sepu car then
            cons(char2str car, analyselex reste)
            else cons(premier_terme l , analyselex reste (saute_terme l);;

type terme = po|pf|op of string| entier of int;;

let ch2terme = function
    "(" -> po
    |")" -> pf
    |("+"|"-"|"*"|"/") as ope -> op ope
    |v ->entier (int_of_string v);;

let rec trans = fun f vide -> vide
    | f (cons(tete, reste)) -> cons((f tete), (trans f reste));;

let calculer_ebp = function ebp -> calculer ebp vide;;

let reduire = function cons(t2, cons (ope cons( t1, reste))) -> cons(valeur ope t1 t2, reste)
    |_ -> failwith "erreur";;

let rec calculer = fun vide (cons(entier v, vide)) -> v
    | (cons(po, reste)) pile -> calculer reste pile
    | (cons(pf, reste)) pile -> calculer reste (reduire pile)
    | (cons(t, reste)) pile -> calculer reste (cons(t, pile))
    | _ _ -> failwith "erreur dans la fonction  calculer" ;;


let valeur = fun (op o as ope) (entier v1) (entier v2) ->
    entier ((op2fun ope) v1 v2)
    | _ _ _ -> failwith "erreur dans la fonction valeur";;

let op2fun = function op "+" -> prefix +
    |op "-" -> prefix -
    |op "*" -> prefix *
    |op "/" -> prefix /
    | _ -> failwith "impossible";;

(*Question 1*)

let lecture_et_calcul_ebp = function nom -> calculer_ebp (analyselex(lire_car nom));;

lecture_et_calculer_ebp "expinv.txt";;
