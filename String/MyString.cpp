#include <iostream>
#include <algorithm>
#include <cstring>



class Osztaly{
private:
	char* buff=nullptr;
	int hossz=0;
public:
	Osztaly(const char* szoveg){
		hossz=std::strlen(szoveg);
		buff=new char[hossz+1];
		if(buff!=0)
		{	
			//OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
			std::copy(szoveg,szoveg+hossz, buff);
		}
		else
		{
			std::cout<<"Hibás"<<std::endl;
		
		}
	}
	Osztaly(const Osztaly& masolat)
        {
        	std::cout<<"Copy Ctor"<<std::endl;
              *this = masolat;
        }
     Osztaly& operator=(const Osztaly& masolat)
        {
            std::cout<<"Copy Assign"<<std::endl;
            if(this != &masolat)
            {
               
                
                delete[] buff;
                hossz = masolat.hossz;
                buff = new char[hossz+1];
                if(buff!=0)
                {
                    std::copy(masolat.buff,masolat.buff+hossz, buff);
                }
                else
                {
                    std::cout << "Hiba";
              
                }
            
            }
           
            return *this;
        }
        Osztaly(Osztaly&& masolat)
        {
        	std::cout<<"Move Ctor"<<std::endl;
            buff = nullptr;
            *this = std::move(masolat);
            
        }
        Osztaly& operator=(Osztaly&& masolat)
        {
        	std::cout<<"Move Assign"<<std::endl;
            std::swap(buff,masolat.buff);
            hossz = masolat.hossz;
            return *this;
        }

        friend std::ostream& operator<< (std::ostream& os,const Osztaly& szoveg)
        {
            os << szoveg.buff;
            return os;
        }

        char operator[](int x) const{
		
		if( x > hossz ) { std::cout << "Túlhivatkoztál!" <<std::endl; }
		return (buff[x]);
		}
		void rev() 
		{ 
		    int n = hossz; 
		  
		    
		    for (int i = 0; i < n / 2; i++) 
		        std::swap(buff[i], buff[n - i - 1]); 
		} 

        ~Osztaly()
        {
                delete[] buff;
        }


};

int main(int argc, char const *argv[])
{
	
	Osztaly szoveg = "asd";
	Osztaly szoveg2=szoveg;
	szoveg.rev();
	std::cout<<szoveg<<std::endl;
	std::cout<<szoveg2<<std::endl;
	std::cout<<szoveg[0]<<std::endl;
	return 0;
}