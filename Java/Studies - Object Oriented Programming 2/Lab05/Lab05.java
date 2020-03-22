import java.util.*;
import java.math.*;

public class Lab05{
	public static void main(String[] args) {
        Man[] staff = new Man[6];
        staff[0] = new Student("Jan", "Kowalski", 211152, 3.5, 4.0, 5.0);
        staff[1] = new Student("Marek", "Styczen", 211150, 4.5, 3.5, 5.0);
        staff[2] = new Graduate("inz.", "Franciszek", "Nowak", 223123, 2018, 5.0, 4.5, 4.0);
        staff[3] = new Graduate("mgr inz.", "Lukasz", "Maj", 200122, 2012, 5.0, 4.5, 3.0);
        staff[4] = new Dean("prof.", "Wojciech", "Luzny", 2008, 2012);
        staff[5] = new Dean("prof.", "Janusz", "Wolny", 2012, 2020);
        
        printStaff(staff);

        System.out.println();
        System.out.println(staff[0].compare(staff[1]));
        System.out.println(staff[1].compare(staff[0]));
        System.out.println(staff[1].compare(staff[2]));
        System.out.println(staff[1].compare(staff[4]));

        System.out.println();
        System.out.println(staff[4].compare(staff[5]));
        System.out.println(staff[5].compare(staff[4]));
        System.out.println(staff[5].compare(staff[0]));
    }

    public static void printStaff(Man[] tab) {
        for (Man c : tab)
            if (c != null) {
                System.out.println(c.getClass().getName() + ": " + c);
                System.out.println("  Average = " + c.average());
                System.out.println();
            } else
                break;
    }
}

abstract class Man {
    private final String name;
    private final String surname;

    // DOPISAC: Konstruktor
    
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



class Student extends Man{
	double oceny[]=new double[3];
	int index;

	Student(String imie,String nazwisko,int id,double x1,double x2,double x3){
		super(imie,nazwisko);
		oceny[0]=x1;
		oceny[1]=x2;
		oceny[2]=x3;
		index = id;
	}
	public String toString(){
	
	return super.toString()+", id number: "+index+", grades: ["+oceny[0]+", "+oceny[1]+", "+oceny[2]+"]";
	}
	public double average(){
		double av=0;
		for(Double x:oceny){
			av+=x;
		}
		av=av/3;
		return av;
	}
	public Man compare(Man obj){
		if(obj instanceof Student){
		if(this.average()>obj.average())
			return this;
		else
			return obj;
		}
		return null;
	}
}
class Graduate extends Student{
	String tytul;
	int data;

	Graduate(String title,String imie,String nazwisko,int id,int year,double x1,double x2,double x3){
		super(imie,nazwisko,id,x1,x2,x3);
		
		
		tytul=title;
		data=year;
	}
	public double average(){
		double av=0;
		for(Double x:super.oceny){
			av+=x;
		}
		av=av/3;
		return av;
	}
	public String toString(){
	return tytul+" "+super.toString()+", year of graduation: "+data;
	}
}
class Dean extends Man{
	int start,end;
	String tytul;

	Dean(String title,String imie,String nazwisko,int yearOfHired,int yearOfFired){
		super(imie,nazwisko);
		tytul=title;
		start=yearOfHired;
		end=yearOfFired;
	}
	public String toString(){
		return tytul+" "+super.toString()+", Dean of Faculty from "+start+" to "+end+".";
	}
	public Man compare(Man obj){
		if(obj instanceof Dean){
		if(this.end>((Dean)obj).end)
			return this;
		return obj;
	}
	return null;
	}
	public double average(){
		System.out.print("  [Average not applicable]");
		return 0.0;
	}
}