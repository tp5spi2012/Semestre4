(* Tremblain Rémi *)

print_endline "TP2 - Tremblain Rémi";;

type  'a liste = vide | cons of  'a * 'a liste;;

let tete = function cons(x, _) -> x | _ -> failwith "ERROR";;
  
let suite = function cons(_ ,y) -> y | _ -> failwith "ERROR";;

(*********************)
(**    Question 1    **)
(*********************)

let rec lignes = function canal ->
          try let une_ligne = input_line canal in
                cons(une_ligne, lignes canal)
          with End_of_file -> vide;;
          
let lire = function nom ->
       let canal = open_in nom in
          let resu = lignes canal in
               close_in canal; resu;;
               
let rec int_of_string_liste = function l -> if l = vide then vide else cons(int_of_string(tete(l)), int_of_string_liste(suite(l)));;

let rec som = function l -> if l=vide then 0 else
	(tete(l) + som(suite(l)));;
	
som (int_of_string_liste(lire "donnees_1.dat"));;


(*********************)
(**    Question 2    **)
(*********************)
          
let rec couple = function l -> if l = vide then vide 
	else if suite l = vide then failwith "ERROR" 
	else cons((tete l,int_of_string(tete(suite l))), couple(suite(suite(l))));;

couple (lire "donnees_2.dat");; 

(*********************)
(**    Question 3    **)
(*********************)	

let rec recherche = function (l,nom) -> if l = vide then 0 
	else if fst(tete(l)) = nom then snd(tete(l)) + recherche(suite(l),nom)
	else recherche(suite(l),nom);;

recherche (couple(lire "donnees_2.dat"), "Thomas");; 
(* remplacer "Thomas" par le nom souhaité *)	
