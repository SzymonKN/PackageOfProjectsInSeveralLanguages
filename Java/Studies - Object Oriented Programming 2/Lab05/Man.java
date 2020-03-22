package Man.java;
abstract class Man {
    private final String name;
    private final String surname;

    // DOPISAC: Konstruktor
    Man(){
    	name="";
    	surname="";
    }
     Man(String imie,String nazwisko){
    	name=imie;
    	surname=nazwisko;
    }
    // DOPISAC: Metody typu get
    public String getName(){
    	return name;
    }
    public String getSurname(){
    	return surname;
    }
    // DOPISAC: toString zwracajacy lancuch z imieniem i nazwiskiem
    public String toString(){
	
	return getName()+" "+getSurname();
}

    abstract public Man compare(Man ob);

    public double average() {
        return 0.0;
    }
}