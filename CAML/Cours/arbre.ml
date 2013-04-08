(*penser à déclarer les fonctions pour liste et arbres*)


let rec presence = fun x -> vide false
    |x((N(el, ag, ad)) -> x = el or presence x ag presence or presence x ad;;


(*Version pour les arbres*)
let rec recherche2 = fun x V -> raise pas-trouver
    |x (N(el, ag, ad))-> if x = el then el
    else try recherche2 x ag
        with pas_trouver -> recherche2 (x , ad);;

(*Cours : chemin de la racine à un noeud :*)

(*Version pour les arbres*)
let rec chemin = fun x V -> raise pas_trouver
    |x(N(el, ag, ad)) -> if x = el then cons(el, vide)
    else cons (el, (try chemin x ag with pas_trouver chemin x ad));;


(*Parcours : *)

(*
prefixe :
*)

let rec prefixe = function V -> vide
    |N(el, ag, ad) -> cons (el, (ajout (prefixe ag)(prefixe ad));;

let rec infixe =  function V -> vide
    |N(el, ag, ad) -> ajout(infixe (ad),cons(el, infixe(ad)));;

let rec postfixe = function V -> vide
    |N(el, ag, ad) -> ajout(postfixe(ag),ajout( postfixe(ad), cons(el, vide)));;


(*map => mise-à-plat*)

let rec map = fun V l -> l
    |(N(el, ag, ad))l -> map ag(cons(el, (map ad l)));;

let infixeBis = function a -> map a vide;;

(*Arbre binaire de recherche*)

(*recherche :*)

let recherchebis = fun x V -> raise pas_trouver
    |x(N(el, ag, ad)) -> if x = el, then el
    else if x < el then recherchebis (x ag)
        else recherchebis (x ad);;

(*insertion*)

let rec inserer = fun el V -> N(el, V, V)
    |el (N(r, ay, ad)) -> if el <=r then N(r, (inserer el ag), ad)
    else N(r, ag, (inserer el ad));;


(*Arbre n-aire de recherche *)

type 'a  arbre = V | N('a * ('a arbre) liste);;
(*ou*)
type 'a arbre = Naf('a * ('a arbre) liste);;

(*preference pour :*)
type 'a arbre = V | N af 'a * 'a arbre * arbre;;

let rec cardinal = function V -> 0
    |N(_, pf, fd) ->1 + cardinal pf + cardinal fd;;

let rec hauteur = function V -> -1
    |N(_, pf, fd) -> max (1 + hauteur pf, hauteur fd);;

let rec chemin = fun x V -> raise pas_trouver
    |x(N(el, pf, fd)) ->if x = el then cons(el, vide)
    else try (cons (el, chemin x pf) with pas_trouver chemin x fd);;


(*
32
*)

let rec profondeur = fun chaine V -> raise pas_trouver
    |N((el, num), ag, ad) -> if el = chaine then 0
    else if el >= chaine then 1 + profondeur chaine ag
        else 1 + profondeur chaine ad;;

(*
33
*)

(*
34
*)
let rec hauteur = function V -> -1
    |N(_, ag, ad) -> 1 + max(hauteur ag, hauteur ad);;


let rec listenoeud = function V -> vide
    |N(el, ag, ad) ->  ajout(listenoeud ag, (cons (el,listenoeud ad)));;

let rec listefeuille = function V -> vide
    |N(el, V, V)-> cons(el, vide)
    |N(_, ag, ad,) -> ajout (listefeuille(ag), listefeuille(ad));;
