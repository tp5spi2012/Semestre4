%
%	Tremblain - Khomany
%	TP5 
%

close all;
clear all;

x = wavread('U1.wav');
y = wavread('U2.wav');

%
% DSP deux signaux
%

[Freq,Sxx,Sxy,Syy]=periodogramme_moyenne_deuxvoies(x,y,1,512,12800);

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
xlabel("Frequence (Hz)");
ylabel("Amplitude (je sais pas)");

subplot(3,1,2)
plot(Freq, abs(h), 'g')
title("Réponse fréquentielle");
xlabel("Frequence (Hz)");
ylabel("Amplitude (je sais pas)");

subplot(3,1,3)
plot(Freq, coh, 'm')
title("Fonction de cohérance");
xlabel("Frequence (Hz)");
ylabel("Amplitude (je sais pas)");


