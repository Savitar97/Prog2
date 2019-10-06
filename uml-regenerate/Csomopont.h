#ifndef CSOMOPONT_H
#define CSOMOPONT_H

class Csomopont {

private:
	char betu;
	Csomopont* balNulla;
	Csomopont* jobbEgy;

public:
	Csomopont(char b = '/');

	void ~Csomopont();

	Csomopont(const Csomopont& elem);

	Csomopont* nullasGyermek();

	Csomopont* egyesGyermek();

	void ujNullasGyermek(Csomopont* gy);

	void ujEgyesGyermek(Csomopont* gy);

	char getBetu();
};

#endif
