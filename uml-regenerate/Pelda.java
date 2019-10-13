interface Motor{
 public void uzemanyag();
}

class Jarmu implements Motor{
	public void fek(){

	};
	public void gaz()
	{

	};
	@Override
	public void uzemanyag(){};

}

class Szemelyauto extends Jarmu{
@Override
public void fek(){};
@Override
public void gaz(){};

}

class Teherauto extends Jarmu{
	@Override
	public void fek(){};
	@Override
	public void gaz(){};
}

class Pelda{

	public static void main(String[] args) {
	Jarmu jarmu=new Jarmu();
	Szemelyauto auto=new Szemelyauto();
	Teherauto tauto=new Teherauto();
	jarmu=new Szemelyauto();
	jarmu=new Teherauto();

	}
}