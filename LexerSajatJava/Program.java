import java.io.*;
import java.util.*;


class Lexer{
	private String text;
	public Lexer()
	{
		
	}
 
	public static Map<String, String[]> lexer = new HashMap<String, String[]>();



	public String Lextext(String text){
		this.text=text.toLowerCase();
		Random rand = new Random();
		for (Map.Entry<String, String[]> peldany : lexer.entrySet()) {

			int random = rand.nextInt(4);
            String kulcs = peldany.getKey();
            String[] ertek = peldany.getValue();
            text= text.replace(kulcs, ertek[random]);
		}
		return text;
		
	}
	
	
}


class Program{
public static void main(String[] args) {
		Lexer lex=new Lexer();
		lex.lexer.put("a",new String[] {"α", "4", "@", "/-\\"});
		lex.lexer.put("b",new String[] {"ß", "8", "|3", "|}"});
		lex.lexer.put("c",new String[] {"©", "€", "¢", "{"});
		lex.lexer.put("d",new String[] {"d", "|)", "|]", "|}"});
		lex.lexer.put("e",new String[] {"Σ", "Œ", "3", "3"});
		lex.lexer.put("f",new String[] {"╒", "|=", "£", "|#"});
		lex.lexer.put("g",new String[] {"g", "6", "[", "[+"});
		lex.lexer.put("h",new String[] {"♓", "4", "|-|", "[-]"});
		lex.lexer.put("i",new String[] {"1", "1", "|", "!"});
		lex.lexer.put("j",new String[] {"⌡", "7", "_|", "_/"});
		lex.lexer.put("k",new String[] {"k", "|<", "1<", "|{"});
		lex.lexer.put("l",new String[] {"l", "1", "|", "|_"});
		lex.lexer.put("m",new String[] {"m", "44", "(V)", "|\\/|"});
		lex.lexer.put("n",new String[] {"π", "|\\|", "/\\/", "/V"});
		lex.lexer.put("o",new String[] {"σ", "0", "()", "[]"});
		lex.lexer.put("p",new String[] {"p", "/o", "|D", "|o"});
		lex.lexer.put("q",new String[] {"q", "9", "O_", "(,)"});
		lex.lexer.put("r",new String[] {"®", "Γ", "12", "|2"});
		lex.lexer.put("s",new String[] {"s", "5", "$", "$"});
		lex.lexer.put("t",new String[] {"†", "╤", "τ", "'|'"});
		lex.lexer.put("u",new String[] {"µ", "|_|", "(_)", "[_]"});
		lex.lexer.put("v",new String[] {"v", "\\/", "\\/", "\\/"});
		lex.lexer.put("w",new String[] {"w", "VV", "\\/\\/", "(/\\)"});
		lex.lexer.put("x",new String[] {"x", "%", ")(", ")("});
		lex.lexer.put("y",new String[] {"y", "¥", "y", "y"});
		lex.lexer.put("z",new String[] {"z", "2", "7_", ">_"});
		lex.lexer.put("0",new String[] {"Ω", "○", "º", "☺"});
		lex.lexer.put("1",new String[] {"I", "I", "L", "L"});
		lex.lexer.put("2",new String[] {"Z", "Z", "Z", "e"});
		lex.lexer.put("3",new String[] {"E", "E", "E", "E"});
		lex.lexer.put("4",new String[] {"h", "h", "A", "A"});
		lex.lexer.put("5",new String[] {"S", "S", "S", "S"});
		lex.lexer.put("6",new String[] {"b", "b", "G", "G"});
		lex.lexer.put("7",new String[] {"T", "T", "j", "j"});
		lex.lexer.put("8",new String[] {"X", "X", "X", "X"});
		lex.lexer.put("9",new String[] {"g", "g", "j", "j"});
	while(true){

	    Scanner in = new Scanner(System.in);
	    String s = in.nextLine();
	    if(s.length()<1){
	    	break;
	    }
	    System.out.println();
	    System.out.println(lex.Lextext(s));
	    System.out.println();
	   	}
	   	
	   	
}
}
