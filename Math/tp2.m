clear all;
close all;
m = 101;
N = 100;
%m = 2^31;
%a = 843314861;
% a = 12
%b = 453816693;
% b = 0;
%y = ones(N, 1);
%for i = 1 : N-1
%    y(i +1) = mod(a * y(i) + b, m);
%endfor
%x = y/m;  
%u = x(1 : 100);
%v = x(2 :101);
%plot(u, v ,'*')
%disp(x(1))
%disp(x(101))
%r =x(1 : N-2, 1);
%s = x (2 :N-1, 1);
%t = x(3 : N, 1);
%scatter3(r, s, t)
x = rand(N, 1);
u = x(1 : N-1);
v = x(2 :N);
plot(u, v, '*')
