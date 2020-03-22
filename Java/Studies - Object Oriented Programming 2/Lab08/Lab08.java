import java.util.*;
import java.math.*;
import java.util.Random;
import org.graalvm.compiler.core.common.type.ArithmeticOpTable.Op;


import org.graalvm.compiler.core.common.type.ArithmeticOpTable.Op;

public class Lab08{
	public static void main(final String[] args) {
        boolean czy_int=true;
        int rozmiar=0;

        Scanner sc = new Scanner(System.in); // klasa z pakietu java.util
        while(czy_int){
            try{
            int nx;
            System.out.println("> Podaj liczbe calkowita wieksza od 1:");
            nx = sc.nextInt();
            if(nx<=1){
                throw new toSmall("BLAD: Zbyt mala wartosc nx: "+nx);
            }
            czy_int=false;
            rozmiar=nx;
            }
            catch(toSmall blad){
                System.out.println(blad);
                sc.nextLine();
            }
            catch(Exception err){
                System.out.println("BLAD: Podaj liczbe calkowita!");
                sc.nextLine();
            }
            
        }
        sc.close();
        Board Labirynt = new Board(rozmiar);
        
        sc = new Scanner(System.in); // klasa z pakietu java.util
        czy_int=true;
        while(czy_int){
            Labirynt.printBoard();
            char z;

           z = sc.next().charAt(0);
            try{
           if(z=='q'){
               sc.close();
               break;
           }
           else if(z=='0'){
               Labirynt=new Board(rozmiar);
           }
           else if(z=='l'){

           }
           else if(z=='r'){
               
           }
           else if(z=='d'){

           }
           else if(z=='u'){
               
           }
           else{
               throw new OptionNotRecognized("Nie rozpoznano opcji: "+z);
           }
            }
            catch(OptionNotRecognized err){
                System.out.println(err);
            }

        }
        if(czy_int==false){
            System.out.println("*********************");
            System.out.println("***  Wygrales!!!  ***");
            System.out.println("*********************");
        }

    }   
}
class toSmall extends Exception{
       
    private static final long serialVersionUID = 1L;
    String er;

    toSmall(String text){
        er=text;
    }
    public String toString(){
        return er;
        }
}



class OptionNotRecognized extends Exception{
   
    private static final long serialVersionUID = 1L;
    String text;
    OptionNotRecognized(String lancuch){
        text=lancuch;
    }
	public String toString(){
	return text;
	}
	
}
class WallException extends Exception{
    private static final long serialVersionUID = 1L;
    String text;
    WallException(String lancuch){
        text=lancuch;
    }
	public String toString(){
	return text;
	}
	
}

class Board{
	String[][] plansza;
	int nx;
	int position_x=nx-2,position_y=1;
	Board(int nxx){
		nx=nxx;
		plansza = new String[nx][nx];
		for(int i=0;i<nx;++i){
			for(int j=0;j<nx;++j){
                Random r = new Random();
                if(r.nextDouble()>0.3){
                plansza[i][j]=" ";
                }
                else{
                    plansza[i][j]="X";
                }
				plansza[0][j]="X";
				plansza[nx-1][j]="X";
				}
				plansza[i][0]="X";
				plansza[i][nx-1]="X";
			}
			plansza[nx-2][1]="o";
			plansza[0][nx-3]=" ";
		}

	public String toString(){
		return Arrays.toString(plansza[1]);
	}
	public void printBoard(){
	
		for(int i=0;i<nx;++i){	
			for(int j=0;j<nx;++j){
				System.out.print(plansza[i][j]);
			}
			System.out.println("");
		}

	}
}
