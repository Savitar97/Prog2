//gcc pointer2.cpp -o binarytree -lm -lstdc++
#include <iostream>		
#include <cmath>		
#include <fstream>	
#include <algorithm>
#include <utility>

class LZWBinFa
{
public:
  
  LZWBinFa()
  {
      gyoker = new Csomopont();
      fa=gyoker;
  }
   ~LZWBinFa ()
  {
    szabadit (gyoker->egyesGyermek ());
    szabadit (gyoker->nullasGyermek ());
    delete gyoker;
  }
  
  LZWBinFa ( const LZWBinFa & regi ) {
    std::cout << "LZWBinFa copy ctor called" << std::endl;
    gyoker = masol(regi.gyoker, regi.fa);
  }

  LZWBinFa (LZWBinFa && regi ){
      std::cout<<"LZWBinFa move ctor called"<<std::endl;
      gyoker = nullptr;
      
      *this = std::move(regi);

      
  }
  
 LZWBinFa& operator= ( const LZWBinFa & regi ) 
    {
        std::cout << "LZWBinFa copy assignment" << std::endl;

        gyoker->balNulla =  masol ( regi.gyoker->balNulla, regi.fa ) ;
        gyoker->jobbEgy =  masol ( regi.gyoker->jobbEgy, regi.fa ) ;

        if ( regi.fa ==  regi.gyoker)
            fa = gyoker;
          return *this;

    }

  LZWBinFa & operator= (LZWBinFa && regi){
      
      std::swap(gyoker, regi.gyoker);
      std::cout << "LZWBinFa move assignment" << std::endl;
      return *this;
}

  void operator<< (char b)
  {

    if (b == '0')
      {
	
	if (!fa->nullasGyermek ())	
	  {
	    Csomopont *uj = new Csomopont ('0');
	    fa->ujNullasGyermek (uj);
	    fa = gyoker;
	  }
	else			
	  {
	    
	    fa = fa->nullasGyermek ();
	  }
      }
    else
      {
	if (!fa->egyesGyermek ())
	  {
	    Csomopont *uj = new Csomopont ('1');
	    fa->ujEgyesGyermek (uj);
	    fa = gyoker;
	  }
	else
	  {
	    fa = fa->egyesGyermek ();
	  }
      }
  }
  
  void kiir (void)
  {
    
    melyseg = 0;
    kiir (gyoker, std::cout);
  }
  
  int getMelyseg (void);
  double getAtlag (void);
  double getSzoras (void);

  friend std::ostream & operator<< (std::ostream & os, LZWBinFa & bf)
  {
    bf.kiir (os);
    return os;
  }
  void kiir (std::ostream & os)
  {
    melyseg = 0;
    kiir (gyoker, os);
  }

private:
  class Csomopont
  {
  public:

  Csomopont (char b = '/'):betu (b), balNulla (0), jobbEgy (0)
    {
    };
    Csomopont *balNulla;
    Csomopont *jobbEgy;
    ~Csomopont ()
    {
    };
    Csomopont (const Csomopont& elem){
        
        betu = elem.getBetu();
        balNulla = new Csomopont;
        jobbEgy = new Csomopont;
        *balNulla= *(elem.nullasGyermek());
        *jobbEgy= *(elem.egyesGyermek());
    }
    
    Csomopont & operator= (const Csomopont& elem){
        
        betu = elem.getBetu();
        Csomopont* ujBal = new Csomopont();
        *ujBal = *(elem.nullasGyermek());
        delete balNulla;
        balNulla = ujBal;
        Csomopont* ujJobb = new Csomopont();
        *ujJobb = *(elem.egyesGyermek());
        delete jobbEgy;
        jobbEgy = ujJobb;
        
        return *this;
    }
   
    Csomopont *nullasGyermek () const
    {
      return balNulla;
    }
    
    Csomopont *egyesGyermek () const
    {
      return jobbEgy;
    }
  
    void ujNullasGyermek (Csomopont * gy)
    {
      balNulla = gy;
    }
    
    void ujEgyesGyermek (Csomopont * gy)
    {
      jobbEgy = gy;
    }
   
    char getBetu () const
    {
      return betu;
    }

  private:
   
    char betu;
    
    
  };

  Csomopont *fa;
  int melyseg, atlagosszeg, atlagdb;
  double szorasosszeg;

  void kiir (Csomopont * elem, std::ostream & os)
  {
    
    if (elem != NULL)
      {
	++melyseg;
	kiir (elem->nullasGyermek (), os);
	for (int i = 0; i < melyseg; ++i)
	  os << "---";
	os << elem->getBetu () << "(" << melyseg - 1 << ")" << std::endl;
	kiir (elem->egyesGyermek (), os);
	--melyseg;
      }
  }
  void szabadit (Csomopont * elem)
  {
    if (elem != NULL)
      {
	szabadit (elem->egyesGyermek ());
	szabadit (elem->nullasGyermek ());
	delete elem;
      }
  }

  Csomopont *  masol ( Csomopont * elem, Csomopont * regifa ) {

    Csomopont * ujelem = NULL;
    if ( elem != NULL ) {
      ujelem = new Csomopont ( elem->getBetu() );

      ujelem->ujEgyesGyermek ( masol ( elem->egyesGyermek (), regifa ) );
      ujelem->ujNullasGyermek ( masol ( elem->nullasGyermek (), regifa ) );

      if ( regifa == elem )
        fa = ujelem;

    }
    return ujelem;
  }


protected:			
  Csomopont *gyoker;
  int maxMelyseg;
  double atlag, szoras;

