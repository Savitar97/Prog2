

import java.io.IOException;




public class LZWBinFa implements Comparable<LZWBinFa> {

    public LZWBinFa() {
        gyoker = new Csomopont();
        fa = gyoker;
    }
    public void push_back(char ch) {
        if (ch == '0') {
            if (fa.getBalNulla() == null) {
                Csomopont uj = new Csomopont('0');
                fa.setNullasGyermek(uj);
                fa = gyoker;
            }
            else{
                fa = fa.getBalNulla();
            }
        }
        else if (ch == '1') {
            if (fa.getJobbEgy() == null) {
                Csomopont uj = new Csomopont('1');
                fa.setEgyesGyermek(uj);
                fa = gyoker;
            } else {
                fa = fa.getJobbEgy();
            }
        }
    }
    public int compareTo(LZWBinFa fa) {
        if (this.melyseg< fa.melyseg) {
            return -1;
        } 
        else if (this.melyseg > fa.melyseg){
            return 1;
        }
        else if (this.melyseg==fa.melyseg)
        {
            if (this.atlag< fa.atlag) {
                return -1;
            }
            else if (this.atlag > fa.atlag) {
                return 1;
            }
             return 0;
        }
        else{
            return 0;
        }
        
    }
    public double getAtlag() {
        melyseg = atlagosszeg = atlagdb = 0;
        ratlag(gyoker);
        atlag = (double) atlagosszeg / atlagdb;
        return atlag;
    }
    public int getMelyseg() {
        melyseg = maxMelyseg = 0;
        rmelyseg(gyoker);
        return maxMelyseg - 1;
    }
    public double getSzoras() {
        atlag = getAtlag();
        szorasosszeg = 0.0;
        melyseg = atlagdb = 0;
        rszoras(gyoker);
        if (atlagdb - 1 > 0) {
            szoras = Math.sqrt(szorasosszeg / (atlagdb - 1));
        } else {
            szoras = Math.sqrt(szorasosszeg);
        }
        return szoras;
    }
    public void kiir() {
        melyseg = 0;
        kiir(gyoker);
    }
    
    private class Csomopont {
       
        public Csomopont() {
            betu = '/';
            jobbEgy = null;
            balNulla = null;
        }
        public Csomopont(char ch) {
            betu = ch;
            jobbEgy = null;
            balNulla = null;
        }
        
        public void setNullasGyermek(Csomopont nulla) {
            balNulla = nulla;
        }
        public void setEgyesGyermek(Csomopont egy) {
            jobbEgy = egy;
        }
        public void setBetu(char ch) {
            betu = ch;
        }
       
        public char getBetu() {
            return betu;
        }
        public Csomopont getJobbEgy() {
            return jobbEgy;
        }
        public Csomopont getBalNulla() {
            return balNulla;
        }
        
        private char betu;
        private Csomopont jobbEgy;
        private Csomopont balNulla;
    }

    private Csomopont fa;
    private int melyseg, atlagosszeg, atlagdb;
    private double szorasosszeg;

    private void kiir(Csomopont elem) {
        if (elem != null) {
            melyseg++;
            kiir(elem.getJobbEgy());
            for (int i = 0; i < melyseg; i++) {
                System.out.print("---");
            }
            System.out.print(elem.getBetu() + "(" + (melyseg - 1) + ")" + "\n");
            kiir(elem.getBalNulla());
            melyseg--;
        }
    }

    protected Csomopont gyoker;
    protected int maxMelyseg;
    protected double atlag, szoras;
    protected void rmelyseg(Csomopont elem) {
        if (elem != null) {
            melyseg++;
            if (melyseg > maxMelyseg) {
                maxMelyseg = melyseg;
            }
            rmelyseg(elem.getBalNulla());
            rmelyseg(elem.getJobbEgy());
            melyseg--;
        }
    }
    protected void ratlag(Csomopont elem) {
        if (elem != null) {
            melyseg++;
            ratlag(elem.getBalNulla());
            ratlag(elem.getJobbEgy());
            melyseg--;
            if (elem.getJobbEgy() == null && elem.getBalNulla() == null) {
                atlagdb++;
                atlagosszeg += melyseg;
            }
        }
    }
    protected void rszoras(Csomopont elem) {
        if (elem != null) {
            melyseg++;
            rszoras(elem.getJobbEgy());
            rszoras(elem.getBalNulla());
            melyseg--;
            if (elem.getJobbEgy() == null && elem.getBalNulla() == null) {
                atlagdb++;
                szorasosszeg += (melyseg - atlag) * (melyseg - atlag);
            }
        }
    }
    public static void main(String[] args) throws IOException {
     LZWBinFa binfa = new LZWBinFa();
    LZWBinFa binfa1 = new LZWBinFa();
    LZWBinFa binfa2 = new LZWBinFa();
    String str = "011110010110010101010101"; 
    for(int i = 0; i < str.length(); i++){
            binfa.push_back(str.charAt(i));
        } 
    System.out.println("Binfa");
    binfa.kiir(binfa.gyoker);
    System.out.println("Átlag:"+binfa.getAtlag());
    System.out.println("Mélység:"+binfa.getMelyseg());
    str = "011110011111"; 
    for(int i = 0; i < str.length(); i++){
            binfa1.push_back(str.charAt(i));
        } 
    System.out.println("Binfa1");
    binfa1.kiir(binfa1.gyoker);
    System.out.println("Átlag:"+binfa1.getAtlag());
    System.out.println("Mélység:"+binfa1.getMelyseg());
    str = "011110010001100101"; 
    for(int i = 0; i < str.length(); i++){
            binfa2.push_back(str.charAt(i));
        } 
    System.out.println("Binfa2");
    binfa2.kiir(binfa2.gyoker);
    System.out.println("Átlag:"+binfa2.getAtlag());
    System.out.println("Mélység:"+binfa2.getMelyseg());
    LZWBinFa binfak[]=new LZWBinFa[3];
    binfak[0]=binfa;
    binfak[1]=binfa1;
    binfak[2]=binfa2;
    System.out.println();
    java.util.List<LZWBinFa> rendezettbinfak= java.util.Arrays.asList(binfak);
    java.util.Collections.sort(rendezettbinfak);
    for(LZWBinFa elem : rendezettbinfak) {
            System.out.println(elem.getMelyseg()+":"+elem.getAtlag());
        }



    }
}
