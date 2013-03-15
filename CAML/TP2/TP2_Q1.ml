(* Tremblain Rémi *)

print_endline "TP2 - Tremblain Rémi";;

(* Fonction indispensable à la réalisation de ce TP *)

type  'a liste = vide | cons of  'a * 'a liste;;

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

(*********************)
(**    Question 1    **)
(*********************)
(* Additionne toutes les valeurs présentent dans le fichier "donnees_1.dat" *)
               
let rec int_of_string_liste = function l -> if l = vide then vide else cons(int_of_string(tete(l)), int_of_string_liste(suite(l)));;

let rec som = function l -> if l=vide then 0 else
	(tete(l) + som(suite(l)));;
	
som (int_of_string_liste(lire "donnees_1.dat"));;

(*********************)
(**    Question 2    **)
(*********************)
(* Retourne la liste des noms associés aux valeurs *)
          
let rec couple = function l -> if l = vide then vide 
	else if suite l = vide then failwith "ERROR" 
	else cons((tete l,int_of_string(tete(suite l))), couple(suite(suite(l))));;

couple (lire "donnees_2.dat");; 

(*********************)
(**    Question 3    **)
(*********************)
(* Recherche et additionne les valeurs associées au nom entré en paramètre *)	

let rec recherche = function (l,nom) -> if l = vide then 0 
	else if fst(tete(l)) = nom then snd(tete(l)) + recherche(suite(l),nom)
	else recherche(suite(l),nom);;

recherche (couple(lire "donnees_2.dat"), "Thomas");; 
(* remplacer "Thomas" par le nom souhaité *)	
		
(*********************)
(**    Question 4    **)
(*********************)
(* Renvoie le nom associé au plus grand nombre *)
	
let rec max_bis = function (l, couple) -> if l = vide then fst(couple) 
	else if snd(tete (l)) > snd(couple) then max_bis(suite(l), tete(l)) 
	else max_bis(suite(l), couple);;

let rec max = function l -> max_bis(l,tete(l));;

max(couple(lire "donnees_2.dat"));;
