import java.util.*;
import java.math.*;
import java.lang.Math;


public class Lab13{

	public static void main(final String[] args) {
       int n=Integer.valueOf(args[0]);
       int m = Integer.valueOf(args[1]);
       int p = Integer.valueOf(args[2]);
       Matrix A = new Matrix(n,m);
       Matrix B = new Matrix(m,p);
       Matrix C = new Matrix(A,B);
       Matrix D = new Matrix(A,B,0);
       System.out.println("Macierz A:");
       System.out.println(A);
       System.out.println("Macierz B:");
       System.out.println(B);
       System.out.println("Macierz C = A * B :");
       System.out.println(C);
       System.out.println("Macierz C = A * B :  [Wątkowo]");
       System.out.println(D);
       System.out.println(C.equals(D));
  }

  
}

class Matrix{
  private final int n;
  private final int m;
  private final Double[][] macierz;

  Matrix(int x,int y){
    n=x;
    m=y;
    Random r = new Random();
    macierz = new Double[n][m];
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        macierz[i][j] = r.nextDouble();
      }
    }
  }
  //Konstruktor dla mnożenia zwykłego
  Matrix(Matrix A, Matrix B){
    n = A.getX();
    m = B.getY();
    macierz = new Double[n][m];
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        double sum=0;
        for(int k=0;k<A.getY();++k){
          sum+=A.macierz[i][k]*B.macierz[k][j];
        }
        macierz[i][j]=sum;
      }
    }
  }
  //Konstruktor dla mnozenia watkowego
  Matrix(Matrix A, Matrix B, int flag){
    n = A.getX();
    m = B.getY();
    macierz = new Double[n][m];
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        //implementacja wątku
        mnozenieWatek w = new mnozenieWatek(i,j,A.getY(),A,B,this);
        w.start();
        
        //
      }
    }
  }
  public boolean equals(Object X){
    if(this.getClass()==X.getClass()){
    Matrix por = (Matrix)X;
    if(this.n!=por.n || this.m != por.m)
      return false;

    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        if(this.macierz[i][j]!=por.macierz[i][j]){
          return false;
        }
      }
    }
    return true;
  }
  else
    return false;

  }
  public int getX(){
    return n;
  }
  public int getY(){
    return m;
  }
  public double getMacierz(int i,int j){
    return macierz[i][j];
  }
  public void setMacierz(int i, int j, double val){
    macierz[i][j] = val;
  }
  public String toString(){
    String wyjscie="";
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
        wyjscie +=" "+String.format("%.4f", macierz[i][j]);
      }
      wyjscie +="\n";
    }

    return wyjscie;
  }

}
class mnozenieWatek extends Thread{
  int i_w,j_w,k_max;
  Matrix A_w,B_w,C_w;
  
  mnozenieWatek(int i,int j,int k,Matrix A, Matrix B,Matrix C){
    i_w = i;
    j_w = j;
    k_max = k;
    A_w = A;
    B_w =B;
    C_w = C;
  }
  public void run(){
    try{  
      double v = 0;
      for(int k=0;k<k_max;++k){
          v+=A_w.getMacierz(i_w,k)*B_w.getMacierz(k,j_w);
        }
        C_w.setMacierz(i_w,j_w,v);
      
    }
    catch(Exception e){
      System.out.println("watek przerwany");
    }
  }
}