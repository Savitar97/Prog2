class Szulo{
	void message(){
		System.out.println("Szülő üzenete.");
	}
}

class Pulya extends Szulo{
	@Override
	void message(){
		System.out.println("Szülő üzenet felülír");
	}
	void message2(){
		System.out.println("Gyerek üzenete");
	}
}

class Szulogyerek{
	public static void main(String[] args) {
		Szulo szulo = new Szulo();
		szulo.message();
		szulo=new Pulya();
		szulo.message();
		//Itt látható, hogy a szülő nem tudja meghívni a gyerek metódusát.Tehát az ősön keresztül, csak az ős üzenetei küldhetők.
		szulo.message2();
		Pulya gyerek=new Pulya();
		gyerek.message();
		gyerek.message2();

	}
}