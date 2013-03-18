(*
TP n°2 CAML
    -------- 
Colas PICARD
*)


(*Question 1*)

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

let rec int_of_string_liste = function l -> 
    if  l = vide then vide
    else cons(int_of_string (tete l), int_of_string_liste (suite l));;

somme(int_of_string_liste(lire "donnees.dat"));;


(*
-----
Question 2
----
*)


let rec trans2 = function l ->
    if l = vide then vide
        else if suite l = vide then failwith "Zut!"
        else cons((tete l, int_of_string(tete(suite l))), trans2(suite (suite l)));;

trans2 (lire "truc.dat");;


(*
----
Question 3
----
*)

let rec sommeliste = function (nom, l)->
    if l = vide then 0
        else if fst(tete l) = nom then snd(tete l) + sommeliste(nom, suite l)
            else sommeliste(nom, suite l);;

sommeliste("pla", trans2(lire "truc.dat"));;


(*
------
Question 4
-----
*)

let max_de_2 = function (a,b) ->
    if snd(a) > snd (b) then a
        else b;;
let rec le_maximum = fun max_de_2 (cons (tete, vide)) -> tete
    | max_de_2 (cons (tete, suite)) ->
        max_de_2 (tete, (le_maximum max_de_2 suite))
        | _ vide -> failwith "impossible";;

let rec q4 = function l ->
    if l = vide failwith "Zut^^"
        else if suite l = vide then tete l
            else le_maximum max_de_2 l;;

q4(trans2(lire "truc.dat"));;
