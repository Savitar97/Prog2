férfi(attila).
férfi(elek).
férfi(nElek).
férfi(barnabas).
nő(edit).
nő(ildikó).
nő(piroska).
nő(jolán).
gyereke(attila, elek).
gyereke(edit, elek).
gyereke(attila, ildikó).
gyereke(edit, ildikó).
gyereke(elek, nElek).
gyereke(elek, piroska).
gyereke(ildikó, barnabas).
gyereke(ildikó, jolán).
apa(X) :- férfi(X), gyereke(_Y, X).
apja(X, Y) :- férfi(X), gyereke(Y, X).
anya(X) :- nő(X), gyereke(_Y, X).
anyja(X, Y) :- nő(X), gyereke(Y, X).
nagyapa(X) :- apja(X, Y), (apja(Y, _U); anyja(Y, _Z)).
nagyapja(X, Z) :- apja(X, Y), (apja(Y, Z); anyja(Y, Z)).