  void rmelyseg (Csomopont * elem);
  void ratlag (Csomopont * elem);
  void rszoras (Csomopont * elem);

};

int
LZWBinFa::getMelyseg (void)
{
  melyseg = maxMelyseg = 0;
  rmelyseg (gyoker);
  return maxMelyseg - 1;
}

double
LZWBinFa::getAtlag (void)
{
  melyseg = atlagosszeg = atlagdb = 0;
  ratlag (gyoker);
  atlag = ((double) atlagosszeg) / atlagdb;
  return atlag;
}

double
LZWBinFa::getSzoras (void)
{
  atlag = getAtlag ();
  szorasosszeg = 0.0;
  melyseg = atlagdb = 0;

  rszoras (gyoker);

  if (atlagdb - 1 > 0)
    szoras = std::sqrt (szorasosszeg / (atlagdb - 1));
  else
    szoras = std::sqrt (szorasosszeg);

  return szoras;
}

void
LZWBinFa::rmelyseg (Csomopont * elem)
{
  if (elem != NULL)
    {
      ++melyseg;
      if (melyseg > maxMelyseg)
	maxMelyseg = melyseg;
      rmelyseg (elem->egyesGyermek ());
      rmelyseg (elem->nullasGyermek ());
      --melyseg;
    }
}

void
LZWBinFa::ratlag (Csomopont * elem)
{
  if (elem != NULL)
    {
      ++melyseg;
      ratlag (elem->egyesGyermek ());
      ratlag (elem->nullasGyermek ());
      --melyseg;
      if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
	{
	  ++atlagdb;
	  atlagosszeg += melyseg;
	}
    }
}

void
LZWBinFa::rszoras (Csomopont * elem)
{
  if (elem != NULL)
    {
      ++melyseg;
      rszoras (elem->egyesGyermek ());
      rszoras (elem->nullasGyermek ());
      --melyseg;
      if (elem->egyesGyermek () == NULL && elem->nullasGyermek () == NULL)
	{
	  ++atlagdb;
	  szorasosszeg += ((melyseg - atlag) * (melyseg - atlag));
	}
    }
}


void
usage (void)
{
  std::cout << "Usage: lzwtree in_file -o out_file" << std::endl;
}

int
main (int argc, char *argv[])
{

  if (argc != 4)
    {
      usage ();
      return -1;
    }

  char *inFile = *++argv;

  if (*((*++argv) + 1) != 'o')
    {
      usage ();
      return -2;
    }

  std::fstream beFile (inFile, std::ios_base::in);

  if (!beFile)
    {
      std::cout << inFile << " nem letezik..." << std::endl;
      usage ();
      return -3;
    }

  std::fstream kiFile (*++argv, std::ios_base::out);

  unsigned char b;		
  LZWBinFa binFa,binFa2,binFa4;		


  while (beFile.read ((char *) &b, sizeof (unsigned char)))
    if (b == 0x0a)
      break;

  bool kommentben = false;

  while (beFile.read ((char *) &b, sizeof (unsigned char)))
    {

      if (b == 0x3e)
	{			// > karakter
	  kommentben = true;
	  continue;
	}

      if (b == 0x0a)
	{			// újsor 
	  kommentben = false;
	  continue;
	}

      if (kommentben)
	continue;

      if (b == 0x4e)		// N betű
	continue;

      for (int i = 0; i < 8; ++i)
	{
	  if (b & 0x80)
	    binFa << '1';
	  else
	    binFa << '0';
	  b <<= 1;
	}

    }


  kiFile << binFa;
  kiFile << "depth = " << binFa.getMelyseg () << std::endl;
  kiFile << "mean = " << binFa.getAtlag () << std::endl;
  kiFile << "var = " << binFa.getSzoras () << std::endl;
  kiFile << &binFa;
  std::cout << &binFa<<std::endl;
  LZWBinFa binFa3(binFa);
  std::cout<<binFa3<<std::endl;
  binFa2=std::move(binFa);
  binFa4=binFa3;
  std::cout << &binFa3<<std::endl;
  std::cout << &binFa4<<std::endl;
  
  kiFile<<"\n Mozgatás után binFa:"<< std::endl;
  std::cout<<"\n Mozgatás után binFa:"<< std::endl;
  std::cout << &binFa<<std::endl;
  std::cout<<binFa<<std::endl;
  kiFile << binFa;
  kiFile << "depth = " << binFa.getMelyseg () << std::endl;
  kiFile << "mean = " << binFa.getAtlag () << std::endl;
  kiFile << "var = " << binFa.getSzoras () << std::endl;
  kiFile  << "\nMozgatás után a binFa2"<< std::endl;
  kiFile<<binFa2;
  std::cout<<"\n Mozgatás után binFa2:"<< std::endl;
  std::cout << &binFa2<<std::endl;
  std::cout<<binFa2;
  kiFile << "depth = " << binFa2.getMelyseg () << std::endl;
  kiFile << "mean = " << binFa2.getAtlag () << std::endl;
  kiFile << "var = " << binFa2.getSzoras () << std::endl;
  kiFile<<"\n Másolás után binFa3:"<< std::endl;
  kiFile << binFa3;
  kiFile << "depth = " << binFa3.getMelyseg () << std::endl;
  kiFile << "mean = " << binFa3.getAtlag () << std::endl;
  kiFile << "var = " << binFa3.getSzoras () << std::endl;
  kiFile.close ();
  beFile.close ();

  return 0;
}
