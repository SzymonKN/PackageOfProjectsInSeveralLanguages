import java.util.*;
import java.math.*;
import java.lang.Math;
import java.lang.reflect.*;

public class Lab09{

	public static void main(final String[] args) {
       

       try{
        String splitted[] = splitArgs(args[0]);
        try{
            
            Class<?> c = Math.class;

            if(splitted.length==2){

              Method m = c.getMethod(splitted[0],double.class);
              double x = Double.valueOf(splitted[1]);
              System.out.println( m.invoke(null,x));
            }
            else if(splitted.length==3){
             
               Method m = c.getMethod(splitted[0],double.class,double.class);
               double x = Double.valueOf(splitted[1]);
                double y = Double.valueOf(splitted[2]);
                 System.out.println( m.invoke(null,x,y));;
            }
            else{
              throw new ToManyArgs();
            }

          }
          catch(NumberFormatException ex){
              System.out.println("Argumenty funkcji musza byc liczbami!");
            }
          catch(NoSuchMethodException ex){
            System.out.println("Nie ma takiej metody!");
          }
          catch(ToManyArgs e){
            System.out.println("Zla liczba argumentow funkcji! Podaj jedna lub dwie liczby.");
          }
          catch(Exception ex){
            System.out.println(ex);
          }
      }
       catch(Exception e){
        System.out.println("Nie podano nic do obliczenia!");
       }
       
       
  }

    public static String[] splitArgs(String arg) {
        return Arrays.stream(arg.split("[\\s+(),]")).filter(w -> w.isEmpty() == false).toArray(String[]::new);
    }

   


}
 class ToManyArgs extends Exception{
  
  }
