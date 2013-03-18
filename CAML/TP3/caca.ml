(* Tremblain Rémi *)
(* 18/03/13 *)

print_endline "TP3 - Tremblain Rémi";;

(* Fonction indispensable à la réalisation de ce TP *)

type 'a liste = vide | cons of 'a * 'a liste;;

let tete = function cons(x, _) -> x | _ -> failwith "ERROR";;
  
let suite = function cons(_ ,y) -> y | _ -> failwith "ERROR";;

let rec lignes = function canal ->
          try let une_ligne = input_line canal in
                cons(une_ligne, lignes canal)
          with End_of_file -> vide;;
          
let lire = function nom ->
       let canal = open_in nom in
          let resu = lignes canal in
               close_in canal; resu;;
               
               let lire_car =function nom ->
 let canal=open_in nom in
  let rec lirea =function () ->
         try let a = input_char canal in
            cons (a ,lirea ()) with
       End_of_file -> begin close_in canal;vide end
      in lirea ();;

let is_sep = function ` `| `\n` -> true
                     | _ -> false;;

let rec saute_mot = function vide -> vide
        | cons(car,reste) as l -> if is_sep car then l
                  else saute_mot reste;;

let char2str = function car -> make_string 1 car;;

let rec premier_mot = function vide -> ""
     | cons(car,reste) -> if is_sep car then ""
                else char2str car ^ premier_mot reste;;

let rec analyselex = function vide->vide
  |cons (car,reste) as l -> if is_sep car then
            analyselex reste
    else cons(premier_mot l , analyselex (saute_mot l));;


let tout= function nom -> analyselex(lire_car nom);;

(*********************)
(** Question 1 **)
(*********************)

(* TP fini la séance précédente *)

(*********************)
(** Question 2 **)
(*********************)

tout("libe.txt");;

let rec q1 = function (x,l) -> if l = vide then cons((x,1),vide)
else if x= fst(tete(l)) then cons((x,1+snd(tete(l))),suite(l))
else if x<fst(tete(l)) then cons((x,1), l)
else cons((tete(l)), q1(x,(suite(l))));;

let rec q2 = function l -> if l = vide then vide
else q1((tete(l)), q2(suite(l)));;

let maximum= function a,b -> if (snd(a)>snd(b)) then a else b ;;



let rec maximumbis= function l -> if l=vide then failwith"ERROR"
else if suite l = vide then tete l
else maximum(tete(l),(maximumbis(suite(l))));;


let q4 = function l-> (maximumbis l);;

q4(q2(tout"libe.txt"));;


