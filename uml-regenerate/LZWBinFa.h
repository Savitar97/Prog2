#ifndef LZWBINFA_H
#define LZWBINFA_H

class LZWBinFa {

private:
	Csomopont* fa;
	int melyseg;
	int atlagosszeg;
	int atlagdb;
	double szorasosszeg;
protected:
	Csomopont* gyoker;
	int maxMelyseg;
	double atlag;
	double szoras;

public:
	LZWBinFa();

	void ~LZWBinFa();

	LZWBinFa(LZWBinFa&& regi);

	void kiir();

	int getMelyseg();

	double getAtlag();

	double getSzoras();

	void kiir(std::ostream& os);

private:
	LZWBinFa(const LZWBinFa& binfa);

	void kiir(Csomopont* elem, std::ostream& os);

	void szabadit(Csomopont* elem);

protected:
	void rmelyseg(Csomopont* elem);

	void ratlag(Csomopont* elem);

	void rszoras(Csomopont* elem);
};

#endif
