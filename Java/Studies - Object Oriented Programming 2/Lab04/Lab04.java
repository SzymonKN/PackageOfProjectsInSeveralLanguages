import java.util.*;
import java.math.*;
import java.lang.Integer;
public class Lab04{
    public static void main(String[] args) {

    BigInt liczba1 = new BigInt("94");
    BigInt liczba2  = new BigInt(liczba1);

    System.out.println(liczba1);
    System.out.println(liczba2);
    BigInt liczba3 = liczba1.add(liczba2);
    System.out.println(liczba3);

/*
   for(int i=0;i<1000;i++){
		BigInt l1 = new BigInt(""+rand.nextLong());
		BigInt l2 = new BigInt(""+rand.nextLong());
		BigInt l3 = l1.add(l2);
		System.out.println(l1+" + " +l2+" = "+l3);
	}
	*/
    }

}
final class BigInt{
	private int N;
	private byte [] tab; 
	
BigInt(String s){
	N = s.length();
	
	tab = new byte[N+1];
	for(int i=1;i<=N;++i){
		tab[i] = Byte.parseByte(""+s.charAt(i-1));
	
	}
}
BigInt(byte [] tab_copy){
	tab = new byte[tab_copy.length];
	for(int i=0;i<tab.length;i++){
		tab[i] = tab_copy[i];
	}

}
BigInt(BigInt obj){
	tab = new byte[obj.tab.length];
	for(int i=0;i<tab.length;i++){
		tab[i] = obj.tab[i];
	}
}



public String toString(){
	String str = new String("");
	for(int i=0;i<tab.length;i++){
		str+=(""+tab[i]);
	}
	return str;
}

public boolean equals(Object obj){

	if(this == null || obj == null)
		return false;
	if(this==obj)
		return true;
	if(obj.getClass()==getClass()){
		return (this.tab).equals(((BigInt)obj).getNum());
		
	}
	else 
		return false;

	
}
public byte [] getNum(){
	byte [] copy = new byte[tab.length];
	for(int i=0;i<tab.length;i++){
		copy[i] = tab[i];
	}	

	return copy;
}
public BigInt add(BigInt obj){
	BigInteger object1= new BigInteger(obj.toString());
	BigInteger object2= new BigInteger(this.toString());
	BigInteger object3= object1.add(object2);
	return new BigInt(object3.toString());
}





}