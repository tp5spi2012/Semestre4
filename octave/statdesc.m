%Picard Colas ----- L2SPI ----- TP5-----
%page 63 du polycopié.


function [moyenne, ecart, mediane, Q1, Q3] = statdesc (x)
moyenne = 0;
ecart = 0;
mediane = 0;
Q1 = 0;
Q3 = 0;
if(nargin !=1)
   usage ("statdesc (vector)")
endif
if(isvector(x))
    n = length(x);
    moyenne = sum(x)/ n;
    ecart = sqrt(sum(x.^2 - moyenne^2)/n);
    y = sort(x);
    mediane = median(x);
    if(mod (n, 2) == 0)
        w = y(1: N/2);
        z = y(N/(2+1) :N);
    else
        w = y(1: floor(n/2));
        z = y(floor(n/2) + 2:n);
    endif
    Q1 = median (w);
    Q3 = median (z);
else
    error ("statdesc : expecting vector argument");
endif
endfunction
