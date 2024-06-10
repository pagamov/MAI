% import db.pl before work

dBrat(X, Y):-
    children(X, Rod),
    children(Rod, RodD),
    children(T, RodD),
    T \= Rod,
    children(Y, T),
    male(Y).

% Марк Александрович Гамов
% Павел Антонович Гамов
% dBrat("Марк Александрович Гамов", "Павел Антонович Гамов").
