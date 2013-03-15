(* HUBA THOMAS - TP2 CAML - Programmation Fonctionnelle
   Licence SPI - Semestre 4 *)

(* PREDEF DATA *)

type 'a liste = vide | cons of  'a* 'a liste;;

let rec lignes = function canal ->
	try let une_ligne = input_line canal in
	cons(une_ligne, lignes canal)
	with End_of_file -> vide;;

let lire = function nom ->
	let canal = open_in nom in
		let resu = lignes canal in
		close_in canal; resu;;
lire "donnees.dat";;

(* TETE *)

let tete = function cons(x,_) -> x;;

(* SUITE *)

let suite = function cons(x,y) -> y;
	| vide -> failwith "Impossible";;

(* Question 1 : Lire un fichier et faire la somme des entiers qui le composent *)

let convert = function l -> 
	if l = vide then 0 else
	cons(int_of_string(tete(l)),int_of_string(suite(l));;

let rec somme = function l -> 
	if l = vide then 0 else
	(tete(l)) + somme(suite(l));;

somme(convert(lire "donnees.dat"));;

(* Question 2 : transformer une liste contenant des entiers et des strings, et retourner une liste de couple (string, int) *)

let rec couple = function l -> 
	if l = vide then vide else
	cons((tete(l),int_of_string(tete(suite(l))),couple(suite(suite(l)))));;

couple(lire "ploup.dat");;

(* Question 3 : Ecrire une fonction rechercher/sommme qui fait la somme des snd corespondant à un fst bien définit *)

let rec recherche = function (l,mot) -> 
	if l = vide then 0 else
	if fst(tete(l))=mot then snd(tete(l)) + recherche(suite(l),mot)
	else recherche(suite(l),mot);;

recherche(couple(lire "q3.txt"), Thomas);;

(* Question 4 : 

