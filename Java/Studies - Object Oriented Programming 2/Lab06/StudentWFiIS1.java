public class StudentWFiIS1 extends Student implements StudentUSOS {
    private String[] przedmioty;
    private int rok;

    /* IMPLEMETACJA METOD: */
    StudentWFiIS1(String imie,String nazwisko,int indeks,int year,String przedmiot1,double ocena1,String przedmiot2,double ocena2,String przedmiot3,double ocena3){
    	super(imie,nazwisko,indeks,ocena1,ocena2,ocena3);
    	rok=year;
    	przedmioty = new String[3];
    	przedmioty[0]=przedmiot1;
    	przedmioty[1]=przedmiot2;
    	przedmioty[2]=przedmiot3;
    }
    public double srednia(){
    	return super.average();
    }
    
    public void listaPrzedmiotow(){
    	for(int i=0;i<przedmioty.length;++i){
    	System.out.println("\t"+(i+1)+". "+przedmioty[i]+": "+super.getGrade(i));
    	}
    }
    
    public String toString() {
		return "["+rok+"] "+super.toString();
	}
}
