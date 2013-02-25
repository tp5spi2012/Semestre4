%
%	Tremblain - Khomany
%	TP5 - Exo 2 
%

close all;
clear all;

x = wavread('S1.wav');
y = wavread('S2.wav');

%
% DSP deux signaux
%

[Freq,Sxx,Sxy,Syy]=periodogramme_moyenne_deuxvoies(x,y,1,512,6400);

%
% Réponse fréquentielle
%

h = Sxy./Sxx;

%
% Fonction de cohérance
%

coh = (abs(Sxy)).^2./(Sxx.*Syy);

%
% decalage temporel entre les deux microphones
%

subplot(3,1,1)
semilogy(Freq, Sxx, 'b', Freq, Syy ,'r')
title("Analyse des signaux U1 & U2");
xlabel("Fréquence (Hz)");
ylabel("Amplitude");

subplot(3,1,2)
plot(Freq, abs(h), 'g')
title("Réponse fréquentielle");
xlabel("Frequence (Hz)");
ylabel("Amplitude");

subplot(3,1,3)
plot(Freq, coh, 'm')
title("Fonction de cohérance");
xlabel("Frequence (Hz)");
ylabel("Amplitude");


