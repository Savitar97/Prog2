#include <iostream>
#include <string>


class Szulo
{
	public:
	void message(){
		std::cout << "It's a message\n";
	}
};

class Pulya : public Szulo
{
	public:
	void message2(){
		std::cout << "It's a Pulya message" << "\n";
	}
};


int main(int argc, char const *argv[])
{
	Szulo* szulo = new Szulo();
	Szulo* gyerek= new Pulya();

	szulo->message();
	gyerek->message2();
	delete szulo;
	delete gyerek;
	return 0;
}
