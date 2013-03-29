%Picard Colas ----- L2SPI ----- TP5-----
%page 63 du polycopié.

function [moyenne, ecart, mediane, Q1, Q3] = statdesc (x)
moyenne = 0;
ecart = 0;
mediane = 0;
Q1 = 0;
Q3 = 0;
if(nargin !=1)
    usage ("statdesc (vector)");
endif
if(isvector (x))
    n = length(x);
    moyenne = sum(x)/ n;
    ecart = sqrt(var(x));
    mediane = median(x);
    Q1 = median ([x(1):x(n/2)]);
    Q3 = median ([x(n/2 + 1): x(n)]);
else
    error ("statdesc : expecting vector argument");
endif
endfunction
