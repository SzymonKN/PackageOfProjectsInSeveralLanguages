import java.util.Arrays;
import java.util.*;

public class Lab07{
	 public static void main(String[] args) {
	 	Board Labirynt = new Board(6,4,0.3);
	 	//System.out.println(Labirynt);
	 	
	 //	Direction dir = Direction;
	 //	System.out.println(java.util.Arrays.toString( Direction.values() ));
	 	System.out.println(java.util.Arrays.toString( Option.values() ));
	 	Scanner sc = new Scanner(System.in); // klasa z pakietu java.util
	 	while(true){
	 		Labirynt.printBoard();
	 		
	 		char z;
			//...
			z = sc.next().charAt(0);
			//...
			
			if(z=='q'){
				sc.close();
				break;
			}
			else if(z=='0'){
				Labirynt=new Board(6,4,0.3);
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
				System.out.println("Niepoprawna Opcja!!!");
			}


	 	}



	 }
}

class Board{
	String[][] plansza;
	int nx,ny;
	int position_x=ny-2,position_y=1;
	Board(int nxx,int nyy, double p){
		nx=nxx;
		ny=nyy;
		plansza = new String[ny][nx];
		for(int i=0;i<ny;++i){
			for(int j=0;j<nx;++j){
				plansza[i][j]=" ";
				plansza[0][j]="X";
				plansza[ny-1][j]="X";
				}
				plansza[i][0]="X";
				plansza[i][nx-1]="X";
			}

			plansza[ny-2][1]="o";
			plansza[0][nx-3]=" ";
		}

	
	public String toString(){
		return Arrays.toString(plansza[1]);
	}
	public void printBoard(){
	
		for(int i=0;i<ny;++i){
				
			for(int j=0;j<nx;++j){
				System.out.print(plansza[i][j]);
			}
			System.out.println("");
		}

	}
}
