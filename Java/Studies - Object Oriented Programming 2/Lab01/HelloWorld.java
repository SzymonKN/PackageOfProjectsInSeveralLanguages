public class HelloWorld {
    public static void main(String[] args) {

        System.out.println("Hello " + "world!");

        Examples ob = new Examples();
        //ob.run();
        //ob.stringsV2();
        Examples newob = new Examples();
        System.out.println(ob == newob);
        System.out.println("" + ob.equals(newob));
    }

}

class Examples {
    float x1;

    public double run() {
      //   System.out.println(2 + 4); // ex. 1
      //   System.out.println("2 + 4 = " + (2 + 4)); // ex. 1

     //    float x2; // ex. 2
      //   x2=4.5f;
       //  System.out.println("x1 = " + x1); // ex. 2
        // System.out.println("x2 = " + x2); // ex. 2

        return Math.sqrt(36.0);
       //  System.out.println("sqrt(36.0) calculated."); // ex. 3
    }

    
     public void stringsV1(){ // ex. 4
         String s1 = new String("Hello");
         String s2 = new String("Hello");
         System.out.print(s1 == s2);
         System.out.println(" " + s1.equals(s2));
     }

     public void stringsV2(){ // ex. 5
         String s1 = "Hello";
         String s2 = "Hello";
         System.out.println(s2 = s2.toUpperCase());
         System.out.print(s1 == s2);
         System.out.println(" " + s1.equals(s2));
     }

}