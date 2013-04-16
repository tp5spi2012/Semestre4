	(* Karassev Marc *)

	type 'a liste = vide | cons of 'a * 'a liste;;

	type 'a arbre = V | N of 'a*'a arbre*'a arbre;;

	type terme = po|pf|op of string|entier of int;;

	let lire_car =function nom ->
	 let canal=open_in nom in
		let rec lirea =function  () -> 
		       try let a = input_char canal in 
		          cons (a ,lirea ())  with
		     End_of_file -> begin close_in canal;vide end
		    in    lirea ();;

	let is_sep = function ` `| `\n` -> true
		                   | _ -> false;;
		                   
	let is_sepu = function `+`|`-`|`/`|`*` -> true
		| _ -> false;;

	let rec saute_terme = function vide -> vide
		      | cons(car,reste) as l -> if is_sep car or is_sepu car then l
		                else saute_terme reste;;

	let char2str = function car -> make_string 1 car;;

	let char2terme = function ("+"|"-"|"/"|"*") as ope -> op ope
		| v -> entier (int_of_string v);;
	
	let rec trans = fun f vide -> vide
		| f (cons(tete,reste)) -> cons((f tete),(trans f reste));;

	let rec  premier_terme = function vide -> ""
		   | cons(car,reste) -> if is_sep car or is_sepu car then ""
		              else char2str car ^  premier_terme reste;;
		  
	let rec analyselex = function vide -> vide
		| cons(car,reste) as l -> if is_sep car then analyselex reste
		else if is_sepu car then cons(char2str car,analyselex reste)
		else cons(premier_terme l,analyselex (saute_terme l));;

	let op2fun = function
			op "+" -> prefix +
		| op "-" -> prefix -
		| op "*" -> prefix *
		| op "/" -> prefix /
		| _ -> failwith "impossible op2fun";;

	let valeur = fun (op o as ope) (entier v1) (entier v2) ->
		entier ((op2fun ope) v1 v2)
		| _ _ _ -> failwith "erreur valeur";;

	let reduire = function cons(ope,cons(t1,cons(t2,reste))) -> 
		cons(valeur ope t1 t2,reste)
		| _ -> failwith "erreur reduire";;

	let rec calculer = fun vide (cons(entier v,vide)) ->  v 
		| (cons(op ope,reste)) pile -> calculer reste (reduire (cons(op ope,pile)))
		| (cons(t,reste)) pile -> calculer reste (cons(t,pile))
		| _ _ -> failwith "erreur calculer";;
	
	(* Q1 *) calculer (trans char2terme (analyselex(lire_car "expinv.txt"))) vide;;

	let reduire_arbre = function
		  ((op ope), cons(a1, cons(a2, reste))) -> cons(N(op ope, a2, a1), reste)
		| _ -> failwith "erreur reduire_arbre";;
	
	let rec arbre_synt = fun
		  vide (cons(tete, vide)) -> tete 
		| (cons(entier v, reste)) pile -> arbre_synt reste (cons(N(entier v, V, V), pile))
		| (cons(op ope, reste)) pile -> arbre_synt reste (reduire_arbre(op ope, pile))
		| _ _ -> failwith "erreur arbre_synt";;

	(* Q2 *) arbre_synt (trans char2terme (analyselex(lire_car "expinv.txt"))) vide;;
		 
	(* let rec pair = function n ->
		if n > 0 then impair (n-1)
		else if n < 0 then impair (n+1)
		else 1
		and impair = function n -> 
			if n > 0 then pair (n-1)
			else if n < 0 then pair (n+1)
			else 0;; *)

