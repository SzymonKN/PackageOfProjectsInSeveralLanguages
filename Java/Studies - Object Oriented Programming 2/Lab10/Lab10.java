import java.util.*;
import java.math.*;
import java.lang.Math;
import java.lang.reflect.Array;
import java.lang.Class;


public class Lab10{

	public static void main(final String[] args) {
       
    
    String splitted[] = splitArgs(args[0]);
    
    ONP(splitted);
  }

    public static String[] splitArgs(String arg) {
        return Arrays.stream(arg.split("")).filter(w -> w.isEmpty() == false).toArray(String[]::new);
    }

   public static void ONP(String splitted[]){
    Stack<String> stos = new Stack<String>(10,String[].class);
    
    boolean t=true;
    int i=0;
    while(i<splitted.length){
       
      
      if(splitted[i].equals("+") || splitted[i].equals("-") || splitted[i].equals("*") || splitted[i].equals("/")){
        
        try{
        String v1 = stos.pop();
        String v2 = stos.pop();
        stos.push("("+v2+splitted[i]+v1+")");
        }
        catch(Exception ex){
          System.out.println("BLAD DANYCH WEJSCIOWYCH! Koniec algorytmu, a stos nie jest pusty:"+stos);
          t=false;
      }

      }
      else{
        try{
        stos.push(splitted[i]);
      }
      catch(Exception ex){
          System.out.println("BLAD DANYCH WEJSCIOWYCH! Na stosie jest za malo elementow, zeby wykonac operacje!");
          t=false;
        }
      }
      i++;
      
      
    }
    
    if(t){
  System.out.println("Wynik: "+stos);
}
  }


}
class Stack<T>{
  //private T[] tab;
  final T[] stack;
  int act_leng;
  final int max_leng;

  Stack(int max, Class<T[]> classT) {
        max_leng = max;
        stack = classT.cast(Array.newInstance(classT.getComponentType(), max));
    }
  public boolean isEmpty(){
    if(act_leng==0){
      return true;
    }
    else{
      return false;
    }
  }
  public boolean isFull(){
    if(act_leng==max_leng){
      return true;
    }
    else{
      return false;
    }
  }
  public void push(T x) throws StackOverflowException{
    if(this.isFull()){
      throw new StackOverflowException("Stos jest PEŁNY!");
    }
    else{
      stack[act_leng]=x;
      act_leng+=1;
      
    }
    
  }
  public T pop() throws StackUnderflowException{
    if(this.isEmpty()){
      throw new StackUnderflowException("Stos jest PUSTY!");
    }
    else{
      act_leng-=1;
      return stack[act_leng];
    }

  }
  public String toString(){
    return String.valueOf(stack[0]);
  }

  
}
class StackOverflowException extends Exception{
  StackOverflowException(String t){
    super(t);
  }
}
class StackUnderflowException extends Exception{
  StackUnderflowException(String t){
    super(t);
  }
}
