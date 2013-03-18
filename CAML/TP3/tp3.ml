(*---------------Colas PICARD --- Groupe TP5 ---- TP N°3-------*)

(*Déclaration des listes et autres fonctions*)
type 'a liste =vide | cons of  'a* 'a liste;;

let tete = function cons(x, y) -> x
    | vide -> failwith "impossible";;

let suite = function cons(x, y) -> y
    |vide -> failwith "impossible";;

let rec lignes = function canal ->
    try let une_ligne = input_line canal in
    cons(une_ligne, lignes canal)
    with End_of_file -> vide;;

let lire = function nom ->
    let canal = open_in nom in
        let resu = lignes canal in
    close_in canal; resu;;

let rec somme = function l ->
    if l = vide then 0
    else tete l + somme (suite l);;



let lire_car =function nom ->
    let canal=open_in nom in
        let rec lirea =function  () -> 
        try let a = input_char canal in 
            cons (a ,lirea ())  with
    End_of_file -> begin close_in canal;vide end
    in  lirea ();;

let is_sep = function ` `| `\n` -> true
| _ -> false;;


let rec saute_mot = function vide -> vide
    | cons(car,reste) as l -> if is_sep car then l
        else saute_mot reste;;

let char2str = function car -> make_string 1 car;;

let rec premier_mot = function vide -> ""
    | cons(car,reste) -> if is_sep car then ""
        else char2str car ^  premier_mot reste;;

let rec analyselex = function vide->vide
    |cons (car,reste) as l -> if is_sep car then
    analyselex reste
        else cons(premier_mot l , analyselex (saute_mot l));;


let tout= function nom -> analyselex(lire_car nom);;

let rec compte = function (nom, l) ->
    if l = vide then 0
        else if tete l = nom then 1 + compte (nom, suite l)
            else compte (nom, suite l);;

let rec compte_mot = function (l) ->
    if l = vide then failwith "Vide"
        else cons((premier_mot, compte (premier_mot, l)), compte_mot(suite l));;

let max_de_2 = function (a,b) ->
    if snd(a) > snd (b) then a
        else b;;
let rec le_maximum = fun max_de_2 (cons (tete, vide)) -> tete
    | max_de_2 (cons (tete, suite)) ->
        max_de_2 (tete, (le_maximum max_de_2 suite))
        | _ vide -> failwith "impossible";;

let rec q4 = function l -> 
   if l = vide then failwith "Zut"
     else if suite l = vide then tete l
       else le_maximum max_de_2 l;;

tout("libre.txt");;
