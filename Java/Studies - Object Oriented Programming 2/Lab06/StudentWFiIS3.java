public class StudentWFiIS3 extends Student {
    private StudentUSOS stud;

    /* IMPLEMETACJA METOD: */
    StudentWFiIS3(String imie,String nazwisko,int indeks,int year,String przedmiot1,double ocena1,String przedmiot2,double ocena2,String przedmiot3,double ocena3){
    	super(imie,nazwisko,indeks,ocena1,ocena2,ocena3);
    	
    	stud=make(year,przedmiot1,przedmiot2,przedmiot3);
    }
   public StudentUSOS make(int year,String... p){

   	return new StudentUSOS(){
   		private int rok= year;
    	private String[] przedmioty = new String[]{p[0],p[1],p[2]};
    	
   		public double srednia(){
   			return average();
   		}
   		public void listaPrzedmiotow(){
   			przedmioty[0]=p[0];
    		przedmioty[1]=p[1];
    		przedmioty[2]=p[2];
   			for(int i=0;i<przedmioty.length;++i){
    			System.out.println("\t"+(i+1)+". "+przedmioty[i]+": "+getGrade(i));
    		}
   		}
   		public String toString(){
   			return "["+rok+"] ";
   		}

   	};

   }
   public double srednia(){
   	return stud.srednia();
   }
   public void listaPrzedmiotow(){
   	stud.listaPrzedmiotow();
   }
   public String toString(){
   	return stud.toString()+super.toString();
   }
}