import java.util.*;
import java.math.*;
import java.lang.Math;
import java.util.Random;



public class Lab11{

	public static void main(final String[] args) {
       int n = 100000;
       int m = 1000;
      String t1[] = new String[n];
      String t2[] = new String[m];
      String t3[] = new String[m];

      String lancuch  = "ABCDEFGHIJKLMNOPRSTUQVWXYZ"; //26
      Random r = new Random();
      for(int i=0;i<n;++i){
        int k = r.nextInt(15)+5;
        String val = "";
        for(int j=0;j<k;++j){
          val+=lancuch.charAt(r.nextInt(25));
        }
        t1[i]=val;
      }   
    //System.out.println(t1[5]);
      for(int i=0;i<m;++i){
        t2[i] = t1[r.nextInt(n)];
      }
      for(int i=0;i<m;++i){
        int k = r.nextInt(15)+5;
        String val = "";
        for(int j=0;j<k;++j){
          val+=lancuch.charAt(r.nextInt(25));
        }
        t3[i]=val;
      } 


      var array_list = new ArrayList<String>(n);
      var linked_list = new LinkedList<String>();
      var tree_set = new TreeSet<String>();
      var hash_map = new HashMap<String,String>();
System.out.println("\n");
//ARRAY LIST
      long startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        array_list.add(t1[i]);
      }
      double elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przepisanie do ArrayList (w ms): "+elapsedNanos);

//LINKED LIST
      startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        linked_list.add(t1[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przepisanie do LinkedList (w ms): "+elapsedNanos);

//TREE SET
      startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        tree_set.add(t1[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przepisanie do TreeSet (w ms): "+elapsedNanos);

//HASH MAP
      startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        hash_map.put(t1[i],t1[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przepisanie do HashMap (w ms): "+elapsedNanos);

System.out.println("\n\n");
//ArrayList
    startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        array_list.indexOf(t2[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t2 w ArrayList (w ms): "+elapsedNanos);

//LinkedList
    startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        linked_list.indexOf(t2[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t2 w LinkedList (w ms): "+elapsedNanos);

//TreeSet
      startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        tree_set.contains(t2[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t2 w TreeSet (w ms): "+elapsedNanos);


 //HashMap
      startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        hash_map.get(t2[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t2 w HashMap (w ms): "+elapsedNanos);

System.out.println("\n\n");
//ArrayList
    startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        array_list.indexOf(t3[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t3 w ArrayList (w ms): "+elapsedNanos);

//LinkedList
    startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        linked_list.indexOf(t3[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t3 w LinkedList (w ms): "+elapsedNanos);

//TreeSet
      startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        tree_set.contains(t3[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t3 w TreeSet (w ms): "+elapsedNanos);


 //HashMap
      startTime = System.nanoTime();
      for(int i=0;i<m;++i){
        hash_map.get(t3[i]);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Wyszukiwanie t3 w HashMap (w ms): "+elapsedNanos);

System.out.println("\n\n");

//Przejscie po indeksach

      startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        array_list.get(i);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po ArrayList petla for (w ms): "+elapsedNanos);

      startTime = System.nanoTime();
      for(String c : array_list){
        
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po ArrayList petla for-each (w ms): "+elapsedNanos);

      startTime = System.nanoTime();
      Iterator<String> it = array_list.iterator();
      while(it.hasNext()){it.next();};
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po ArrayList iteratorem (w ms): "+elapsedNanos);

      System.out.println("\n");

      startTime = System.nanoTime();
      for(int i=0;i<n;++i){
        linked_list.get(i);
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po LinkedList petla for (w ms): "+elapsedNanos);

      startTime = System.nanoTime();
      for(String c : linked_list){
        
      }
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po LinkedList petla for-each (w ms): "+elapsedNanos);

      startTime = System.nanoTime();
      it = linked_list.iterator();
      while(it.hasNext()){it.next();};
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Przejscie po LinkedList iteratorem (w ms): "+elapsedNanos);

//CLEAR 
      System.out.println("\n");
//ArrayList
    startTime = System.nanoTime();
     
        array_list.clear();
      
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Usuniecie ArrayList (w ms): "+elapsedNanos);

//LinkedList
    startTime = System.nanoTime();
     
        linked_list.clear();
      
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Usuniecie LinkedList (w ms): "+elapsedNanos);

//TreeSet
      startTime = System.nanoTime();
      
        tree_set.clear();
      
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Usuniecie TreeSet (w ms): "+elapsedNanos);


 //HashMap
      startTime = System.nanoTime();
  
        hash_map.clear();
    
      elapsedNanos = (System.nanoTime() - startTime)/1000000.0;
      System.out.println("Usuniecie HashMap (w ms): "+elapsedNanos);


  }
}