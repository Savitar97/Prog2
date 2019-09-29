interface Madar{
	 
}

interface RepuloMadar {
	abstract void repul();
}
class Sas  implements RepuloMadar{
	public void repul(){
		System.out.println("A sas repül");
	}
}

class Pingvin implements Madar{

}

class Liskovjo{
	public static void main(String[] args) {
		Sas sas=new Sas();
		Pingvin pingvin=new Pingvin();
		sas.repul();
		pingvin.repul();
	}
}