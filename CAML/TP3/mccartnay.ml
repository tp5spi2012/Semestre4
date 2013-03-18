 
(* author ==> mccartnay *)


(*Question 1*)

type 'a liste = vide | cons of 'a * 'a liste;;

let rec lignes = function canal ->
    try let une_ligne = input_line canal in
        cons(une_ligne, lignes canal)
    with End_of_file -> vide;;

let lire = function nom ->
    let canal = open_in nom in
        let resu = lignes canal in
            close_in canal; resu;;

lire "mccartnay_donnees.dat";;

(* Tête *)

let tete = function cons(x,_) -> x | _ -> failwith "impossible";;

(* Suite *)

let suite = function cons(_,g) -> g | _ -> failwith "impossible";;

(* Fonction de convertion *)

let rec trans = function l ->
    if l = vide
        then vide
    else
        cons(int_of_string(tete(l)), trans(suite(l)));;

(* Fonction somme *)

let rec somme = function l ->
    if l = vide
        then 0
    else
        tete(l) + somme(suite(l));;

somme(trans(lire "mccartnay_donnees.dat"));;


(*Question 2*)


(* Fonction créant la liste de couple *)

let rec assoc = function l ->
    if l = vide
        then vide
    else
        cons((tete(l),suite(l)), assoc(suite(suite(l))));;

assoc(lire "mccartnay_donnees2.dat");;


(* Question 3 *)


(* Fonction de recherche*)

let rec recherche = function (chaine, l) ->
    if l = vide
        then 0
    else if fst(tete(l)) = chaine
        then snd(tete(l)) + recherche(chaine,suite(l))
    else
        recherche(chaine,suite(l));;

recherche("Whesh ma gueule",assoc(lire ("donnees2.dat")));;
 
(* Question 4 *)
 
let rec dominant = function (binome, l) ->
    if l = vide
        then fst(binome)
    else if snd(binome) < snd(tete(l))
        then dominant(tete(l), suite(l))
    else
        dominant(suite(l), binome(l));;

let rec maximum = function l ->
    dominant(tete(l), l);;

maximum(dominant(tete(l), l);;

(* TP 3 *)

let frontiere = function carac ->
    if carac = ' ' | carac = '\n'
        then true
    else
        false;;

let assemblageCarac = function l ->
    if frontiere(tete(l)) = true
        then
    else
        cons(tete(l), assemblageCarac(suite(l)));;

let rec motDominant = function (mot, l) ->
    if l = vide
        then cons((mot, 1), suite(l))
    else if mot = fst(tete(l))
        then cons((mot, 1 + snd(tete l)), suite(l))
    else
        cons(tete l, motDominant(mot, (suite l)));;