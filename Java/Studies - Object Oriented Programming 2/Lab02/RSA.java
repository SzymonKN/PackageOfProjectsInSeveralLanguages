import java.math.BigInteger;
public class RSA {
    public static void main(String[] args) {
        String s = args[0];
        BigInteger tab[] = new BigInteger[args[0].length()];
        int p = 397;
        int q=103;
        int n = p*q;
       System.out.println(n);
       int fi = (p-1)*(q-1);
       int e=2;
      


System.out.println();

      int a=e;
      while(a!=1){
        a+=1;
        e+=1;
        a = Euclid(fi,a);
      }

       System.out.println(e);
       int d = extendedEuclid(e,fi);
       System.out.println(d);

        BigInteger Big_e = new BigInteger(""+e); 
        BigInteger Big_fi = new BigInteger(""+fi); 
        BigInteger Big_n = new BigInteger(""+n); 
        BigInteger Big_d = new BigInteger(""+d); 

        for(int i=0;i<args[0].length();i++){
            tab[i]=new BigInteger(""+(int)s.charAt(i));
            System.out.print(tab[i]+ " ");
            tab[i]=tab[i].modPow(Big_e,Big_n);
            // System.out.print(tab[i]+ " ");
        }
        System.out.println("");
    

        for(int i=0;i<args[0].length();i++){
            tab[i]=tab[i].modPow(Big_d,Big_n);
            System.out.print(tab[i]+ " ");
        }
        System.out.println("");
        for(int i=0;i<args[0].length();i++){
           
            System.out.print((char)tab[i].intValue());
        }
          System.out.println("");


          int[] coded = {40606, 25802, 11618, 24168, 11618, 39378, 9444, 5109, 16086, 39378, 26980}; 
          BigInteger tab_c[] = new BigInteger[coded.length];
          for(int i=0;i<coded.length;i++){
            tab_c[i]=new BigInteger(""+coded[i]);
          }
           for(int i=0;i<coded.length;i++){
            tab_c[i]=tab_c[i].modPow(Big_d,Big_n);
            System.out.print(tab_c[i]+ " ");
        }
        System.out.println("");
        for(int i=0;i<coded.length;i++){
           
            System.out.print((char)tab_c[i].intValue());
        }
          System.out.println("");

    }



public static int Euclid(int a, int b){

     while(b!=0){
        int temp = a%b;
        a=b;
        b=temp;
       }

    return a;
}

public static int extendedEuclid(int a, int b){
    int x0=1;
    int x=0;
    int b0=b;
    while(b!=0){
        int q = a/b;
        int temp=x;
        x=x0-q*x;
        x0=temp;
        temp=a%b;
        a=b;
        b=temp;
    }
    if(x0<0){
        x0=x0+b0;
    }

    return x0;
}
/*
public static int powMod(int t, int e, int n){
    int y=1;
    for(int k=e.length();k<=0;k--){
        y=y*(y%n);

    }
}

*/


}