(*---------------Colas PICARD --- Groupe TP5 ---- TP N°3-------*)


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

let rec  premier_mot = function vide -> ""
    | cons(car,reste) -> if is_sep car then ""
        else char2str car ^  premier_mot reste;;

let rec analyselex = function vide->vide
    |cons (car,reste) as l -> if is_sep car then
    analyselex reste
        else cons(premier_mot l , analyselex (saute_mot l));;


let tout= function nom -> analyselex(lire_car nom);;
