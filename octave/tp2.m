m = 2^31;
a = 843314861;
b = 453816693;
y = ones(101, 1);
for i = 1 : 100
    y(i +1) = mod(a * y(i) + b, m);
endfor
x = y/m;
u = x(1 : 100);
v = x(2 :101);
plot(u, v ,'*')
disp(x(1))
disp(x(101))

