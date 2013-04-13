p = 0.3;
N = 1000;
%x = zeros(N, 1);
%for i = 1 :N
  %  if(rand >= i(1 - p))
  %      x(i) = 1;
  %  endif
%endfor
%hist(x, 2, 1)

%% Binomiale

p = 0.5;
n = 12;
S = zeros(N, 1);
for k = 1 :N
    x = zeros(n, 1);
    for i = 1 : n
        if rand >= 1 -p
            x(i) = 1;
        endif
    endfor
    S(k) = sum(x);
endfor
hist(S, 13, 1)
