% Карасёв Марк Иванович
% ТП1 Статистика
% Слава СССР !

% 7.1
disp("7.1 :\n");

function [moy, ect, med, q1, q3] = statdesc(x)
    moy = 0;
    ect = 0;
    med = 0;
    q1 = 0;
    q3 = 0;
    if(nargin != 1)
      usage ("statdesc (vector)");
    endif
    if(isvector(x))
	    n = length(x);
	    moy = sum(x)/n;
	    ect = sqrt(sum(power(x-moy,2))/n);
	    med = median(x);
	    j = 1;
	    for i = 1:n
		    if(x(i) < med)
			    y(j) = x(i);
			    j++;
		    endif
	    endfor
	    q1 = median(y);
	    j = 1;
	    for i = 1:n
		    if(x(i) > med)
			    y(j) = x(i);
			    j++;
		    endif
	    endfor
	    q3 = median(y);
    else
	    usage ("statdesc (vector)");
    endif
endfunction

x = [1, 2, -3.5, 6.3, -5, 0.78, -8.12]
[moy, ect, med, q1, q2] = statdesc(x)

% 7.2

disp("7.2 :\n")

