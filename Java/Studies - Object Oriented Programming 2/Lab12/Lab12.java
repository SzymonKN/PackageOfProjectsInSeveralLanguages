import java.util.*;
import java.math.*;
import java.lang.Math;
import java.util.Scanner;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.*;

public class Lab12{

	public static void main(final String[] args) {
    String plik1="";
    String plik2="";
    int counter=0;

    BufferedReader pliki = new BufferedReader(new InputStreamReader(System.in));
    String plik;

    System.out.println("Podaj nazwy dwoch plikow:");

      try{
        while((plik=pliki.readLine())!=null){
          counter++;
          if(counter==2){
            plik2=plik;
            break;
          }
          else
            plik1=plik;
        }
        pliki.close();
      }
      catch(IOException e){
        System.err.println("Blad wczytywania z konsoli!");
      }
       Charset charset = Charset.forName("UTF-8");
      Path path_p1 = Paths.get(plik1);
      int len=0;
      try(BufferedReader reader = Files.newBufferedReader(path_p1,charset)){
      String line =null;
        while((line=reader.readLine())!=null){
         len++;
        }
        reader.close();
      }
      catch(IOException e){
       System.err.println("Blad Otwartcia Pliku: "+plik1+" !");
      }
      //pliki.close();




  var x = getArgs(plik1,len);

  var plik_1 = getFile(plik1);
  var plik_2 = getFile(plik2);
  
  var plik_3 = new HashMap<String,Double>();
  for(int i=0;i<x.length;++i){
    if(plik_1.containsKey(x[i])&&plik_2.containsKey(x[i])){
      double val = Double.valueOf(plik_1.get(x[i]))+Double.valueOf(plik_2.get(x[i]));
      plik_3.put(x[i],val);
      System.out.println(val);
    }
  }

  System.out.println("\nPodaj nazwe pliku wyjsciowego!");
  Scanner sc = new Scanner(System.in); // klasa z pakietu java.util
  String file = sc.nextLine();
  sc.close();
  Path pat = Paths.get(file);
  try{
  BufferedWriter plik_koncowy = Files.newBufferedWriter(pat);
  for(int i=0;i<len;++i){
    if(plik_3.containsKey(x[i]))
      plik_koncowy.write(x[i]+" "+plik_3.get(x[i]));
  }
  }
  catch(IOException e){
       System.err.println("Blad Zapisania Pliku: "+file+" !");
      }

  }




  static HashMap<String,Double> getFile(String file_name){
    var plik_1 = new HashMap<String,Double>();
    Path path_p1 = Paths.get(file_name);
    
    Charset charset = Charset.forName("UTF-8");

    try(BufferedReader reader = Files.newBufferedReader(path_p1,charset)){
      String line =null;
      while((line=reader.readLine())!=null){
        String[] splittedLine = line.split("\\s+");
         plik_1.put(splittedLine[0],Double.valueOf(splittedLine[1]));
      }
      reader.close();
    }
    catch(IOException e){
      System.err.println("Blad Otwartcia Pliku: "+file_name+" !");
    }

    return plik_1;
  }
 
  static String[] getArgs(String file_name,int len){
    String[] args=new String[len];
    Path path_p1 = Paths.get(file_name);
    int l=0;
    Charset charset = Charset.forName("UTF-8");

    try(BufferedReader reader = Files.newBufferedReader(path_p1,charset)){
      String line =null;
      while((line=reader.readLine())!=null){
        String[] splittedLine = line.split("\\s+");
        args[l]=splittedLine[0];
        l++;
      }
      reader.close();
    }
    catch(IOException e){
      System.err.println("Blad Otwartcia Pliku: "+file_name+" !");
    }

    return args;
  }
}