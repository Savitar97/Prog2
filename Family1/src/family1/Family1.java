/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package family1;

import java.util.Map;

import org.jpl7.JPL;
import org.jpl7.Query;
import org.jpl7.Term;
/**
 *
 * @author nemesis
 */
public class Family1 {

    public static void main(String argv[]) {
		// JPL.setTraditional();
		//
		Query.hasSolution("use_module(library(jpl))"); // only because we call e.g. jpl_pl_syntax/1 below
		Term swi = Query.oneSolution("current_prolog_flag(version_data,Swi)").get("Swi");
		System.out.println("swipl.version = " + swi.arg(1) + "." + swi.arg(2) + "." + swi.arg(3));
		System.out.println("swipl.syntax = " + Query.oneSolution("jpl_pl_syntax(Syntax)").get("Syntax"));
		System.out.println("swipl.home = " + Query.oneSolution("current_prolog_flag(home,Home)").get("Home").name());
		System.out.println("jpl.jar = " + JPL.version_string());
		System.out.println("jpl.dll = " + org.jpl7.fli.Prolog.get_c_lib_version());
		System.out.println("jpl.pl = " + Query.oneSolution("jpl_pl_lib_version(V)").get("V").name());
		//
	String s = "consult('family.pl')";
        Query q = new Query(s);
        System.out.println(s + " " + (Query.hasSolution(s) ? "succeeded" : "failed"));

        String term = "apa(edit)";
        System.out.println(term + " is " + (Query.hasSolution(term) ? "provable" : "not provable"));
        
        String term1 = "nagyapja(X, attila)";
        System.out.println("A formula megoldásai: " + term1);
        Query q1 = new Query(term1);
        while (q1.hasMoreSolutions()) {
            Map<String, Term> str = q1.nextSolution();
            System.out.println("X = " + str.get("X"));
        }        

        String term2 = "nagyapa(X)";
        System.out.println("Az első megoldása a formulának: " + term2 + ": X = " + Query.oneSolution(term2).get("X"));
        
        System.out.println("Tobábbi megoldások: " + term2);
        Query q2 = new Query(term2);
        while (q2.hasMoreSolutions()) {
            Map<String, Term> str1 = q2.nextSolution();
            System.out.println("X = " + str1.get("X"));
        }

        
        
        String term3 = "gyereke(X, elek)";
        System.out.println("Minden megoldás: " + term3);
        Query q3 = new Query(term3);
        while (q3.hasMoreSolutions()) {
            Map<String, Term> str2 = q3.nextSolution();
            System.out.println("X = " + str2.get("X"));
	}
    }
}
