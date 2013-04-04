(*      TP4                     *)


(********************************)
(*      DECLARATIONS            *)
(********************************)
(* liste *)
type 'a liste = vide | cons of 'a * 'a liste;;
(* arbre binaire*)
type 'a arbreB = V | N of 'a*'a arbreB*'a arbreB;;

(* fonctions utiles *)
let tete = function (x,_) -> x;;
let suite = function (_,x) -> x;;
let rec conc = fun vide vide -> vide |
                        vide l2 -> l2 |
                        (cons(valeur, suivant)) l2 -> cons(valeur, conc (suivant) l2);;

(* structures de test *)
let test_l = cons(("carte pokemon", 23), cons(("abris bus", 42), 
cons(("brebis gonflable", 4), vide)));;
let test_lT = cons(("abris bus", 42), cons(("carte pokemon", 23), 
cons(("brebis gonflable", 4), vide)));;
let test_a = N(("carte pokemon",23), 
                N(("abris bus", 42),V,V), 
                N(("brebis gonflable", 4), V, V));;





(********************************)
(*      QUESTION 1              *)
(********************************)
let rec liste_totalVentes = function vide -> 0 |
                                cons((_, qtt), suivant) -> 
                                        qtt + (liste_totalVentes suivant);;

let rec arbreB_totalVentes = function V -> 0 |
                                N((_, qtt), fg, fd) ->
                                       qtt + (arbreB_totalVentes fd) +
                                       (arbreB_totalVentes fg);;


liste_totalVentes test_l;;
liste_totalVentes test_lT;;
arbreB_totalVentes test_a;;




(********************************)
(*      QUESTION 2              *)
(********************************)
let rec liste_ajouterVente = fun vente vide -> cons(vente, vide) |
                                vente (cons((obj, qtt), suivant)) -> 
                                        cons((obj, qtt), 
                                        (liste_ajouterVente vente suivant));;
let rec listeT_ajouterVente = fun vente vide -> cons(vente, vide) |
                                vente (cons((obj, qtt), suivant)) ->
                                        if obj > (tete vente) 
                                        then 
                                                cons(vente, cons((obj, qtt), suivant)) 
                                        else    
                                                cons((obj, qtt), 
                                                listeT_ajouterVente vente suivant) ;;


let rec arbre_ajouterVente = fun vente V -> N(vente, V, V) |
                                vente ( N((obj, qtt), fg, fd) ) ->
                                        if ( obj > (tete vente) ) 
                                        then
                                                N( (obj, qtt),
                                                arbre_ajouterVente vente fg, fd)
                                        else
                                                N( (obj, qtt),
                                                fg, arbre_ajouterVente vente fd);;



liste_ajouterVente ("mongolfiere", 64) test_l;;
let test_lT = listeT_ajouterVente ("mongolfiere", 64) test_lT;;
let test_lT = listeT_ajouterVente ("disque en or veritable", 3) test_lT;;
let test_a = arbre_ajouterVente ("mongolfiere", 64) test_a;;
let test_a = arbre_ajouterVente ("disque en or veritable", 3) test_a;;




(********************************)
(*      QUESTION 3              *)
(********************************)
let rec arbre2listeT = function V -> vide | 
                                ( N(vente, fg, fd) ) -> 
                                        conc (arbre2listeT fg) (cons(vente, 
                                        arbre2listeT fd));;

arbre2listeT test_a;;



(********************************)
(*      QUESTION 4              *)
(********************************)
(* retourne la vente la plus conséquente *)
let max = function ((obj1,qtt1),(obj2,qtt2)) -> if qtt1 > qtt2 
                                then 
                                        (obj1, qtt1)
                                else
                                        (obj2, qtt2);;

let rec maxVentes_rec = fun ventemax V -> ventemax |
                                ventemax ( N(vente,fg,fd) ) ->
                                        max(vente, max(
                                                (maxVentes_rec ventemax fg),
                                                (maxVentes_rec ventemax fd))
                                        );;
let maxVentes = function a -> maxVentes_rec ("Aucun objet vendu", -1) a;;


maxVentes test_a;;





