import java.io.*;
import java.util.*;
class Lexer{
	private String text;
	public Lexer(String text)
	{
		this.text=text.toLowerCase();
	}

	public String Lextext(){
		StringBuilder sb=new StringBuilder();
		String newtext;
		for(char c:text.toCharArray()){
			switch(c){
				case 'a':sb.append("4");
				break;
				case 'b':sb.append("ß");
				break;
				case 'c':sb.append("€");
				break;
				case 'd':sb.append("|)");
				break;
				case 'e':sb.append("3");
				break;
				case 'f':sb.append("£");
				break;
				case 'h':sb.append("♓");
				break;
				case 'i':sb.append("1");
				break;
				case 'j':sb.append("⌡");
				break;
				case 'k':sb.append("|<");
				break;
				case 'l':sb.append("|_");
				break;
				case 'm':sb.append("(V)");
				break;
				case 'o':sb.append("0");
				break;
				case 'r':sb.append("®");
				break;
				case 's':sb.append("$");
				break;
				case 't':sb.append("†");
				break;
				case 'u':sb.append("µ");
				break;
				case 'w':sb.append("\\/\\/");
				break;
				case 'x':sb.append(")(");
				break;
				case 'y':sb.append("¥");
				break;
				case '0':sb.append("☺");
				break;
				case '3':sb.append("E");
				break;
				case '5':sb.append("S");
				break;
				default: sb.append(c);
			}
		}
		newtext=sb.toString();
		return newtext;
		
	}
	
	
}


class Program{
public static void main(String[] args) {
	while(true){
	    Scanner in = new Scanner(System.in);
	    String s = in.nextLine();
	    if(s.length()<1){
	    	break;
	    }
	    System.out.println();
	    Lexer lex=new Lexer(s);
	    System.out.println(lex.Lextext());
	    System.out.println();
	   	}
}
}
